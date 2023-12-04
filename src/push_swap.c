/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:59:23 by aautin            #+#    #+#             */
/*   Updated: 2023/12/04 17:11:10 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push_swap(t_list **lst_a, t_list **lst_b)
{
	int	moves_nb;

	// (void) lst_a;
	// (void) lst_b;
	moves_nb = 0;
	moves_nb += push(lst_b, lst_a, 'b');
	ft_printlsts(*lst_a, *lst_b);
	moves_nb += push(lst_b, lst_a, 'b');
	ft_printlsts(*lst_a, *lst_b);
	moves_nb += push(lst_b, lst_a, 'b');
	ft_printlsts(*lst_a, *lst_b);
	moves_nb += rotate(lst_a, 'a');
	ft_printlsts(*lst_a, *lst_b);
	moves_nb += rotate_r(lst_b, lst_a);
	ft_printlsts(*lst_a, *lst_b);
	moves_nb += push(lst_b, lst_a, 'b');
	ft_printlsts(*lst_a, *lst_b);
	moves_nb += push(lst_b, lst_a, 'b');
	ft_printlsts(*lst_a, *lst_b);
	moves_nb += push(lst_b, lst_a, 'b');
	ft_printlsts(*lst_a, *lst_b);
	return (moves_nb);
}
