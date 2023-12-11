/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:31:34 by aautin            #+#    #+#             */
/*   Updated: 2023/12/11 16:45:18 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	move(t_list **lst)
{
	t_list	*top_node;
	t_list	*bot_node;

	top_node = *lst;
	bot_node = ft_lstlast(*lst);
	bot_node->next = top_node;
	*lst = top_node->next;
	top_node->next = NULL;
}

int	rotate(t_list **lst, char name)
{
	if (*lst && (*lst)->next)
	{
		move(lst);
		if (name == 'a')
			ft_printf("ra\n");
		if (name == 'b')
			ft_printf("rb\n");
		return (1);
	}
	return (0);
}

int	rotate_r(t_list **lst_a, t_list **lst_b)
{
	if (*lst_a && (*lst_a)->next && *lst_b && (*lst_b)->next)
	{
		move(lst_a);
		move(lst_b);
		ft_printf("rr\n");
		return (2);
	}
	return (0);
}
