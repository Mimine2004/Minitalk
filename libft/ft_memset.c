/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:53:06 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/06 11:51:46 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = s;
	while (n != 0)
	{
		*str = c;
		str++;
		n--;
	}
	return ((void *)s);
}
/* #include <string.h>
#include <stdio.h>
int main(void)
{
	char str1[50];
	char str2[50];
	
	strcpy(str1,"voila maintenant il y a 5 $");
	strcpy(str2,"voila maintenant il y a 5 $");
	ft_memset(str1,'$',5);
	printf("%s\n",str1);
	memset(str2,'$',5);
	printf("%s\n",str2);
	return(0);
} */