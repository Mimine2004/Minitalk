/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_basictools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:50:56 by hhecquet          #+#    #+#             */
/*   Updated: 2025/01/03 14:17:19 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *format)
{
	int	count;

	count = 0;
	if (!format)
		return (ft_putstr("(null)"));
	while (format[count])
		ft_putchar(format[count++]);
	return (count);
}

int	handle_sign(long nb, t_flags flags)
{
	if (flags.plus == 1 && nb >= 0)
		return (1);
	if (nb < 0)
		return (1);
	return (0);
}
