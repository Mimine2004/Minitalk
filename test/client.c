#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

volatile sig_atomic_t acknowledgement = 0;

void ack_handler(int sig) {
    (void)sig; // pour éviter des avertissements du compilateur
    acknowledgement = 1;
}

int send_message(pid_t server_pid, const char *message) {
    for (size_t i = 0; i <= strlen(message); i++) {
        unsigned char c = message[i];
        for (int bit = 0; bit < 8; bit++) {
            if (c & (1 << (7 - bit))) {
                if (kill(server_pid, SIGUSR2) == -1) {
                    perror("Erreur lors de l'envoi du signal SIGUSR2");
                    return -1;
                }
            } else {
                if (kill(server_pid, SIGUSR1) == -1) {
                    perror("Erreur lors de l'envoi du signal SIGUSR1");
                    return -1;
                }
            }
            while (!acknowledgement)
                pause();
            acknowledgement = 0;
        }
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server PID> <message>\n", argv[0]);
        return 1;
    }

    pid_t server_pid = atoi(argv[1]);
    struct sigaction act;
    act.sa_handler = ack_handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

    if (sigaction(SIGUSR1, &act, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    return send_message(server_pid, argv[2]);
}