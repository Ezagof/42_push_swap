/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:31:34 by aautin            #+#    #+#             */
/*   Updated: 2023/12/05 11:10:35 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_list	*ft_lstbeforelast(t_list *lst)
{
	if (lst->next == NULL || lst == NULL)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

static void	move(t_list **lst)
{
	t_list	*prelast_node;
	t_list	*last_node;

	prelast_node = ft_lstbeforelast(*lst);
	last_node = ft_lstlast(*lst);
	last_node->next = *lst;
	prelast_node->next = NULL;
	*lst = last_node;
}

int	rotate_rev(t_list **lst, char name)
{
	if (*lst && (*lst)->next)
	{
		move(lst);
		if (name == 'a')
			ft_printf("rra\n");
		if (name == 'b')
			ft_printf("rrb\n");
		return (1);
	}
	return (0);
}

int	rotate_rrev(t_list **lst_a, t_list **lst_b)
{
	if (*lst_a && (*lst_a)->next && *lst_b && (*lst_b)->next)
	{
		move(lst_a);
		move(lst_b);
		ft_printf("rrr\n");
		return (2);
	}
	return (0);
}
