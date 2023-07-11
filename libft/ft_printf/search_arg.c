/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 08:49:24 by jrenault          #+#    #+#             */
/*   Updated: 2022/11/26 14:47:35 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	search_arg(va_list arg, char c)
{
	int	j;

	j = 0;
	if (c == 'c')
		j = ispercent_c(va_arg(arg, int));
	else if (c == 'X')
		j = ispercent_capx(va_arg(arg, int));
	else if (c == 'd' || c == 'i')
		j = ispercent_d_i(va_arg(arg, int));
	else if (c == 'p')
		j = ispercent_p(va_arg(arg, unsigned long));
	else if (c == 's')
		j = ispercent_s(va_arg(arg, char *));
	else if (c == 'u')
		j = ispercent_u(va_arg(arg, unsigned int));
	else if (c == 'x')
		j = ispercent_x(va_arg(arg, unsigned int));
	else if (c == '%')
	{
		write(1, "%", 1);
		j++;
	}
	else
		j = -1;
	return (j);
}
