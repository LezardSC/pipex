/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ispercent_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:18:46 by jrenault          #+#    #+#             */
/*   Updated: 2022/11/26 17:21:10 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_error(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base [i] == '-')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_putnbr_base_printf(unsigned int nbr, char *base, int *j)
{
	unsigned long	lnbr;
	int				base_size;

	lnbr = nbr;
	if (check_error(base) == 1)
	{
		base_size = ft_strlen(base);
		if (lnbr > 0)
		{
			*j += 1;
			ft_putnbr_base_printf(lnbr / base_size, base, j);
			write(1, &base[lnbr % base_size], 1);
		}
		return (*j);
	}
	return (0);
}

int	ispercent_x(unsigned int x)
{
	int	j;

	j = 0;
	if (x == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (ft_putnbr_base_printf(x, "0123456789abcdef", &j));
}
