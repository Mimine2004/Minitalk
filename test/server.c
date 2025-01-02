#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

volatile sig_atomic_t received_bit = 0;

void signal_handler(int sig, siginfo_t *info, void *context) {
    (void)context;
    static int bits_received = 0;
    static unsigned char current_char = 0;
    static char *message = NULL;
    static size_t length = 0;

    if (!message) {
        length = 1024;
        message = malloc(length);
        if (!message) {
            perror("Erreur d'allocation mémoire");
            exit(1);
        }
    }

    if (sig == SIGUSR1)
        received_bit = 0;
    else if (sig == SIGUSR2)
        received_bit = 1;

    current_char = (current_char << 1) | received_bit;
    bits_received++;

    if (bits_received == 8) {
        message[strlen(message)] = current_char;
        if (current_char == '\0') {
            printf("%s\n", message);
            free(message);
            message = NULL;
        }
        bits_received = 0;
        current_char = 0;
    }
    if (info && info->si_pid)
        kill(info->si_pid, SIGUSR1);
}

int main(void) {
    printf("PID du serveur : %d\n", getpid());

    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = signal_handler;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction SIGUSR1");
        return 1;
    }
    if (sigaction(SIGUSR2, &sa, NULL) == -1) {
        perror("sigaction SIGUSR2");
        return 1;
    }
    while (1)
        pause();

    return 0;
}