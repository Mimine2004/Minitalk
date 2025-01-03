/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:27:50 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/06 13:55:53 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
		{
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		}
		i++;
	}
	return (0);
}
/* #include <string.h>
#include <stdio.h>
int main(void)
{
	const char str1a[] = "voilka maintenant il y a 5 $";
	const char str2a[] = "voilka maintenant il y a 5 $";
	const char str1b[] = "voila maintenant il y a 5 $";
	const char str2b[] = "voila maintenant il y a 5 $";
	int res1 = memcmp(str1a,str1b,18);
	int res2 = ft_memcmp(str2a,str2b,18);
	printf("%d\n",res2);
	printf("%d\n", res1);
	return(0);
} */