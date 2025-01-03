/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:48:56 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/07 11:19:22 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
	{
		free(str);
		return (NULL);
	}
	while (i != ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	while (i != (ft_strlen(s1) + ft_strlen(s2)))
	{
		str[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/* #include <string.h>
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
	char	des1[500] = "Bonjour ";
	char    des2[500] = "Bonjour ";
	char    des3[500] = "Bonjour ";
	char    des4[500] = "Bonjour ";

	printf("%s\n",ft_strjoin(des1,"la miff"));
    printf("%s\n",strcat(des2,"la miff"));
	printf("%s\n",ft_strjoin(des3,"\nla miff"));
	printf("%s\n",strcat(des4,"\nla miff"));
	return(0);
} */