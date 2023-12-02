/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:17:25 by aautin            #+#    #+#             */
/*   Updated: 2023/12/02 16:25:00 by aautin           ###   ########.fr       */
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
		ft_lstadd_front(lst, ft_lstnew(ft_atoi(str[i])));
		free(str[i]);
	}
	free(str);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*lst_a;
	t_list	*lst_b;

	lst_a = NULL;
	lst_b = NULL;
	if (argc == 2)
	{
		if (!ft_putinlst(&lst_a, argv[1]))
			return (1);
	}
	else
	{
		while (argc > 1)
			ft_lstadd_back(&lst_a, ft_lstnew(ft_atoi(argv[--argc])));
	}
	ft_printlsts(lst_a, lst_b);
	ft_printf("%d\n", push_swap(lst_a, lst_b));
	ft_lstclear(&lst_a);
	ft_lstclear(&lst_b);
	return (0);
}
