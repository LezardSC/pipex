/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:38:47 by jrenault          #+#    #+#             */
/*   Updated: 2022/11/10 08:38:47 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*concatenation;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	concatenation = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!concatenation)
		return (NULL);
	while (s1[i])
	{
		concatenation[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		concatenation[i] = s2[j];
		i++;
		j++;
	}
	concatenation[i] = '\0';
	return (concatenation);
}
