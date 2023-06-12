/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ispercent_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 08:51:38 by jrenault          #+#    #+#             */
/*   Updated: 2022/11/25 14:22:42 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ispercent_d_i(int nb)
{
	ft_putnbr(nb);
	return (ft_count_long(nb));
}
