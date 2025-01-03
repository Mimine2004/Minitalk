/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:01:46 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/07 09:36:45 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n && (*(unsigned char *)(s1 + i) || *(unsigned char *)(s2 + i)))
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
		{
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		}
		i++;
	}
	return (0);
}
/* #include <stdio.h>
#include <string.h>
int main(void)
{
    printf("%d = ",ft_strncmp("ABC", "ABCDE",5));
    printf("%d\n",strncmp("ABC", "ABCDE",5));
    printf("%d = ",ft_strncmp("ABCDE", "ABC",5));
    printf("%d\n",strncmp("ABCDE", "ABC",5));
    printf("%d = ",ft_strncmp("ABC", "ABC",5));
    printf("%d\n",strncmp("ABC", "ABC",5));
    return(0);
} */