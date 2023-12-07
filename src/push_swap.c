/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:59:23 by aautin            #+#    #+#             */
/*   Updated: 2023/12/07 22:05:31 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_eco_sending(t_list **dst, t_list **src)
{
	t_list		*first_node;
	t_list		*min_mv_node;
	long int	min_mv_nb;
	long int	mv_nb;
	int			index_node;

	first_node = *src;
	min_mv_node = *src;
	min_mv_nb = ft_lstsize(src);
	while (*src)
	{
		mv_nb = ft_placeindex(*dst, (*src)->value) - ft_lstsize(src) / 2;
		if (abs(mv_nb) < min_mv_nb)
		{
			min_mv_nb = mv_nb;
			min_mv_node = *src;
		}
		*src = (*src)->next;
	}
	

	*src = first_node;
}

void	ft_sort_list(t_list **lst_a, t_list **lst_b)
{
	while (ft_lstsize(*lst_a))
		ft_eco_sending(lst_b, lst_a);
	return ;
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
		ft_sort_list(lst_a, lst_b);
}
