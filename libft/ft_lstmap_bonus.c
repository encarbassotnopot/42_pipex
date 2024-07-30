/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:37:39 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/23 12:03:38 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static t_list	*do_map(t_list *lst_iter, t_list *map_head,
		void *(*f)(void *), void (*del)(void *))
{
	t_list	*map_iter;

	map_iter = map_head;
	while (lst_iter->next)
	{
		map_iter->content = f(lst_iter->content);
		map_iter->next = malloc(sizeof(t_list));
		if (!map_iter->next)
		{
			ft_lstclear(&map_head, del);
			return (map_head);
		}
		lst_iter = lst_iter->next;
		map_iter = map_iter->next;
	}
	map_iter->content = f(lst_iter->content);
	map_iter->next = NULL;
	return (map_head);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*my_lst;

	if (!lst || !f || !del)
		return (NULL);
	my_lst = lst;
	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	return (do_map(my_lst, head, f, del));
}
