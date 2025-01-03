/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:14:51 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/07 10:00:03 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if ((!dest && !src) || (!dest && !src && !n))
		return (NULL);
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			*(unsigned char *)(dest + i) = *(const char *)(src + i);
			i++;
		}
	}
	else
	{
		i = n;
		while (i-- > 0)
		{
			*(unsigned char *)(dest + i) = *(const char *)(src + i);
		}
	}
	return (dest);
}
/* #include <string.h>
#include <stdio.h>
int main(void)
{
	char str1a[50];
	char str1b[50];
	char str2a[50];
	char str2b[50];
	
	strcpy(str1a,"voila maintenant il y a 5 $");
	strcpy(str2a,"voila maintenant il y a 5 $");
	strcpy(str1b,"$$$$$");
	strcpy(str2b,"$$$$$");
	ft_memmove(str1a,str1b,50);
	printf("%s\n",str1a);
	memmove(str2a,str2b,50);
	printf("%s\n",str2a);
	return(0);
} */