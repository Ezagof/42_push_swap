/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:17:25 by aautin            #+#    #+#             */
/*   Updated: 2023/12/06 18:58:20 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
