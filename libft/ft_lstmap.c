/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:37:42 by jrenault          #+#    #+#             */
/*   Updated: 2022/11/18 15:08:20 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
	void (*del)(void *))
{
	t_list	*new;
	t_list	*node;

	node = NULL;
	if (!lst || !f || !del)
		return (lst);
	while (lst != NULL)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
			ft_lstclear(&node, del);
		ft_lstadd_back(&node, new);
		lst = lst->next;
	}
	return (node);
}
