/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:06:20 by jrenault          #+#    #+#             */
/*   Updated: 2022/11/17 09:43:23 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	size_t	i;

	i = 0;
	if (size <= 0)
		return (0);
	while (i < size)
	{
		if (((char *)memoryBlock)[i] == ((char)searchedChar))
			return (&((char *)memoryBlock)[i]);
		i++;
	}
	return (0);
}
