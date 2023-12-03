/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:31:34 by aautin            #+#    #+#             */
/*   Updated: 2023/12/03 19:06:55 by aautin           ###   ########.fr       */
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

// here, have to turn the lastone into first and the beforelastone into lastone

static void	rotate(t_list **lst_a, t_list *top_node, t_list *bot_node)
{
	bot_node->next = top_node;
	*lst_a = top_node->next;
	top_node->next = NULL;
}

int	rotate_ra(t_list **lst_a)
{
	t_list	*top_node;
	t_list	*bot_node;

	top_node = *lst_a;
	bot_node = ft_lstlast(*lst_a);
	rotate(lst_a, top_node, bot_node);
	ft_printf("ra\n");
	return (1);
}

int	rotate_rb(t_list **lst_b)
{
	t_list	*top_node;
	t_list	*bot_node;

	top_node = *lst_b;
	bot_node = ft_lstlast(*lst_b);
	rotate(lst_b, top_node, bot_node);
	ft_printf("rs\n");
	return (1);
}

int	rotate_rr(t_list **lst_a, t_list **lst_b)
{
	t_list	*top_node;
	t_list	*bot_node;

	top_node = *lst_a;
	bot_node = ft_lstlast(*lst_a);
	rotate(lst_a, top_node, bot_node);
	top_node = *lst_b;
	bot_node = ft_lstlast(*lst_b);
	rotate(lst_b, top_node, bot_node);
	ft_printf("rr\n");
	return (1);
}
