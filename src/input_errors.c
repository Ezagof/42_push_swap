/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:04:17 by aautin            #+#    #+#             */
/*   Updated: 2023/12/05 16:20:59 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_is_str_number(char *str)
{
	int	i;
	int	digit_present;

	i = 0;
	digit_present = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] != ' ' && str[i] != '-')
				return (0);
		}
		else
			digit_present = 1;
		i++;
	}
	return (digit_present);
}

static void	ft_lst_to_tab(int *tab, t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		tab[i++] = lst->value;
		lst = lst->next;
	}
}

int	ft_nbs_separated(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_is_str_number(argv[i]))
			return (1);
		if (ft_atol(argv[i]) < INT_MIN || INT_MAX < ft_atol(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_nbs_combined(char *argv)
{
	char	**str;
	int		i;

	if (!ft_is_str_number(argv))
		return (1);
	str = ft_split(argv, ' ');
	i = 0;
	while (str[i])
	{
		if (ft_atol(str[i]) < INT_MIN || INT_MAX < ft_atol(str[i]))
			return (ft_free_dbtab(str, i));
		if (!ft_is_str_number(str[i]))
			return (ft_free_dbtab(str, i));
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

int	ft_unique_integers(t_list *lst)
{
	int		*int_tab;
	size_t	i;
	size_t	j;
	size_t	size;

	size = ft_lstsize(lst);
	int_tab = (int *)malloc(size * sizeof(int));
	if (!int_tab)
		return (0);
	ft_lst_to_tab(int_tab, lst);
	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (int_tab[i] == int_tab[j])
			{
				free(int_tab);
				return (0);
			}
		}
	}
	free(int_tab);
	return (1);
}
