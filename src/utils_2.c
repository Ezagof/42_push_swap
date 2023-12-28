/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:59:33 by aautin            #+#    #+#             */
/*   Updated: 2023/12/28 16:20:57 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_islstsorted(t_list *lst)
{
	while (lst->next)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	ft_indexmax(t_list *lst)
{
	int	value;
	int	indexmax;
	int	i;

	value = lst->value;
	indexmax = 0;
	i = 0;
	while (lst)
	{
		if (lst->value > value)
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
	int	value;
	int	indexmin;
	int	i;

	value = lst->value;
	indexmin = 0;
	i = 0;
	while (lst)
	{
		if (lst->value < value)
		{
			value = lst->value;
			indexmin = i;
		}
		lst = lst->next;
		i++;
	}
	return (indexmin);
}

void	ft_placemintop(t_list **lst, char lst_name)
{
	int	i_max;

	i_max = ft_indexmin(*lst);
	if (i_max > ft_lstsize(*lst) / 2)
	{
		while (i_max < ft_lstsize(*lst))
		{
			rotate_rev(lst, lst_name);
			i_max++;
		}
	}
	else
	{
		while (i_max)
		{
			rotate(lst, lst_name);
			i_max--;
		}
	}
}
