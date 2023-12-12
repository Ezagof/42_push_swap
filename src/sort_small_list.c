/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:18:31 by aautin            #+#    #+#             */
/*   Updated: 2023/12/12 19:40:21 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_apply_rotates_mixed(t_conf *stk, t_list **dst, t_list **src)
{
	while (stk->rotate_src > 0)
	{
		rotate(src, 'a');
		(stk->rotate_src)--;
	}
	while (stk->rotate_src < 0)
	{
		rotate_rev(src, 'a');
		(stk->rotate_src)++;
	}
	while (stk->rotate_dst > 0)
	{
		rotate(dst, 'b');
		(stk->rotate_dst)--;
	}
	while (stk->rotate_dst < 0)
	{
		rotate_rev(dst, 'b');
		(stk->rotate_dst)++;
	}
}

void	ft_sort_three_list(t_list **l)
{
	if ((*l)->value < (*l)->next->value)
	{
		if ((*l)->next->value < (*l)->next->next->value)
			return ;
		else if ((*l)->value < (*l)->next->next->value)
		{
			swap(*l, 'a');
			rotate(l, 'a');
		}
		else
			rotate_rev(l, 'a');
	}
	else
	{
		if ((*l)->next->value > (*l)->next->next->value)
		{
			swap(*l, 'a');
			rotate_rev(l, 'a');
		}
		else if ((*l)->value > (*l)->next->next->value)
			rotate(l, 'a');
		else
			swap(*l, 'a');
	}
}

static void	ft_pushmin(t_list **dest, t_list **src)
{
	int		indexmin;

	indexmin = ft_indexmin(*src);
	if (indexmin <= ft_lstsize(*src) / 2)
	{	
		while (indexmin)
		{
			rotate(src, 'a');
			indexmin--;
		}
	}
	else
	{
		while (ft_lstsize(*src) - indexmin > 0)
		{
			rotate_rev(src, 'a');
			indexmin++;
		}
	}
	push(dest, src, 'b');
}

void	ft_sort_four_list(t_list **lst_a, t_list **lst_b)
{
	ft_pushmin(lst_b, lst_a);
	ft_sort_three_list(lst_a);
	push(lst_a, lst_b, 'a');
}

void	ft_sort_five_list(t_list **lst_a, t_list **lst_b)
{
	ft_pushmin(lst_b, lst_a);
	ft_sort_four_list(lst_a, lst_b);
	push(lst_a, lst_b, 'a');
}
