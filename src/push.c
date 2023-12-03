/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:36:31 by aautin            #+#    #+#             */
/*   Updated: 2023/12/03 19:09:06 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_lstremove_front(t_list **lst)
{
	t_list	*prev_first;
	t_list	*next_first;

	if (lst == NULL || *lst == NULL)
		return ;
	prev_first = *lst;
	next_first = (*lst)->next;
	free(prev_first);
	*lst = next_first;
}

int	push_a(t_list **lst_a, t_list **lst_b)
{
	if (*lst_b != NULL)
	{
		if (*lst_a == NULL)
			*lst_a = ft_lstnew((*lst_b)->value);
		else
			ft_lstadd_front(lst_a, ft_lstnew((*lst_b)->value));
		ft_printf("pa\n");
		ft_lstremove_front(lst_b);
		return (1);
	}
	return (0);
}

int	push_b(t_list **lst_a, t_list **lst_b)
{
	if (*lst_a != NULL)
	{
		if (*lst_b == NULL)
			*lst_b = ft_lstnew((*lst_a)->value);
		else
			ft_lstadd_front(lst_b, ft_lstnew((*lst_a)->value));
		ft_printf("pb\n");
		ft_lstremove_front(lst_a);
		return (1);
	}
	return (0);
}
