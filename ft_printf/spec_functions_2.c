/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:36:55 by tkonecny          #+#    #+#             */
/*   Updated: 2024/06/15 13:03:42 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

int	print_low_hex(va_list arg)
{
	variables	v;

	v.result = ft_strdup("");
	v.string = 0;
	v.remainder = 0;
	v.hex = ft_strdup("");
	v.a = "0123456789abcdef";
	v.i = va_arg(arg, int);
	v.uni = (unsigned int)v.i;
	if (v.uni == 0)
	{
		ft_putchar_fd('0', 1);
		v.chartotal = 1;
		return (v.chartotal);
	}
	while (v.uni > 0)
	{
		v.remainder = v.uni % 16;
		v.hex[v.string++] = v.a[v.remainder];
		v.uni /= 16;
	}
	v.hex[v.string] = '\0';
	v.result = reverse_string(v.hex, v.string);
	v.string = 0;
	while (v.result[v.string])
	{
		ft_putchar_fd(v.result[v.string], 1);
		v.string++;
	}
	return (v.string);
}

int	print_upp_hex(va_list arg)
{
	variables	v;

	v.result = ft_strdup("");
	v.string = 0;
	v.remainder = 0;
	v.hex = ft_strdup("");
	v.a = "0123456789ABCDEF";
	v.i = va_arg(arg, int);
	v.uni = (unsigned int)v.i;
	if (v.uni == 0)
	{
		ft_putchar_fd('0', 1);
		v.chartotal = 1;
		return (v.chartotal);
	}
	while (v.uni > 0)
	{
		v.remainder = v.uni % 16;
		v.hex[v.string++] = v.a[v.remainder];
		v.uni /= 16;
	}
	v.hex[v.string] = '\0';
	v.result = reverse_string(v.hex, v.string);
	v.string = 0;
	while (v.result[v.string])
	{
		ft_putchar_fd(v.result[v.string], 1);
		v.string++;
	}
	return (v.string);
}
