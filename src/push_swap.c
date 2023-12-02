/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:59:23 by aautin            #+#    #+#             */
/*   Updated: 2023/12/02 20:26:25 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push_swap(t_list *lst_a, t_list *lst_b)
{
	int	moves_nb;

	moves_nb = 0;
	moves_nb += swap_a(lst_a);
	ft_printlsts(lst_a, lst_b);
	moves_nb += push_b(lst_a, lst_b);
	ft_printlsts(lst_a, lst_b);
	return (moves_nb);
}
