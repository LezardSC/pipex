/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:15:25 by jrenault          #+#    #+#             */
/*   Updated: 2022/12/13 14:19:45 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(const char *str);
char	*ft_strnjoin_gnl(char *buf, char *line, size_t len);
void	*ft_memset_gnl(void *mem, int newValue, size_t n);
void	*ft_memmove_gnl(void *dest, const void *src, size_t size);

#endif