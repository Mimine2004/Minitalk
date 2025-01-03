/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:56:58 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/07 09:31:16 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
/* #include <stdio.h>
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
	printf("%s = ", ft_strrchr("Bonjour mon bro je t'aime ;)",'p'));
    printf("%s\n",strrchr("Bonjour mon bro je t'aime ;)",'p'));
	printf("%s = ", ft_strrchr("Bonjour mon bro je t'aime ;)",'o'));
    printf("%s\n",strrchr("Bonjour mon bro je t'aime ;)",'o'));
    return(0);
} */