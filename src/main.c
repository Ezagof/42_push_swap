/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:17:25 by aautin            #+#    #+#             */
/*   Updated: 2023/12/04 16:55:25 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_inputs_error(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	// error =	same integer twice, 
	//			an argv isnt an integer (overflow/other ASCII) : argc > 2 case
	//			a splited value isnt an interger ("") : argc == 2 case
	return (0);
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

int	main(int argc, char *argv[])
{
	t_list	*lst_a;
	t_list	*lst_b;

	if (ft_inputs_error(argc, argv))
	{
		ft_printf("Error\n");
		return (0);								// RETURN VALUE IN THIS CASE ?
	}
	lst_a = NULL;
	lst_b = NULL;
	if (argc == 2)
	{
		if (!ft_putinlst(&lst_a, argv[1]))
			return (1);
	}
	else
		while (argc > 1)
			ft_lstadd_front(&lst_a, ft_lstnew(ft_atoi(argv[--argc])));
	ft_printlsts(lst_a, lst_b);
	ft_printf("%d\n", push_swap(&lst_a, &lst_b));
	ft_lstclear(&lst_a);
	ft_lstclear(&lst_b);
	return (0);
}
