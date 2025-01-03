/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:01:59 by marvin            #+#    #+#             */
/*   Updated: 2024/11/10 19:01:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	i = 0;
	str = ft_strdup(s);
	if (!str)
	{
		return (NULL);
	}
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
/* #include <stdio.h>
#include <string.h>
char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s) +1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
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
char f_content(unsigned int a, char b)
{
	(void)a;
	if (b >= 'a' && b <= 'z')
    {
        b -= 32;
    }
	return(b);
}
int main(void)
{
	char str[] = "Bonjour2 la mIFf";
    printf("avant et apres (*f) %s :", str);
	printf("%s",ft_strmapi(str, f_content));
    return(0);
} */