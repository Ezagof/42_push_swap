/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:17:25 by aautin            #+#    #+#             */
/*   Updated: 2023/12/28 16:00:31 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_give_biggest(int nb1, int nb2)
{
	if (nb1 > nb2)
		return (nb1);
	else
		return (nb2);
}

static int	ft_putinlst(t_list **lst, char *argv)
{
	char	**str;
	size_t	i;

	str = ft_split(argv, ' ');
	if (!str)
		return (0);
	i = -1;
	while (str[++i])
	{
		ft_lstadd_back(lst, ft_lstnew(ft_atoi(str[i])));
		free(str[i]);
	}
	free(str);
	return (1);
}

static int	ft_printf_error(char *str)
{
	ft_printf("%s\n", str);
	return (1);
}

void	push_swap(t_list **lst_a, t_list **lst_b)
{
	if (ft_lstsize(*lst_a) == 1 || ft_islstsorted(*lst_a))
		return ;
	if (ft_lstsize(*lst_a) == 2)
	{
		if ((*lst_a)->value > (*lst_a)->next->value)
			rotate(lst_a, 'a');
	}
	else if (ft_lstsize(*lst_a) == 3)
		ft_sort_three_list(lst_a);
	else if (ft_lstsize(*lst_a) == 4)
		ft_sort_four_list(lst_a, lst_b);
	else if (ft_lstsize(*lst_a) == 5)
		ft_sort_five_list(lst_a, lst_b);
	else
	{
		while (ft_lstsize(*lst_a) > 4)
			push(lst_b, lst_a, 'b');
		ft_sort_four_list(lst_a, lst_b);
		while (ft_lstsize(*lst_b) > 0)
			ft_eco_sending(lst_a, lst_b, 'a', 'b');
		ft_placemintop(lst_a, 'a');
		return ;
	}
}

int	main(int argc, char *argv[])
{
	t_list	*lst_a;
	t_list	*lst_b;

	if (argc == 1)
		return (0);
	if (ft_input_errors(argc, argv))
		return (ft_printf_error("Error"));
	lst_a = NULL;
	lst_b = NULL;
	if (argc == 2)
	{
		if (!ft_putinlst(&lst_a, argv[1]))
			return (ft_printf_error("Allocation error"));
	}
	else
		while (argc > 1)
			ft_lstadd_front(&lst_a, ft_lstnew(ft_atoi(argv[--argc])));
	if (!ft_unique_integers(lst_a))
	{
		ft_lstsclear(&lst_a, &lst_b);
		return (ft_printf_error("Error"));
	}
	push_swap(&lst_a, &lst_b);
	ft_lstsclear(&lst_a, &lst_b);
	return (0);
}
