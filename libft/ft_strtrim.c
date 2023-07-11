/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:20:09 by jrenault          #+#    #+#             */
/*   Updated: 2022/11/10 09:20:09 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char *set)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (set[i])
	{
		if (c == set[i])
			n++;
		i++;
	}
	return (n);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		size;
	char	*isnul;

	i = 0;
	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	while (is_set(((char *)s1)[i], (char *)set) > 0)
		i++;
	if (i == size)
	{
		isnul = malloc(1);
		if (isnul == NULL)
			return (NULL);
		isnul[0] = '\0';
		return (isnul);
	}
	while (is_set(((char *)s1)[size - 1], (char *)set) > 0)
		size--;
	return (ft_substr(s1, i, size - i));
}
