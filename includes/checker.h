/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:45:42 by aautin            #+#    #+#             */
/*   Updated: 2023/12/11 16:47:09 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

// swap.c
int			swap(t_list *a, char name);
int			swap_s(t_list *lst_a, t_list *lst_b);

// push.c
int			push(t_list **dest, t_list **src, char name);

// rotate.c
int			rotate(t_list **lst, char name);
int			rotate_r(t_list **lst_a, t_list **lst_b);

// rotate_reverse.c
int			rotate_rev(t_list **lst, char name);
int			rotate_rrev(t_list **lst_a, t_list **lst_b);
