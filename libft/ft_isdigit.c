/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:43:33 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/08 15:08:05 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
/* #include <ctype.h>
#include <stdio.h>
int main(void)
{
	printf("0: %d\n",ft_isdigit('a'));
	printf("0: %d\n",isdigit('a'));
	printf("+: %d\n",ft_isdigit('1'));
	printf("+: %d\n",isdigit('1'));
        return(0);
} */