/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:59:33 by aautin            #+#    #+#             */
/*   Updated: 2023/12/28 16:23:10 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_setup(t_conf *stack, t_list **lst)
{
	stack->i = 0;
	stack->first = *lst;
	stack->min_i = ft_indexmin(*lst);
	stack->max_i = ft_indexmax(*lst);
	while (stack->i < stack->min_i)
	{
		(*lst) = (*lst)->next;
		(stack->i)++;
	}
}

static void	ft_setup_rev(t_conf *stack, t_list **lst)
{
	stack->i = 0;
	stack->first = *lst;
	stack->min_i = ft_indexmin(*lst);
	stack->max_i = ft_indexmax(*lst);
	while (stack->i < stack->max_i)
	{
		(*lst) = (*lst)->next;
		(stack->i)++;
	}
}

int	ft_i_place(t_list *lst, int value)
{
	t_conf	stack;

	if (lst == NULL)
		return (0);
	ft_setup(&stack, &lst);
	while (lst)
	{
		if (value < lst->value)
			return (stack.i);
		lst = lst->next;
		(stack.i)++;
	}
	if (stack.i > stack.max_i)
	{
		stack.i = 0;
		lst = stack.first;
		while (stack.i <= stack.max_i)
		{
			if (value < lst->value)
				return (stack.i);
			lst = lst->next;
			(stack.i)++;
		}
	}
	return (stack.i);
}

int	ft_i_place_rev(t_list *lst, int value)
{
	t_conf	stack;

	if (lst == NULL)
		return (0);
	ft_setup_rev(&stack, &lst);
	while (lst)
	{
		if (value > lst->value)
			return (stack.i);
		lst = lst->next;
		(stack.i)++;
	}
	if (stack.i > stack.min_i)
	{
		stack.i = 0;
		lst = stack.first;
		while (stack.i <= stack.min_i)
		{
			if (value > lst->value)
				return (stack.i);
			lst = lst->next;
			(stack.i)++;
		}
	}
	return (stack.i);
}
