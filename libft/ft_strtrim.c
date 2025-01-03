/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:31:11 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/08 17:06:26 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char const s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_countwords(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (ft_inset(s1[i], set) == 1 && s1[i])
	{
		i++;
		j++;
	}
	if (j == ft_strlen(s1))
		return (j);
	i = ft_strlen(s1) - 1;
	while (ft_inset(s1[i], set) == 1 && s1[i])
	{
		i--;
		j++;
	}
	return (j);
}

static char	*ft_trimwords(char const *s1, char const *set, char	*str)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(s1) - 1;
	j = 0;
	k = 0;
	while (ft_inset(s1[i], set) == 1 && s1[i])
	{
		i--;
	}
	k = i;
	i = 0;
	while (ft_inset(s1[i], set) == 1 && s1[i])
	{
		i++;
	}
	while (i <= k && s1[i])
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	j;
	char	*str;

	j = ft_countwords(s1, set);
	str = malloc(sizeof(char) * ((ft_strlen(s1) - j) + 1));
	if (!str)
		return (NULL);
	str = ft_trimwords(s1, set, str);
	return (str);
}
/* #include <stdio.h>
#include <string.h>
#include <unistd.h>
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
	const char *s1 = "  \t \t \n   \n\n\n\t";
 	const char *s2 = "";
 	char *ret = ft_strtrim(s1, " \n\t");
 
 	if (!strcmp(ret, s2))
 		write(1,"yes it work",12);
 	else
		write(1,"no...",5);
	return (0);
} */
