/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:59:33 by aautin            #+#    #+#             */
/*   Updated: 2023/12/09 21:27:19 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

static void	ft_setup(t_conf *stack, t_list **lst)
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
		if (value > lst->value)
			return (stack.i);
		lst = lst->next;
		(stack.i)++;
	}
	if (stack.i != stack.min_i)
	{
		lst = stack.first;
		stack.i = 0;
		while (stack.i < stack.min_i)
		{
			if (value > lst->value)
				return (stack.i);
			lst = lst->next;
			(stack.i)++;
		}
	}
	return (stack.i);
}

int	ft_indexmax(t_list *lst)
{
	int	value;
	int	indexmax;
	int	i;

	value = lst->value;
	indexmax = 0;
	i = 0;
	while (lst)
	{
		if (value < lst->value)
		{
			value = lst->value;
			indexmax = i;
		}
		lst = lst->next;
		i++;
	}
	return (indexmax);
}

int	ft_indexmin(t_list *lst)
{
	int	value;
	int	indexmin;
	int	i;

	value = lst->value;
	indexmin = 0;
	i = 0;
	while (lst)
	{
		if (value > lst->value)
		{
			value = lst->value;
			indexmin = i;
		}
		lst = lst->next;
		i++;
	}
	return (indexmin);
}
