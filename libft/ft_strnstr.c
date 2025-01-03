/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:39:21 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/07 10:25:37 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(little) > len && big && little && len)
		return (NULL);
	while (big[i] && j != ft_strlen(little) && i < len && (i + j) < len)
	{
		if (big[i + j] == little[j])
		{
			j++;
		}
		else
		{
			j = 0;
			i++;
		}
	}
	if (j == ft_strlen(little))
	{
		return ((char *)(big + i));
	}
	return (NULL);
}
/* #include <bsd/string.h>
#include <stdio.h>
#include <string.h>
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
	printf("%s = ", ft_strnstr("Bonjour mon bro je t'aime ;)","je",16));
    printf("%s\n",strnstr("Bonjour mon bro je t'aime ;)","je",16));
	printf("%s = ", ft_strnstr("Bonjour mon bro je t'aime ;)","je",20));
    printf("%s\n",strnstr("Bonjour mon bro je t'aime ;)","je",20));
    return(0);
} */
//cc -Wall -Wextra -Werror -lbsd -g ft_strnstr.c && ./a.out