/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:59:23 by aautin            #+#    #+#             */
/*   Updated: 2023/12/05 20:19:57 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_sort_list(t_list **lst_a, t_list **lst_b)
{
	int	moves_nb;

	moves_nb = ft_quick_sort(lst_a, lst_b);
	return (0);
}

int	push_swap(t_list **lst_a, t_list **lst_b)
{
	ft_printlsts(*lst_a, *lst_b);
	if (ft_lstsize(*lst_a) == 1)
		return (0);
	if (ft_lstsize(*lst_a) == 2)
		return (ft_sort_two_list(lst_a));
	else if (ft_lstsize(*lst_a) == 3)
		return (ft_sort_three_list(lst_a));
	else
		return (ft_sort_list(lst_a, lst_b));
	return (0);
}
