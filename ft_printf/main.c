/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:40:22 by tkonecny          #+#    #+#             */
/*   Updated: 2024/06/15 11:24:18 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	character_count(const char *format, va_list arg, convert_t f_list[])
{
	variables	v;

	v.function = 0;
	v.string = 0;
	v.end_value = 0;
	v.i = 0;
	/* Iteratest thru the format string */
	while (format[v.string])
	{
		// printf("%d string\n", v.string);
		/* checks for the % character */
		if (format[v.string] == '%')
		{
			// printf("%d string \n", v.string);
			/* Iterates thru the function list untill it finds the right function */
			while (f_list[v.function].sym)
			{
				// printf("%d fnction\n", v.function);
				/* checks for the conversion character */
				if (format[v.string + 1] == f_list[v.function].sym[0])
				{
					// printf("%d|%d function and string\n", v.string, v.function);
					/* save to value from called function to end_value */
					v.end_value = f_list[v.function].f(arg);
					v.i += v.end_value;
					break ;
				}
				v.function++;
				// printf("%d function", v.function);
			}
			/* if the type descriptor is not valid just print the character */
			if (f_list[v.function].sym == NULL)
			{
				// ft_putchar_fd(format[v.string], 1);
				ft_putchar_fd(format[v.string + 1], 1);
				v.i++;
			}
			v.string++;
		}
		/* if not % just print the character */
		else
		{
			ft_putchar_fd(format[v.string], 1);
			v.i++;
		}
		v.string++;
		v.function = 0;
	}
	// printf("%d\n\n\n", v.i);
	return (v.i);
}
