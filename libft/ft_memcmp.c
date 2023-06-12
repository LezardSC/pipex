/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:17:50 by jrenault          #+#    #+#             */
/*   Updated: 2022/11/16 15:06:09 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (0);
	while (((unsigned char *)pointer1)[i] ==
		((unsigned char *)pointer2)[i] && i < size - 1)
		i++;
	return (((unsigned char *)pointer1)[i] - ((unsigned char *)pointer2)[i]);
}
