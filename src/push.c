/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:36:31 by aautin            #+#    #+#             */
/*   Updated: 2023/12/03 17:16:33 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_lstremove_back(t_list **lst)
{
	t_list	*current;
	t_list	*prev;

	current = *lst;
	if (current->next == NULL)
	{
		*lst = NULL;
		free(*lst);
		return ;
	}
	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	if (prev != NULL)
		prev->next = NULL;
	else
		*lst = NULL;
	free(current);
}

int	push_a(t_list **lst_a, t_list **lst_b)
{
	t_list	*first_node;

	if (*lst_b != NULL)
	{
		if (*lst_a == NULL)
			*lst_a = ft_lstnew(ft_lstlast(*lst_b)->value);
		else
		{
			first_node = *lst_a;
			while ((*lst_a)->next)
				*lst_a = (*lst_a)->next;
			(*lst_a)->next = ft_lstnew(ft_lstlast(*lst_b)->value);
			*lst_a = first_node;
		}
		ft_printf("pa\n");
		ft_lstremove_back(lst_b);
		return (1);
	}
	return (0);
}

int	push_b(t_list **lst_a, t_list **lst_b)
{
	t_list	*first_node;

	if (*lst_a != NULL)
	{
		if (*lst_b == NULL)
			*lst_b = ft_lstnew(ft_lstlast(*lst_a)->value);
		else
		{
			first_node = *lst_b;
			while ((*lst_b)->next)
				*lst_b = (*lst_b)->next;
			(*lst_b)->next = ft_lstnew(ft_lstlast(*lst_a)->value);
			*lst_b = first_node;
		}
		ft_printf("pb\n");
		ft_lstremove_back(lst_a);
		return (1);
	}
	return (0);
}
