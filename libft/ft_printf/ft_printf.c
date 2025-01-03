/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:36:37 by hhecquet          #+#    #+#             */
/*   Updated: 2025/01/03 13:23:45 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(va_list args, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.flag == '%')
		count += ft_putchar('%');
	else if (flags.flag == 'c')
		count += ft_putchar_c(va_arg(args, int), flags);
	else if (flags.flag == 's')
		count += ft_putstring(va_arg(args, char *), flags);
	else if (flags.flag == 'x' || flags.flag == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), flags);
	else if (flags.flag == 'p')
		count += ft_print_hex(va_arg(args, unsigned long long), flags);
	else if (flags.flag == 'd' || flags.flag == 'i')
		count += ft_putnbr(va_arg(args, int), flags);
	else if (flags.flag == 'u')
		count += ft_putnbr(va_arg(args, unsigned int), flags);
	else
		return (0);
	return (count);
}

int	parseformatsize(const char *str, int i, t_flags *flags)
{
	while (ft_isdigit(str[i]))
	{
		flags->formatsize = (flags->formatsize * 10) + (str[i] - '0');
		i++;
	}
	return (i);
}

int	parserflag(const char *format, int i, t_flags *flags)
{
	while (format[i++])
	{
		if (!ft_isdigit(format[i]) && !ft_strchr("-. +#c%sxXuipd", format[i]))
			break ;
		if (format[i] == '+')
			flags->plus = 1;
		if (format[i] == '#')
			flags->hash = 1;
		if (format[i] == '-')
			flags->minus = 1;
		if (format[i] == '0' && flags->minus == 0 && flags->point == 0)
			flags->zero = 1;
		if (ft_isdigit(format[i]) && !flags->point)
			i = parseformatsize(format, i, flags);
		if (format[i] == ' ')
			flags->space = 1;
		if (format[i] == '.')
			i = parseprecision(format, i + 1, flags);
		if (ft_strchr("csx%Xuipd", format[i]))
		{
			flags->flag = format[i];
			break ;
		}
	}
	return (i);
}

t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.precision = 0;
	flags.formatsize = 0;
	flags.minus = 0;
	flags.plus = 0;
	flags.zero = 0;
	flags.pourcent = 0;
	flags.space = 0;
	flags.hash = 0;
	flags.point = 0;
	return (flags);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
	t_flags	flags;

	i = 0;
	count = 0;
	flags = ft_init_flags();
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i = parserflag(format, i, &flags);
			count += ft_print_format(args, flags);
			flags = ft_init_flags();
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
/*
⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⢻⣿⡗⢶⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣄
⠀⢻⣇⠀⠈⠙⠳⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⠶⠛⠋⣹⣿⡿
⠀⠀⠹⣆⠀⠀⠀⠀⠙⢷⣄⣀⣀⣀⣤⣤⣤⣄⣀⣴⠞⠋⠉⠀⠀⠀⢀⣿⡟⠁
⠀⠀⠀⠙⢷⡀⠀⠀⠀⠀⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⠋⠀⠀
⠀⠀⠀⠀⠈⠻⡶⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣠⡾⠋⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣼⠃⠀⢠⠒⣆⠀⠀⠀⠀⠀⠀⢠⢲⣄⠀⠀⠀⢻⣆⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢰⡏⠀⠀⠈⠛⠋⠀⢀⣀⡀⠀⠀⠘⠛⠃⠀⠀⠀⠈⣿⡀⠀⠀⠀⠀
⠀⠀⠀⠀⣾⡟⠛⢳⠀⠀⠀⠀⠀⣉⣀⠀⠀⠀⠀⣰⢛⠙⣶⠀⢹⣇⠀⠀⠀⠀
⠀⠀⠀⠀⢿⡗⠛⠋⠀⠀⠀⠀⣾⠋⠀⢱⠀⠀⠀⠘⠲⠗⠋⠀⠈⣿⠀⠀⠀⠀
⠀⠀⠀⠀⠘⢷⡀⠀⠀⠀⠀⠀⠈⠓⠒⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡇⠀⠀⠀
⠀⠀⠀⠀⠀⠈⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣧⠀⠀⠀
⠀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠁⠀⠀⠀
*/
/* #include "ft_printf.h"
#include <stdio.h>

int main(void) {
    // Testing basic functionality
    ft_printf("Hello, World!\n");
    ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", "42 Network");
    ft_printf("Pointer: %p\n", &main);
    ft_printf("Decimal: %d\n", 12345);
    ft_printf("Unsigned: %u\n", 4294967295);
    ft_printf("Hex lowercase: %x\n", 255);
    ft_printf("Hex uppercase: %X\n", 255);
    ft_printf("Percent: %%\n");

    // Testing bonus features
    ft_printf("Width: %10d\n", 42);
    ft_printf("Precision: %.5d\n", 42);
    ft_printf("Zero-padding: %05d\n", 42);
    ft_printf("Left-align: %-10dDone\n", 42);
    ft_printf("Space flag: % d\n", 42);
    ft_printf("Plus flag: %+d\n", 42);
    ft_printf("Hash flag: %#x\n", 255);

    return 0;
} */
