/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 23:39:43 by aautin            #+#    #+#             */
/*   Updated: 2023/12/02 00:20:18 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_list *a)
{
	int	i;

	if (ft_lstsize(a) > 1)
	{
		i = 0;
		while (i++ < ft_lstsize(a) - 1)
			a = a->next;
		a->next->next = a;
		a->next = NULL;
	}
	ft_printf("sa\n");
}