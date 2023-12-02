/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:09:34 by aautin            #+#    #+#             */
/*   Updated: 2023/12/02 20:16:35 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

// utils.c
void	ft_printlst(t_list *lst);
void	ft_printlsts(t_list	*lst_a, t_list *lst_b);

// push_swap.c
int	push_swap(t_list *lst_a, t_list *lst_b);

// mandatories : swap.c / rotate.c / push.c
int	push_a(t_list *lst_a, t_list *lst_b);
int	push_b(t_list *lst_a, t_list *lst_b);

int	swap_a(t_list *a);
int	swap_b(t_list *a);
int	swap_s(t_list *lst_a, t_list *lst_b);

// main.c
int		main(int argc, char *argv[]);

#endif