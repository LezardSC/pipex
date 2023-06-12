/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:15:01 by jrenault          #+#    #+#             */
/*   Updated: 2022/12/13 14:19:30 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	is_backslash_n(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
	{
		return (0);
	}
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (BUFFER_SIZE);
}

static char	*get_line(char *buffer, char *line)
{
	int	i;

	i = is_backslash_n(buffer);
	line = ft_strnjoin_gnl(buffer, line, i + 1);
	buffer = ft_memmove_gnl(buffer, buffer + i + 1, BUFFER_SIZE - i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			nbyte;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	if (buffer[0] != '\0')
	{
		if (is_backslash_n(buffer) != BUFFER_SIZE)
			return (get_line(buffer, line));
		line = ft_strnjoin_gnl(buffer, line, BUFFER_SIZE);
	}
	nbyte = read(fd, buffer, BUFFER_SIZE);
	if (nbyte < 0)
		return (ft_memset_gnl(buffer, 0, BUFFER_SIZE), free(line), NULL);
	while (nbyte)
	{
		buffer[nbyte] = '\0';
		if (is_backslash_n(buffer) != BUFFER_SIZE)
			return (get_line(buffer, line));
		line = ft_strnjoin_gnl(buffer, line, BUFFER_SIZE);
		nbyte = read(fd, buffer, BUFFER_SIZE);
	}
	return (ft_memset_gnl(buffer, 0, BUFFER_SIZE), line);
}
