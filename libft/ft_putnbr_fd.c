/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:02:04 by jrenault          #+#    #+#             */
/*   Updated: 2022/11/15 08:43:29 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_is_negative(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
}

static void	ft_is_zero(int n, int fd)
{
	if (n == 0)
		ft_putchar_fd(48, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	divider;
	int			temp_n;

	divider = 1;
	temp_n = 1;
	ft_is_zero(n, fd);
	ft_is_negative(n, fd);
	if (n < 0)
		divider *= -1;
	while (temp_n != 0)
	{
		temp_n = n / divider;
		divider = divider * 10;
	}
	divider = divider / 100;
	while (divider != 0)
	{
		temp_n = n / divider;
		ft_putchar_fd(temp_n + 48, fd);
		n = n - temp_n * divider;
		divider = divider / 10;
	}
}
