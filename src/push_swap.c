/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:59:23 by aautin            #+#    #+#             */
/*   Updated: 2023/12/12 22:15:15 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_cheapest(t_conf *stack, int dst_i, int dst_size)
{
	int	min_top;
	int	min_bot;

	if (dst_i > stack->i)
		min_top = dst_i;
	else
		min_top = stack->i;
	if (dst_size - dst_i > ft_lstsize(stack->first) - stack->i)
		min_bot = dst_size - dst_i;
	else
		min_bot = ft_lstsize(stack->first) - stack->i;
	if (min_bot + 1 < min_top && min_bot + 1 < ft_abs(stack->min_mv_nb)
		&& min_bot != 0)
	{
		stack->min_mv_nb = -min_bot;
		stack->rotate_dst = dst_size - dst_i + (ft_lstsize(stack->first) == 1);
		stack->rotate_src = ft_lstsize(stack->first) - stack->i;
	}
	else if (min_top < ft_abs(stack->min_mv_nb))
	{
		stack->min_mv_nb = min_top;
		stack->rotate_dst = dst_i;
		stack->rotate_src = stack->i;
	}
}

static void	apply_rotates_rev(t_conf *stk, t_list **dst, t_list **src)
{
	while (stk->rotate_src && stk->rotate_dst)
	{
		rotate_rrev(src, dst);
		(stk->rotate_src)--;
		(stk->rotate_dst)--;
	}
	while (stk->rotate_src)
	{
		rotate_rev(src, 'b');
		(stk->rotate_src)--;
	}
	while (stk->rotate_dst)
	{
		rotate_rev(dst, 'a');
		(stk->rotate_dst)--;
	}
}

static void	apply_rotates(t_conf *stk, t_list **dst, t_list **src)
{
	while (stk->rotate_src && stk->rotate_dst)
	{
		rotate_r(src, dst);
		(stk->rotate_src)--;
		(stk->rotate_dst)--;
	}
	while (stk->rotate_src)
	{
		rotate(src, 'b');
		(stk->rotate_src)--;
	}
	while (stk->rotate_dst)
	{
		rotate(dst, 'a');
		(stk->rotate_dst)--;
	}
}

static void	ft_eco_sending(t_list **dst, t_list **src)
{
	t_conf	stack;

	stack.first = *src;
	stack.min_mv_nb = ft_lstsize(*src) + ft_lstsize(*dst);
	stack.i = 0;
	while (*src)
	{
		ft_cheapest(&stack, ft_i_place(*dst, (*src)->value), ft_lstsize(*dst));
		*src = (*src)->next;
		(stack.i)++;
	}
	*src = stack.first;
	if (stack.min_mv_nb >= 0)
		apply_rotates(&stack, dst, src);
	else
		apply_rotates_rev(&stack, dst, src);
	push(dst, src, 'a');
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
			push(lst_b, lst_a, 'b');
		while (ft_lstsize(*lst_b) > 0)
			ft_eco_sending(lst_a, lst_b);
		ft_placemintop(lst_a);
		return ;
	}
}
