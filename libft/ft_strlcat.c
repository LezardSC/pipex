/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:56:04 by jrenault          #+#    #+#             */
/*   Updated: 2022/11/16 17:37:16 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	size_dest;
	size_t	size_src;
	int		i;
	int		j;

	if (!dest && !size)
		return (0);
	size_dest = ft_strlen(dest);
	size_src = ft_strlen(src);
	i = -1;
	if (size < size_dest)
		return (size + size_src);
	while (dest[++i] && size > 0)
	{
		size--;
	}
	j = -1;
	while (src[++j] && size > 1)
	{
		dest[i + j] = src[j];
		size--;
	}
	if (size > 0)
		dest[i + j] = '\0';
	return (size_dest + size_src);
}
