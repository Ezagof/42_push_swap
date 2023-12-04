/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:09:34 by aautin            #+#    #+#             */
/*   Updated: 2023/12/04 17:07:59 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"


// push_swap.c
int		push_swap(t_list **lst_a, t_list **lst_b);

//---------
// swap.c
int		swap(t_list *a, char name);
int		swap_s(t_list *lst_a, t_list *lst_b);
// push.c
int		push(t_list **lst_a, t_list **lst_b, char name);
// rotate.c
int		rotate(t_list **lst, char name);
int		rotate_r(t_list **lst_a, t_list **lst_b);
// rotate_reverse.c
int		rotate_rev(t_list **lst, char name);
int		rotate_rrev(t_list **lst_a, t_list **lst_b);

// utils.c
void	ft_printlsts(t_list	*lst_a, t_list *lst_b);

// inputs_errors.c
int		ft_input_errors(int argc, char *argv[]);

// main.c
int		main(int argc, char *argv[]);

#endif