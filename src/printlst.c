/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:56:52 by aautin            #+#    #+#             */
/*   Updated: 2023/12/05 16:57:23 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_printlst(t_list *lst)
{
	while (lst)
	{
		ft_printf("[%d]-->", lst->value);
		lst = lst->next;
	}
	ft_printf("NULL\n");
}

void	ft_printlsts(t_list	*lst_a, t_list *lst_b)
{
	ft_printf("\n");
	ft_printlst(lst_a);
	ft_printlst(lst_b);
	ft_printf("\n");
}
