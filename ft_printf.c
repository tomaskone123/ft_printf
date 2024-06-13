/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:59:33 by tkonecny          #+#    #+#             */
/*   Updated: 2024/06/13 19:24:40 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	int	i;

	convert_t	f_list[] = {
		{"c", print_string},
		{"s", print_char},		// TODO
		{"%", print_char},		// TODO
		// {"p", print_pointer},		// TODO
		// {"d", print_dec},			// TODO
		// {"i", print_int},			// TODO
		// {"u", print_unsigned},		// TODO
		// {"x", print_low_hexa},		// TODO
		// {"X", print_upp_hexa},		// TODO
		{NULL, NULL}
	};
	va_list	arg;
	if (format == NULL)
		return (-1);
	va_start(arg, format);
	i = character_count(format, arg, f_list); // TODO
	va_end(arg);
	return (i);
}
int main(void)
{
	// char *s = "6789";

	// printf("%d\n", ft_printf("%d",NULL));
	ft_printf("%s%s               hi", "Hello", "World");
	// printf("%d\n", printf("%d",));
}
