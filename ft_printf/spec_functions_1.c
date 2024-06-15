/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:25:02 by tkonecny          #+#    #+#             */
/*   Updated: 2024/06/15 11:26:23 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

int	print_string(va_list arg)
{
	variables	v;

	v.i = 0;
	v.chartotal = 0;
	v.a = va_arg(arg, const char *);
	while (v.a[v.i])
	{
		ft_putchar_fd(v.a[v.i], 1);
		v.i++;
		v.chartotal++;
	}
	return (v.chartotal);
}

int	print_char(va_list arg)
{
	variables	v;

	v.b = va_arg(arg, int);
	ft_putchar_fd(v.b, 1);
	return (1);
}

int	print_int(va_list arg)
{
	variables	v;

	v.chartotal = 0;
	v.b = va_arg(arg, int);
	ft_putnbr_fd(v.b, 1);
	if (v.b < 0)
	{
		v.b = -v.b;
		v.chartotal++;
	}
	while (v.b > 0)
	{
		v.b = v.b / 10;
		v.chartotal++;
	}
	return (v.chartotal);
}

int	print_unsigned(va_list arg)
{
	variables	v;

	v.chartotal = 0;
	v.uni = va_arg(arg, unsigned int);
	v.uni = (unsigned int)((int)v.uni);
	ft_putunbr_fd(v.uni, 1);
	while (v.uni > 0)
	{
		v.uni = v.uni / 10;
		v.chartotal++;
	}
	return (v.chartotal);
}
