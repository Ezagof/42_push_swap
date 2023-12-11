/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 23:39:43 by aautin            #+#    #+#             */
/*   Updated: 2023/12/11 16:45:18 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	move(t_list *a, t_list *b)
{
	t_list	*temp;

	temp = ft_lstnew(a->value);
	a->value = b->value;
	b->value = temp->value;
	free(temp);
}

int	swap(t_list *lst, char name)
{
	if (lst && lst->next)
	{
		move(lst, lst->next);
		if (name == 'a')
			ft_printf("sa\n");
		else if (name == 'b')
			ft_printf("sb\n");
		return (1);
	}
	return (0);
}

int	swap_s(t_list *lst_a, t_list *lst_b)
{
	if (lst_a && lst_a->next && lst_b && lst_b->next)
	{
		move(lst_a, lst_a->next);
		move(lst_b, lst_b->next);
		ft_printf("ss\n");
		return (2);
	}
	return (0);
}
