/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:31:34 by aautin            #+#    #+#             */
/*   Updated: 2023/12/03 18:19:27 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rotate_a(t_list **lst_a)
{
	t_list	*frst_node;
	t_list	*last_node;

	frst_node = *lst_a;
	last_node = ft_lstlast(lst_a);
	rotate(lst_a, frst_node, last_node);
	ft_printf("ra\n");
}
