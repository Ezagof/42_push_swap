/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:17:25 by aautin            #+#    #+#             */
/*   Updated: 2023/12/02 00:41:03 by aautin           ###   ########.fr       */
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
		ft_lstadd_back(lst, ft_lstnew(ft_atoi(str[i])));
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*a_lst;

	a_lst = NULL;
	if (argc == 2)
	{
		if (!ft_putinlst(&a_lst, argv[1]))
			return (1);
		// swap_a(a_lst);
	}
	else
	{
		while (argc > 1)
			ft_lstadd_back(&a_lst, ft_lstnew(ft_atoi(argv[--argc])));
	}
	ft_printlst(a_lst);
	return (0);
}
