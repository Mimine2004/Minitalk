/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:52:56 by marvin            #+#    #+#             */
/*   Updated: 2024/11/10 19:52:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/* #include <stdio.h>
#include <string.h>
void f_content(unsigned int a, char *b)
{
	(void)a;
	if (*b >= 'a' && *b <= 'z')
    {
        *b -= 32;
    }
}
int main(void)
{
	char str[] = "Bonjour2 la mIFf";
    printf("avant et apres (*f) %s :", str);
	ft_striteri(str, f_content);
	printf("%s",str);
    return(0);
} */