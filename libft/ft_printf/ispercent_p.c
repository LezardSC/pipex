/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ispercent_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 08:51:24 by jrenault          #+#    #+#             */
/*   Updated: 2022/11/26 17:40:21 by jrenault         ###   ########lyon.fr   */
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

static int	ft_putnbr_base_printf_ul(unsigned long int nbr, char *base, int *j)
{
	int				base_size;

	if (check_error(base) == 1)
	{
		base_size = ft_strlen(base);
		if (nbr > 0)
		{
			*j += 1;
			ft_putnbr_base_printf_ul(nbr / base_size, base, j);
			write(1, &base[nbr % base_size], 1);
		}
		return (*j);
	}
	return (0);
}

int	ispercent_p(unsigned long int p)
{
	int	j;

	j = 2;
	write(1, "0x", 2);
	if (p == 0)
	{
		write(1, "0", 1);
		return (j + 1);
	}
	return (ft_putnbr_base_printf_ul(p, "0123456789abcdef", &j));
}
