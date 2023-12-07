/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:59:33 by aautin            #+#    #+#             */
/*   Updated: 2023/12/07 21:29:47 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long int	abs(long int nb)
{
	if (nb < 0)
		return (-nb)
	else
		return (nb);
}

int	ft_placeindex(t_list *lst, int value)
{
	int	i;

	i = 0;
	while (value > lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_indexmax(t_list *lst)
{
	int value;
	int	indexmax;
	int	i;

	value = lst->value;
	indexmax = 0;
	i = 0;
	while (lst)
	{
		if (value < lst->value)
		{
			value = lst->value;
			indexmax = i;
		}
		lst = lst->next;
		i++;
	}
	return (indexmax);
}

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

// useless for now
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
