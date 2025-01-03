/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:00:58 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/06 13:11:48 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = s;
	while (n != 0)
	{
		*str = 0;
		str++;
		n--;
	}
}
/* #include <string.h>
#include <stdio.h>
int main(void)
{
	char str1[] = "111111111111";
	char str2[] = "111111111111";
	
	ft_bzero(str1, 3);
	printf("%s\n", str1);
	bzero(str2, 3);
	printf("%s\n", str2);
	return(0);
} */