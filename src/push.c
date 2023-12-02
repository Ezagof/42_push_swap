/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:36:31 by aautin            #+#    #+#             */
/*   Updated: 2023/12/02 20:45:05 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int	push_a(t_list *lst_a, t_list *lst_b)
{
	t_list	*temp1;
	t_list	*temp2;

	if (lst_b)
	{
		temp1 = ft_lstlast(lst_b);
		temp2 = ft_lstlast(lst_a);
		temp2->next = temp1;
		ft_printf("pa\n");
		return (1);
	}
	return (0);
}

int	push_b(t_list *lst_a, t_list *lst_b)
{
	t_list	*temp1;
	t_list	*temp2;

	if (lst_a)
	{
		temp1 = ft_lstlast(lst_a);
		temp2 = ft_lstlast(lst_b);
		temp2->next = temp1;
		ft_printf("pb\n");
		return (1);
	}
	return (0);
}
