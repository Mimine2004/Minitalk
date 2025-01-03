/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:03:51 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/06 10:29:42 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	j;

	j = 0;
	while (s[j])
	{
		j++;
	}
	return (j);
}
/* #include <string.h>
#include <stdio.h>
int main(void)
{
	printf("%zu\n",ft_strlen("Bonjour 42 :-)"));
        printf("%lu",strlen("Bonjour 42 :-)"));
	return(0);
} */