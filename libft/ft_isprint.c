/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:58:44 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/06 10:54:00 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
	{
		return (1);
	}
	return (0);
}
/* #include <ctype.h>
#include <stdio.h>
int main(void)
{
	printf("0: %d\n",ft_isprint(''));
	printf("0: %d\n",isprint(''));
	printf("+: %d\n",ft_isprint('a'));
	printf("+: %d\n",isprint('a'));
    return(0);
} */
