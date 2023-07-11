/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:58:08 by jrenault          #+#    #+#             */
/*   Updated: 2022/11/18 08:23:22 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory_zone;

	if (size > 0 && count > SIZE_MAX / size)
		return (0);
	memory_zone = malloc(count * size);
	if (!memory_zone)
		return (NULL);
	ft_bzero(memory_zone, (count * size));
	return (memory_zone);
}
