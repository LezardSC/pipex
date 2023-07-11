/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:14:41 by jrenault          #+#    #+#             */
/*   Updated: 2022/12/03 13:44:19 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_shrink_printf(int *i, int *j, int *adjust)
{
	if (*j == -1)
	{
		*i += 1;
		*adjust += 1;
	}
	else
	{
		*i += 2;
		*adjust += 2;
	}
}

int	ft_printf(const char *format, ...)
{
	int				i;
	int				j;
	int				adjust;
	va_list			arg;

	va_start(arg, format);
	i = 0;
	j = 0;
	adjust = 0;
	if (write(1, 0, 0) != 0)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (i + j - adjust);
			j += search_arg(arg, format[i + 1]);
			ft_shrink_printf(&i, &j, &adjust);
		}
		else
			ft_putchar_fd(format[i++], 1);
	}
	va_end(arg);
	return (i + j - adjust);
}
