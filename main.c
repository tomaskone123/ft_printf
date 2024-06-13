/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:40:22 by tkonecny          #+#    #+#             */
/*   Updated: 2024/06/13 19:27:33 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

// typedef struct gvar
// {
// 	int	string;
// 	int	function;
// 	int	i;
// 	int	end_value;
// }variables;

int	character_count(const char *format, va_list arg, convert_t f_list[])
{
	variables v = {0, 0, 0, 0};

	while (format[v.string]) // Iteratest thru the format string
	{
		if (format[v.string] == '%') // checks for the % character
		{
			v.function = 0;
			while (f_list[v.function].sym) // Iterates thru the function list untill it finds the right function
			{
				if (format[v.string + 1] == f_list[v.function].sym[0]) // checks for the conversion character
				{
					v.end_value = f_list[v.function].f(arg); // save to value from called function to end_value
					v.i += v.end_value;				// string s, string b,
					break;
				}
				v.function++;
			}	/* checks if the type descriptor is not valid */
			if (f_list[v.function].sym == NULL)
			{
				// ft_putchar_fd(format[v.string], 1);
				ft_putchar_fd(format[v.string + 1], 1);
				v.i += 2;
			}
			// else
			// 	return (-1);
			v.string++;
		}
		else // if not % print just print the character
		{
			ft_putchar_fd(format[v.string], 1);
			v.i++;
		}
		v.string++;
	}
	// printf("%d\n\n\n", v.i);
	return (v.i);
}
