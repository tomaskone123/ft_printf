/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:25:02 by tkonecny          #+#    #+#             */
/*   Updated: 2024/06/13 19:52:49 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

// struct	variables
// {
// 	int			chartotal;
// 	int			i;
// 	const char	*a;
// };
// typedef	struct variables var;

int	print_string(va_list arg)
{
	variables	v;

	v.a = va_arg(arg, const char *);
	while (v.a[v.i])
	{
		ft_putchar_fd(v.a[v.i], 1);
		v.i++;
		v.chartotal++;
	}
	return (v.chartotal);
}

int	print_char(va_list arg);
