/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:59:33 by tkonecny          #+#    #+#             */
/*   Updated: 2024/06/16 19:19:40 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	t_variables	v;
	va_list		arg;
	t_convert	f_list[9];

	f_list[0] = (t_convert){"c", print_char};
	f_list[1] = (t_convert){"s", print_string};
	f_list[2] = (t_convert){"d", print_int};
	f_list[3] = (t_convert){"i", print_int};
	f_list[4] = (t_convert){"u", print_unsigned};
	f_list[5] = (t_convert){"p", print_pointer};
	f_list[6] = (t_convert){"x", print_low_hex};
	f_list[7] = (t_convert){"X", print_upp_hex};
	f_list[8] = (t_convert){NULL, NULL};
	v.i = 0;
	if (format == NULL)
		return (-1);
	va_start(arg, format);
	v.i = character_count(format, arg, f_list);
	va_end(arg);
	return (v.i);
}
