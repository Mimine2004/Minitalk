/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:04:57 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/08 17:06:00 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_j(char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			j = 0;
		if (s[i] != c && j == 0)
		{
			j = 1;
			k++;
		}
		i++;
	}
	return (k);
}

static char	*ft_strcpy(char const *s, char *dest, int debut, int fin)
{
	int	i;

	i = 0;
	while (debut <= fin)
	{
		dest[i] = s[debut];
		i++;
		debut++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	ft_free(char **tab, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
}

static char	**ft_set_string(char const *s, char c, char **tab, int i)
{
	int		debut;
	int		j;
	char	*dest;

	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		debut = i;
		while (s[i] != c && s[i])
			i++;
		if (j < ft_count_j(s, c))
		{
			dest = (char *)malloc(sizeof(char) * ((i - 1) - debut + 1) + 1);
			if (!dest)
			{
				ft_free(tab, j);
				return (NULL);
			}
			tab[j++] = ft_strcpy(s, dest, debut, (i - 1));
		}
	}
	return (tab[j] = NULL, tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_count_j(s, c) + 1));
	if (!tab)
	{
		free(tab);
		return (NULL);
	}
	tab = ft_set_string(s, c, tab, i);
	return (tab);
}
/* #include <stdio.h>
int     main(void)
{
        char    *strs = "Hello<World>Wide< >Web";
        char    sep = '<';
        int     i = 0;
        char    **str = ft_split(strs,sep);

        while (str[i])
        {
                printf("%s\n",str[i]);
                i++;
        }
        return (0);
} */