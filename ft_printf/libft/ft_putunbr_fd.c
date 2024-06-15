/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:42:03 by tkonecny          #+#    #+#             */
/*   Updated: 2024/06/14 16:45:15 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putunbr_fd(unsigned int n, int fd)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
	{
		write(fd, "o", 1);
		i = 1;
	}
	else
	{
		if (n >= 10)
		{
			ft_putunbr_fd(n / 10, fd);
			ft_putchar_fd(n % 10 + '0', fd);
			i++;
		}
		else
		{
			ft_putchar_fd(n + '0', fd);
			i++;
		}
	}
	return (i);
}
