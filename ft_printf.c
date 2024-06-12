/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:59:33 by tkonecny          #+#    #+#             */
/*   Updated: 2024/06/12 17:13:30 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	int	i;

	i = 0;
	while (format[i])
	{
		write(1, &format[i], 1);
		i++;
	}
	return (i);
}
int main(void)
{
	char *s = "Hello world";

	ft_printf("");
}
