/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:09:24 by jrenault          #+#    #+#             */
/*   Updated: 2022/11/12 11:48:03 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *mem, int newValue, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)mem)[i] = (char)newValue;
		i++;
	}
	return (mem);
}
