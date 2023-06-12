/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:26:49 by jrenault          #+#    #+#             */
/*   Updated: 2022/11/15 11:42:52 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int searchedChar)
{
	int	len;

	len = ft_strlen((string));
	while (len >= 0)
	{
		if (string[len] == ((char)searchedChar))
			return (&((char *)string)[len]);
		len--;
	}
	return (0);
}
