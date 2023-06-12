/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:15:16 by jrenault          #+#    #+#             */
/*   Updated: 2022/12/14 08:42:15 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strnjoin_gnl(char *buf, char *line, size_t len)
{
	size_t	i;
	size_t	j;
	char	*newline;

	i = 0;
	j = 0;
	if (!buf)
		return (NULL);
	newline = malloc((ft_strlen_gnl(buf) + ft_strlen_gnl(line) + 1)
			* sizeof(char));
	if (!newline)
		return (free(line), NULL);
	while (line && line[i])
	{
		newline[i] = line[i];
		i++;
	}
	while (buf[j] && j < len)
		newline[i++] = buf[j++];
	newline[i] = '\0';
	if (line)
		free(line);
	return (newline);
}

void	*ft_memset_gnl(void *mem, int newValue, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = mem;
	while (i < n && str[i])
	{
		str[i] = (char)newValue;
		i++;
	}
	mem = str;
	return (mem);
}

void	*ft_memmove_gnl(void *dest, const void *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < size)
	{
		if (dest > src)
		{
			((char *)dest)[size - 1] = ((char *)src)[size - 1];
			size--;
		}
		else
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}
