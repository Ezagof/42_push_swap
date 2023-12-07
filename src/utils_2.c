/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:59:33 by aautin            #+#    #+#             */
/*   Updated: 2023/12/07 20:39:14 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_indexmin(t_list *lst)
{
	int value;
	int	indexmin;
	int	i;

	value = lst->value;
	indexmin = 0;
	i = 0;
	while (lst)
	{
		if (value > lst->value)
		{
			value = lst->value;
			indexmin = i;
		}
		lst = lst->next;
		i++;
	}
	return (indexmin);
}

int	ft_findcurrentplace(t_list *lst, t_list *node)
{
	int	pos;

	pos = 0;
	while (lst && lst->value != node->value)
	{
		lst = lst->next;
		pos++;
	}
	return (pos);
}
