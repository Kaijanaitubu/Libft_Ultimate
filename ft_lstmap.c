/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tubu <tubu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:48:05 by kmogami           #+#    #+#             */
/*   Updated: 2025/01/08 15:55:33 by tubu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ult.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*node;

	if (!f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		node = ft_lstnew ((*f)(lst->content));
		if (!node)
		{
			ft_lstclear(&first, (*del));
			return (NULL);
		}
		ft_lstadd_back(&first, node);
		lst = lst->next;
	}
	return (first);
}
