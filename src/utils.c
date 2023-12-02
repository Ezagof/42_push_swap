/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:59:33 by aautin            #+#    #+#             */
/*   Updated: 2023/12/02 15:15:45 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_printlst(t_list *lst)
{
	ft_printf("=============\n");
	ft_printf("BOT--");
	while (lst)
	{
		ft_printf("%d-->", lst->value);
		lst = lst->next;
	}
	ft_printf("NULL\n");
	ft_printf("=============\n");
}

void	ft_printlsts(t_list	*lst_a, t_list *lst_b)
{
	ft_printlst(lst_a);
	ft_printf("      +      \n");
	ft_printlst(lst_b);
}
