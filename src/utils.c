/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:59:33 by aautin            #+#    #+#             */
/*   Updated: 2023/12/03 18:53:07 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_printlst(t_list *lst)
{
	while (lst)
	{
		ft_printf("%d-->", lst->value);
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
