/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:08:38 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/07 10:44:14 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c <= 'z' && c >= 'a')
	{
		return (c - 32);
	}
	return (c);
}
/* #include <stdio.h>
#include <ctype.h>
int main(void)
{
	printf("%d = ",ft_toupper('b'));
	printf("%d",toupper('b'));
    return(0);
} */