/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:56:26 by jrenault          #+#    #+#             */
/*   Updated: 2022/11/25 12:43:33 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*shrink_itoa(int i, long int *big_n, int n, int *sign)
{
	char	*numstring;

	*big_n = n;
	*sign = 0;
	numstring = (char *)malloc(sizeof(char) * (i + 1));
	return (numstring);
}

char	*ft_itoa(int n)
{
	long int			big_n;
	int					i;
	int					sign;
	char				*numstring;

	i = (ft_count_long(n));
	numstring = shrink_itoa(i, &big_n, n, &sign);
	if (!numstring)
		return (NULL);
	if (big_n == 0)
		return (numstring[0] = '0', numstring[1] = '\0', numstring);
	numstring[i] = '\0';
	if (big_n < 0)
	{
		big_n *= -1;
		sign++;
	}
	while (i-- > 0)
	{
		numstring[i] = (big_n % 10) + '0';
		big_n = big_n / 10;
	}
	if (sign > 0)
		numstring[0] = '-';
	return (numstring);
}
