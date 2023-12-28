/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:59:23 by aautin            #+#    #+#             */
/*   Updated: 2023/12/28 15:40:40 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		rotate_rev(src, stk->s_name);
		(stk->rotate_src)--;
	}
	while (stk->rotate_dst)
	{
		rotate_rev(dst, stk->d_name);
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
		rotate(src, stk->s_name);
		(stk->rotate_src)--;
	}
	while (stk->rotate_dst)
	{
		rotate(dst, stk->d_name);
		(stk->rotate_dst)--;
	}
}

void	ft_eco_sending(t_list **dst, t_list **src, char d_name, char s_name)
{
	t_conf	stack;

	stack.d_name = d_name;
	stack.s_name = s_name;
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
		ft_apply_rotates(&stack, dst, src);
	else
		ft_apply_rotates_rev(&stack, dst, src);
	push(dst, src, d_name);
}

int	ft_islstsorted(t_list *lst)
{
	while (lst->next)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}
