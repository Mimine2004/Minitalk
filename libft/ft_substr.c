/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:20:51 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/07 15:51:17 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (start >= ft_strlen(s) || !s)
	{
		str = malloc(sizeof(char) * 1);
		if (!str || !s)
			return (NULL);
		str[j] = '\0';
		return (str);
	}
	else if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (i != start)
		i++;
	while (j < len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
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
	printf("%s\n", ft_substr("Bonjour mon bro je t'aime ;)",0,15));
	printf("%s\n", ft_substr("Bonjour mon bro je t'aime ;)",16,12));
    return(0);
}  */