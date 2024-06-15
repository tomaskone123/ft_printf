/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:59:33 by tkonecny          #+#    #+#             */
/*   Updated: 2024/06/15 13:04:10 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	variables	v;
	va_list		arg;
	convert_t	f_list[] = {{"c", print_char},
							{"s", print_string},
							{"d", print_int},
							{"i", print_int},
							{"u", print_unsigned},
							// {"p", print_pointer},		// TODO
							{"x", print_low_hex},
							{"X", print_upp_hex},		// TODO
							{NULL, NULL}};

	v.i = 0;
	if (format == NULL)
		return (-1);
	va_start(arg, format);
	v.i = character_count(format, arg, f_list); // TODO
	va_end(arg);
	return (v.i);
}
// int main(void)
// {
// 	// char *s = "6789";

// 	// printf("%d\n", ft_printf("%d",NULL));
// 	// ft_printf("\n%u\n",1234);
// 	// printf("%d\n", printf("%d",));
// }
