/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:59:33 by aautin            #+#    #+#             */
/*   Updated: 2023/12/28 15:59:09 by aautin           ###   ########.fr       */
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
		if (lst->value > value)
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
		if (lst->value < value)
		{
			value = lst->value;
			indexmin = i;
		}
		lst = lst->next;
		i++;
	}
	return (indexmin);
}

void	ft_placemintop(t_list **lst, char lst_name)
{
	int	i_max;

	i_max = ft_indexmin(*lst);
	if (i_max > ft_lstsize(*lst) / 2)
	{
		while (i_max < ft_lstsize(*lst))
		{
			rotate_rev(lst, lst_name);
			i_max++;
		}
	}
	else
	{
		while (i_max)
		{
			rotate(lst, lst_name);
			i_max--;
		}
	}
}
