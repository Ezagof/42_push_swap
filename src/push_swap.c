/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:59:23 by aautin            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/12/12 18:12:39 by aautin           ###   ########.fr       */
=======
/*   Updated: 2023/12/12 22:15:15 by aautin           ###   ########.fr       */
>>>>>>> opposite_way
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_is_mixed_cheaper(t_conf *stack, int dst_i, int dst_size)
{
	int	src_mv;
	int	dst_mv;

	if (dst_size - dst_i + 1 < dst_i)
		dst_mv = -(dst_size - dst_i);
	else
		dst_mv = dst_i;
	if (ft_lstsize(stack->first) - stack->i + 1 < stack->i)
		src_mv = -(ft_lstsize(stack->first) - stack->i);
	else
		src_mv = stack->i;
	if ((src_mv < 0 && dst_mv > 0) || (src_mv > 0 && dst_mv < 0))
	{
		if (ft_abs(src_mv) + ft_abs(dst_mv) < ft_abs(stack->min_mv_nb))
		{
			stack->min_mv_nb = ft_abs(src_mv) + ft_abs(dst_mv);
			stack->rotate_dst = dst_mv;
			stack->rotate_src = src_mv;
			stack->min_is_mixed = 1;
		}
		else
			stack->min_is_mixed = 0;
	}
	else
		stack->min_is_mixed = 0;
}

static void	ft_cheapest(t_conf *stack, int dst_i, int dst_size)
{
	stack->min_top = ft_give_biggest(dst_i, stack->i);
	stack->min_bot = ft_give_biggest(dst_size - dst_i,
			ft_lstsize(stack->first) - stack->i);
	if (stack->min_bot + 1 < stack->min_top
		&& stack->min_bot + 1 < ft_abs(stack->min_mv_nb))
	{
		stack->min_mv_nb = -(stack->min_bot);
		stack->rotate_dst = dst_size - dst_i + (ft_lstsize(stack->first) == 1);
		stack->rotate_src = ft_lstsize(stack->first) - stack->i;
	}
	else if (stack->min_top < ft_abs(stack->min_mv_nb))
	{
		stack->min_mv_nb = stack->min_top;
		stack->rotate_dst = dst_i;
		stack->rotate_src = stack->i;
	}
	ft_is_mixed_cheaper(stack, dst_i, dst_size);
}

static void	ft_apply_rotates_rev(t_conf *stk, t_list **dst, t_list **src)
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

static void	ft_apply_rotates(t_conf *stk, t_list **dst, t_list **src)
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

void	ft_eco_sending(t_list **dst, t_list **src)
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
	if (stack.min_is_mixed == 1)
		ft_apply_rotates_mixed(&stack, dst, src);
	else if (stack.min_mv_nb >= 0)
		ft_apply_rotates(&stack, dst, src);
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
