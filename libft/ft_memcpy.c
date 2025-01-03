/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:05:52 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/07 09:37:04 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str1;
	const char		*str2;

	str1 = dest;
	str2 = src;
	if (!dest && !src)
		return (NULL);
	while (n != 0)
	{
		*str1 = *str2;
		str1++;
		str2++;
		n--;
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
	strcpy(str1b,"$$$$$$$$$$$$");
	strcpy(str2b,"$$$$$$$$$$$$");
	ft_memcpy(str1a,str1b,5);
	printf("%s\n",str1a);
	memcpy(str2a,str2b,5);
	printf("%s\n",str2a);
	return(0);
} */