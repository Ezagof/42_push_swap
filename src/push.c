/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:36:31 by aautin            #+#    #+#             */
/*   Updated: 2023/12/04 17:00:41 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	move(t_list **dest, t_list **src)
{
	t_list	*dest_fst;
	t_list	*src_fst;

	dest_fst = *dest;
	src_fst = *src;
	*src = (*src)->next;
	src_fst->next = dest_fst;
	*dest = src_fst;
}

int	push(t_list **dest, t_list **src, char name)
{
	if (*src != NULL)
	{
		move(dest, src);
		if (name == 'a')
			ft_printf("pa\n");
		if (name == 'b')
			ft_printf("pb\n");
		return (1);
	}
	return (0);
}
