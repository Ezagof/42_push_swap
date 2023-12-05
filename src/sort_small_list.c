/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:18:31 by aautin            #+#    #+#             */
/*   Updated: 2023/12/05 18:52:41 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_sort_two_list(t_list **lst_a)
{
	if ((*lst_a)->value > (*lst_a)->next->value)
	{
		rotate(lst_a, 'a');
		return (1);
	}
	else
		return (0);
}

int	ft_sort_three_list(t_list **l)
{
	if ((*l)->value < (*l)->next->value)
	{
		if ((*l)->next->value < (*l)->next->next->value)
			return (0);
		else if ((*l)->value < (*l)->next->next->value)
			return (swap(*l, 'a') + rotate(l, 'a'));
		else
			return (rotate_rev(l, 'a'));
	}
	else
	{
		if ((*l)->next->value > (*l)->next->next->value)
			return (swap(*l, 'a') + rotate_rev(l, 'a'));
		else if ((*l)->value > (*l)->next->next->value)
			return (rotate(l, 'a'));
		else
			return (swap(*l, 'a'));
	}
	return (0);
}
