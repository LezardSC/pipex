/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:20:20 by jrenault          #+#    #+#             */
/*   Updated: 2022/11/24 14:21:02 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	is_zero(unsigned int nb)
{
	if (nb == 0)
		ft_putchar('0');
}

void	ft_putunbr(unsigned int nb)
{	
	long int		divider;
	unsigned int	temp_nb;

	divider = 1;
	temp_nb = 1;
	is_zero(nb);
	while (temp_nb != 0)
	{
		temp_nb = nb / divider;
		divider = divider * 10;
	}
	divider = divider / 100;
	while (divider != 0)
	{
		temp_nb = nb / divider;
		ft_putchar(temp_nb + '0');
		nb = nb - temp_nb * divider;
		divider = divider / 10;
	}
}
