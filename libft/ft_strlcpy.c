/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:00:55 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/07 11:17:27 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;

	i = ft_strlen(src);
	if (size == 0)
		return (i);
	while (*(unsigned char *)src != '\0' && size > 1)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		dst++;
		src++;
		size--;
	}
	*(unsigned char *)dst = '\0';
	return (i);
}
/* #include <bsd/string.h>
#include <stdio.h>
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
int main(void)
{
	char	dst[] = "1546546464664";
	char	src[] = "12345678";
	char	dst2[] = "1546546464664";
	char	src2[] = "12345678";
	printf("%zu; ",ft_strlcpy(dst,src,75));
	printf("%s\n",dst);
	printf("%zu; ",strlcpy(dst2,src2,75));
	printf("%s\n",dst2);
	return(0);
} */
//cc -Wall -Wextra -Werror -g -lbsd ft_strlcpy.c && ./a.out
