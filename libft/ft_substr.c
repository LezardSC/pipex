/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:54:11 by jrenault          #+#    #+#             */
/*   Updated: 2022/11/16 08:37:50 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*newstring;

	i = -1;
	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if ((size_t)start > ft_strlen(s))
	{
		newstring = malloc(1);
		if (newstring == NULL)
			return (NULL);
		newstring[0] = '\0';
		return (newstring);
	}
	newstring = (char *)malloc(sizeof(char) * (len + 1));
	if (!newstring)
		return (NULL);
	while (s[start + ++i] && i < len)
		newstring[i] = s[start + i];
	newstring[i] = '\0';
	return (newstring);
}
