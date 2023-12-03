/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:31:34 by aautin            #+#    #+#             */
/*   Updated: 2023/12/03 19:06:55 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_list **lst_a, t_list *top_node, t_list *bot_node)
{
	bot_node->next = top_node;
	*lst_a = top_node->next;
	top_node->next = NULL;
}

int	rotate_a(t_list **lst_a)
{
	t_list	*top_node;
	t_list	*bot_node;

	top_node = *lst_a;
	bot_node = ft_lstlast(*lst_a);
	rotate(lst_a, top_node, bot_node);
	ft_printf("ra\n");
	return (1);
}

int	rotate_b(t_list **lst_b)
{
	t_list	*top_node;
	t_list	*bot_node;

	top_node = *lst_b;
	bot_node = ft_lstlast(*lst_b);
	rotate(lst_b, top_node, bot_node);
	ft_printf("rs\n");
	return (1);
}

int	rotate_r(t_list **lst_a, t_list **lst_b)
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
