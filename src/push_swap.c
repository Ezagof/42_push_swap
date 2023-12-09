/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:59:23 by aautin            #+#    #+#             */
/*   Updated: 2023/12/09 19:52:34 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_cheapest(int src_i, int dest_i, int src_size, int dest_size)
{
	int	min_top;
	int	min_bot;

	if (dest_i > src_i)
		min_top = dest_i;
	else
		min_top = src_i;
	if (dest_i < src_i)
		min_bot = dest_size - dest_i + 1;
	else
		min_bot = src_size - src_i + 1;
	if (min_bot < min_top)
		return (-min_bot);
	else
		return (min_top);
}

static void	ft_eco_sending(t_list **dst, t_list **src)
{
	t_conf	stack;

	stack.first = *src;
	stack.min_mv_nb = ft_lstsize(*src) + ft_lstsize(*dst);
	while (*src)
	{
		stack.mv_nb = ft_cheapest(stack.i, ft_i_place(*dst, (*src)->value),
				ft_lstsize(stack.first), ft_lstsize(*dst));
		if (ft_abs(stack.mv_nb) < ft_abs(stack.min_mv_nb))
		{
			stack.i = ft_i_place(*dst, (*src)->value);
			stack.min_mv_nb = stack.mv_nb;
			stack.min_mv_node = *src;
		}
		*src = (*src)->next;
	}
	*src = stack.first;
	if (stack.min_mv_nb >= 0)
	{
		while (stack.min_mv_nb > 0)
		{
			if (stack.min_mv_node != (*src) && stack.i > 0)
				rotate_r(src, dst);
			else if (stack.min_mv_node != (*src) && stack.i <= 0)
				rotate(src, 'a');
			else if (stack.min_mv_node == (*src) && stack.i > 0)
				rotate(dst, 'b');
			(stack.min_mv_nb)--;
			(stack.i)--;
		}
		push(dst, src, 'b');
	}
	else
	{
		while (stack.min_mv_nb < 0)
		{
			if (stack.min_mv_node != (*src) && stack.i < ft_lstsize(*dst))
				rotate_rrev(src, dst);
			if (stack.min_mv_node != (*src) && stack.i >= ft_lstsize(*dst))
				rotate_rev(src, 'a');
			if (stack.min_mv_node == (*src) && stack.i < ft_lstsize(*dst))
				rotate_rev(dst, 'b');
			(stack.min_mv_nb)++;
			(stack.i)++;
		}
		push(dst, src, 'b');
		rotate(dst, 'b');
	}
}

void	ft_placemaxtop(t_list **lst)
{
	int	i_max;

	i_max = ft_indexmax(*lst);
	if (i_max > ft_lstsize(*lst) / 2)
	{
		while (i_max < ft_lstsize(*lst))
		{
			rotate_rev(lst, 'b');
			i_max++;
		}
	}
	else
	{
		while (i_max)
		{
			rotate(lst, 'b');
			i_max--;
		}
	}
}

void	push_swap(t_list **lst_a, t_list **lst_b)
{
	if (ft_lstsize(*lst_a) == 1)
		return ;
	if (ft_lstsize(*lst_a) == 2)
	{
		if ((*lst_a)->value > (*lst_a)->next->value)
			rotate(lst_a, 'a');
	}
	else if (ft_lstsize(*lst_a) == 3)
		ft_sort_three_list(lst_a);
	else if (ft_lstsize(*lst_a) == 4)
		ft_sort_four_list(lst_a, lst_b);
	else if (ft_lstsize(*lst_a) == 5)
		ft_sort_five_list(lst_a, lst_b);
	else
	{
		while (ft_lstsize(*lst_a) > 0)
			ft_eco_sending(lst_b, lst_a);
		ft_placemaxtop(lst_b);
		while (ft_lstsize(*lst_b) > 0)
			push(lst_a, lst_b, 'a');
		return ;
	}
}
