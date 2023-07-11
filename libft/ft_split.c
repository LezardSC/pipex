/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:56:38 by jrenault          #+#    #+#             */
/*   Updated: 2022/11/11 10:56:38 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_split(char **split_tab)
{
	int	i;

	i = 0;
	while (split_tab[i])
	{
		free(split_tab[i]);
		i++;
	}
	free(split_tab);
	return (NULL);
}

static int	first_tab_len(const char *s, char c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0' && i != 0)
			count++;
		i++;
	}
	return (count);
}

static char	**shrink_split(unsigned int *i,
	unsigned int *i_tab, const char *s, char c)
{
	char	**split_tab;

	*i = -1;
	*i_tab = 0;
	split_tab = (char **)malloc(sizeof(char *) * (first_tab_len(s, c) + 2));
	return (split_tab);
}

char	**ft_split(const char *s, char c)
{
	unsigned int	i;
	unsigned int	i_tab;
	unsigned int	start;
	char			**split_tab;

	if (!s)
		return (NULL);
	split_tab = shrink_split(&i, &i_tab, s, c);
	if (!split_tab)
		return (NULL);
	while (s[++i])
	{	
		while (s[i + 1] && s[i] == c)
			i++;
		start = i;
		while (s[i + 1] && s[i] != c)
			i++;
		if (s[i + 1] == '\0' && s[i] != c)
			split_tab[i_tab++] = ft_substr(s, start, ((i - start) + 1));
		else if (i - start > 0)
			split_tab[i_tab++] = ft_substr(s, start, (i - start));
		if (!split_tab)
			return (free_split(split_tab));
	}
	return (split_tab[i_tab] = NULL, split_tab);
}
