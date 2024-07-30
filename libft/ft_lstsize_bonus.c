/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:27:15 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/23 11:00:51 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		nodes;
	t_list	*my_lst;

	if (!lst)
		return (0);
	nodes = 1;
	my_lst = lst;
	while (my_lst->next)
	{
		my_lst = my_lst->next;
		nodes++;
	}
	return (nodes);
}
