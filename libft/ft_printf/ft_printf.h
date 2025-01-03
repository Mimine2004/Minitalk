/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:00:37 by hhecquet          #+#    #+#             */
/*   Updated: 2025/01/03 13:58:05 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft.h"

/********************************************/
/*   __ _                  _       _    __  */
/*  / _| |                (_)     | |  / _| */
/* | |_| |_     _ __  _ __ _ _ __ | |_| |_  */
/* |  _| __|   | '_ \| '__| | '_ \| __|  _| */
/* | | | |_    | |_) | |  | | | | | |_| |   */
/* |_|  \__|   | .__/|_|  |_|_| |_|\__|_|   */
/*       ______| |                          */
/*      |______|_|                          */
/********************************************/
typedef struct s_flags
{
	int	formatsize;
	int	minus;
	int	plus;
	int	zero;
	int	pourcent;
	int	space;
	int	hash;
	int	point;
	int	flag;
	int	precision;
}	t_flags;
int		handle_null_str(t_flags flags, int *count);
int		ft_print_format(va_list args, t_flags flags);
int		parseformatsize(const char *str, int i, t_flags *flags);
int		parserflag(const char *str, int i, t_flags *flags);
t_flags	ft_init_flags(void);
int		ft_printf(const char *format, ...);
/****************************************************/
/*  _               _      _              _       _ */
/* | |             (_)    | |            | |     | |*/
/* | |__   __ _ ___ _  ___| |_ ___   ___ | |___  | |*/
/* | '_ \ / _` / __| |/ __| __/ _ \ / _ \| / __| | |*/
/* | |_) | (_| \__ \ | (__| || (_) | (_) | \__ \ |_|*/
/* |_.__/ \__,_|___/_|\___|\__\___/ \___/|_|___/ (_)*/
/*                                                  */
/****************************************************/
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		handle_sign(long nb, t_flags flags);
char	*ft_strchr(const char *s, int c);
int		ft_isdigit(int c);
/************************************************/
/*                 _ _              _       _ _ */
/*                | | |            | |     | | |*/
/*  _ __ ___  __ _| | |_ ___   ___ | |___  | | |*/
/* | '__/ _ \/ _` | | __/ _ \ / _ \| / __| | | |*/
/* | | |  __/ (_| | | || (_) | (_) | \__ \ |_|_|*/
/* |_|  \___|\__,_|_|\__\___/ \___/|_|___/ (_|_)*/
/*                                              */
/************************************************/
size_t	ft_strlen(const char *s);
int		checkspace(t_flags flags);
void	compareformatprecision(long long n, int sign, int zero, t_flags *flags);
int		ft_intlen(long long n, int sign, int base, int zero);
int		parseprecision(const char *format, int i, t_flags *flags);
/*******************************************/
/*             _    __ _             _ _ _ */
/*            | |  / _| |           | | | |*/
/* _ __  _   _| |_| |_| | __ _  __ _| | | |*/
/*| '_ \| | | | __| __| |/ _` |/ _` | | | |*/
/*| |_) | |_| | |_| | | | (_| | (_| |_|_|_|*/
/*| .__/ \__,_|\__|_| |_|\__,_|\__, (_|_|_)*/
/*| |                           __/ |      */
/*|_|                          |___/       */
/*******************************************/
int		ft_putchar_c(char c, t_flags flags);
void	ft_putprecision(long nb, int *count, t_flags *flags);
int		ft_putnbr(long nb, t_flags flags);
int		putformat(int len, t_flags flags);
int		ft_putstr_len(char *str, int len);
/*******************************/
/*  _                  _ _ _ _ */
/* | |                | | | | |*/
/* | |__   _____  __  | | | | |*/
/* | '_ \ / _ \ \/ /  | | | | |*/
/* | | | |  __/>  <   |_|_|_|_|*/
/* |_| |_|\___/_/\_\  (_|_|_|_)*/
/*                             */
/*******************************/
int		ft_ptrlen(unsigned long long n, int base);
void	ft_putahex(unsigned long long nb, int *len, char *base, t_flags *flags);
int		ft_putahash(unsigned long long n, t_flags flags);
int		ft_print_hex(unsigned long long n, t_flags flags);
int		ft_putstring(char *str, t_flags flags);

#endif
/***************************************************/
/*  _   _                 _                        */
/* | | | |               | |                       */
/* | |_| |__   __ _ _ __ | | __  _   _  ___  _   _ */
/* | __| '_ \ / _` | '_ \| |/ / | | | |/ _ \| | | |*/
/* | |_| | | | (_| | | | |   <  | |_| | (_) | |_| |*/
/*  \__|_| |_|\__,_|_| |_|_|\_\  \__, |\___/ \__,_|*/
/*                                __/ |            */
/*                               |___/             */
/***************************************************/