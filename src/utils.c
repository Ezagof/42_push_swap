/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:59:33 by aautin            #+#    #+#             */
/*   Updated: 2023/12/11 16:18:55 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lst_to_tab(int *tab, t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		tab[i++] = lst->value;
		lst = lst->next;
	}
}

void	ft_lstsclear(t_list **lst_a, t_list **lst_b)
{
	ft_lstclear(lst_a);
	ft_lstclear(lst_b);
}

long int	ft_atol(char *str)
{
	int			i;
	long int	nb;
	char		sign;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		nb = (nb * 10) + str[i] - 48;
		i++;
	}
	return (nb * sign);
}

int	ft_free_dbtab(char **str, int i)
{
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (1);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}
