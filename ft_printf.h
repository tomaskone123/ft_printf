/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:00:26 by tkonecny          #+#    #+#             */
/*   Updated: 2024/06/13 19:51:25 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>

struct convert
{
	char	*sym;
	int		(*f)(va_list);
};
typedef struct convert convert_t;

typedef struct gvar
{
	int	string;
	int	function;
	int	i;
	int	end_value;
	int	chartotal;
	const char *a;
}variables;

int	ft_printf(const char *, ...);
int	character_count(const char *format, va_list arg, convert_t f_list[]);
int	print_string(va_list arg);
int	print_char(va_list arg);

#endif
