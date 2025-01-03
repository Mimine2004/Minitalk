/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:37:18 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/06 10:38:59 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}
/* #include <ctype.h>
#include <stdio.h>
int main(void)
{
	printf("+: %d\n",ft_isalpha('a'));
	printf("+: %d\n",isalpha('a'));
	printf("0: %d\n",ft_isalpha('1'));
	printf("0: %d\n",isalpha('1'));
    return(0);
} */