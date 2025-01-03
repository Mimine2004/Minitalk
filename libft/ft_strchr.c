/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:45:05 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/07 09:30:56 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
/* #include <stdio.h>
#include <string.h>
int main(void)
{
	printf("%s\n", ft_strchr("Bonjour mon bro je t'aime ;)",'p'));
    printf("%s\n",strchr("Bonjour mon bro je t'aime ;)",'p'));
	printf("%s\n", ft_strchr("Bonjour mon bro je t'aime ;)",'j'));
    printf("%s\n",strchr("Bonjour mon bro je t'aime ;)",'j'));
    return(0);
} */