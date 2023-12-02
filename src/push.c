/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:36:31 by aautin            #+#    #+#             */
/*   Updated: 2023/12/02 20:31:50 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	erase_lastnode(t_list **lst)
{
	t_list	*temp;
	t_list	**lastnode;

	temp = ft_lstlast(*lst);
	lastnode = lst;
	while ((*lastnode)->next->next)
		*lastnode = (*lastnode)->next;
	(*lastnode)->next = NULL;
	free(temp);
}

int	push_a(t_list *lst_a, t_list *lst_b)
{
	if (lst_b)
	{
		ft_lstadd_back(&lst_a, ft_lstnew(ft_lstlast(lst_b)->value));
		erase_lastnode(&lst_b);
		ft_printf("pa\n");
		return (1);
	}
	return (0);
}

int	push_b(t_list *lst_a, t_list *lst_b)
{
	if (lst_a)
	{
		ft_lstadd_back(&lst_b, ft_lstnew(ft_lstlast(lst_a)->value));
		erase_lastnode(&lst_a);
		ft_printf("pb\n");
		return (1);
	}
	return (0);
}
