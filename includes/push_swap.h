/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:09:34 by aautin            #+#    #+#             */
/*   Updated: 2023/12/13 12:27:59 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_conf
{
	t_list		*first;
	int			i;
	int			min_i;
	int			max_i;
	int			min_mv_nb;
	int			mv_nb;
	int			rotate_src;
	int			rotate_dst;
	int			min_top;
	int			min_bot;
}				t_conf;

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

// printlst.c
void		ft_printlsts(t_list	*lst_a, t_list *lst_b);

// utils.c
void		ft_lstsclear(t_list **lst_a, t_list **lst_b);
void		ft_lst_to_tab(int *tab, t_list *lst);
long int	ft_atol(char *str);
int			ft_free_dbtab(char **str, int i);
int			ft_abs(int nb);

// utils_2.c
int			ft_i_place(t_list *lst, int value);
int			ft_indexmin(t_list *lst);
int			ft_indexmax(t_list *lst);
void		ft_placemaxtop(t_list **lst);

// input_errors.c
int			ft_nbs_combined(char *argv);
int			ft_nbs_separated(int argc, char *argv[]);
int			ft_unique_integers(t_list *lst);

// sort_small_list.c
void		ft_apply_rotates_mixed(t_conf *stk, t_list **dst, t_list **src);
void		ft_sort_three_list(t_list **l);
void		ft_sort_four_list(t_list **lst_a, t_list **lst_b);
void		ft_sort_five_list(t_list **lst_a, t_list **lst_b);

// push_swap.c
void		ft_eco_sending(t_list **dst, t_list **src);

// main.c
int			ft_give_biggest(int nb1, int nb2);
int			ft_input_errors(int argc, char *argv[]);
void		push_swap(t_list **lst_a, t_list **lst_b);
int			main(int argc, char *argv[]);

#endif