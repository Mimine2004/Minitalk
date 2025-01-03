/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:54:49 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/06 10:00:51 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	j;
	int	res;

	res = 0;
	i = 0;
	j = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
	{
		i++;
	}
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
		{
			j *= -1;
		}
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * j);
}
/* #include <stdlib.h>
#include <stdio.h>
int    main(void)
{
	printf("%d\n", ft_atoi("  \t\n+261120"));
	printf("%d\n", atoi("  \t\n+261120"));
	printf("%d\n", ft_atoi("a261120"));
    printf("%d\n", atoi("a261120"));
	printf("%d\n", ft_atoi("  \t\n -2611a20"));
    printf("%d\n", atoi("  \t\n -2611a20"));
    return (0);
} */