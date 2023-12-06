/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:18:31 by aautin            #+#    #+#             */
/*   Updated: 2023/12/06 18:54:59 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_two_list(t_list **lst_a)
{
	if ((*lst_a)->value > (*lst_a)->next->value)
		rotate(lst_a, 'a');
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

static int	ft_findnewplace(t_list *lst, t_list *node)
{
	int	pos;

	pos = 0;
	while (lst && lst->value < node->value)
	{
		lst = lst->next;
		pos++;
	}
	return (pos);
}

static void	place(t_list **a, t_list **b, int (*f)(t_list **, char))
{
	int	i;
	int	nb;

	i = 0;
	nb = ft_lstsize(*a) - ft_findnewplace(*a, *b);
	while (i < nb)
	{
		f(a, 'a');
		i++;
	}
	push(a, b, 'a');
	while (i-- + 1)
		rotate(a, 'a');
}

void	ft_sort_fourfive_list(t_list **lst_a, t_list **lst_b)
{
	int	rotate_nb;
	int	i;

	while (ft_lstsize(*lst_a) > 3)
		push(lst_b, lst_a, 'b');
	ft_sort_three_list(lst_a);
	while (*lst_b)
	{
		if (ft_findnewplace(*lst_a, *lst_b) > ft_lstsize(*lst_a) / 2)
			place(lst_a, lst_b, rotate_rev);
		else
		{
			i = 0;
			rotate_nb = ft_findnewplace(*lst_a, *lst_b);
			while (i < rotate_nb)
			{
				rotate(lst_a, 'a');
				i++;
			}
			push(lst_a, lst_b, 'a');
			while (i--)
				rotate_rev(lst_a, 'a');
		}
	}
}
