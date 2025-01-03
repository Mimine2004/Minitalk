/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:13:38 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/07 10:04:55 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	size_t				i;

	str = s;
	i = 0;
	while (i < n)
	{
		if (*str == (unsigned char)c)
			return ((void *)(s + i));
		i++;
		str++;
	}
	return (NULL);
}
/* #include <string.h>
#include <stdio.h>
int main(void)
{
	const char str1[] = "voila maintenant il y a 5 $";
	const char str2[] = "voila maintenant il y a 5 $";
	const char *res1 = memchr(str2,'y',18);
	const char *res2 = ft_memchr(str1,'y',18);
	printf("%s\n",res2);
	printf("%s\n", res1);
	return(0);
} */