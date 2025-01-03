/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:09:19 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/08 17:05:17 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	tot;
	void	*ran;

	tot = size * nmemb;
	ran = malloc(tot);
	if (!ran)
		return (NULL);
	ft_bzero(ran, tot);
	return (ran);
}
/* #include <string.h>
#include <stdio.h>
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
int main(void)
{
	char *str1 = ft_calloc(5,1);
	char *str2 = calloc(5,1);
	memset(str1,'b',23);
	memset(str2,'b',23);
	printf("%s\n",str1);
	printf("%s\n",str2);
	return(0);
} */