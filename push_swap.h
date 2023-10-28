/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:01:55 by annaershova       #+#    #+#             */
/*   Updated: 2023/10/09 22:43:37 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_obj
{
	long	value;
	size_t	moves;
	size_t	index;
	size_t	curr_pos;
	int		tmp_pos;
	int		seq;
	int		select;
	int		pos_out;
	int		pos_in;
	size_t	end;
}	t_obj;

typedef struct s_str
{
	char	*push_str;
	char	*push_back_str;
	char	*rotate_str;
	char	*rev_str;
	char	*swap_str;
	char	*both_rotate_str;
	char	*both_rev_str;
}	t_str;

typedef struct s_node {
	size_t			val;
	size_t			len;
	struct s_node	*next;
}	t_node;

void	init_stacks(t_obj *a_stack, size_t n, char **arg);
void	error_and_exit(t_obj *data);
void	dealloc_arr(long **arr_1, long **arr_2);
void	alloc_init_arr(long **arr_1, long **arr_2, size_t n1, size_t n2);
void	add_elements_to_list(t_list **a_list, t_obj *a_stack, size_t n);
void	create_and_fill_list(t_obj *a_stack, size_t n);
void	rule_swap(t_list **node, t_list **node_2, int i, char *str);
void	rule_push(t_list **from_stack, t_list **to_stack, char *str);
void	rule_rotate(t_list **stack, char *str);
void	rule_reverse(t_list **stack, char *str);
void	set_lis_elements(t_list **a_list, size_t n);
int		stop_sorting(t_list **a_list, t_list **b_list);
t_list	*get_direction_list(t_list *a_list, t_list *tmp_list);
int		get_direction(int move);
void	separate_move(t_list **list, int dir, t_str *str);
void	sort_merge(long *arr, size_t left, size_t right);
void	presort_stack(t_obj *a_stack, size_t n);
int		check_order_and_continue(t_list *lst, int (f)(void *, void *));
int		compare_index(void *content_1, void *content_2);
int		find_min(t_list **list);
int		find_min_of_top_and_bottom(t_list **list);
int		compare_obj(void *content_1, void *content_2);
size_t	ft_putstr_with_count(char *s, int fd, int stop);
char	swap_or_rotate(t_list **list, int (comp_func)(t_list **));
t_list	*find_min_move_in_full_stack(t_list *list);
void	put_current_position(t_list *list);
void	reset_moves_and_pos(t_list *list);
void	calculate_moves(t_list *list);
void	rule(t_list **list, int (f1)(t_list **), int (f2)(t_list **), t_str s);
void	transfer_elements(t_list **list, t_list **to_list, t_str *str);
void	move_list(t_list **list, t_str str, size_t pos);
void	set_pos_after_transfer(t_list **list, t_list **to_list);
void	find_position(t_list *list, t_list *to_list, size_t size_y);
void	move_and_push_back(t_list **a_list, t_list **b_list, t_str *str);
void	find_zero_element(t_list **list, t_str str);
int		compare_incr_order(void *content_1, void *content_2);
void	put_new_pos_out_for_list_to_push(t_list *list);
void	put_current_position_in_a(t_list *list);
void	calculate_all_moves(t_list *a_list, t_list *b_list);
void	dealloc_list(t_list **list);
int		set_if_ok(int set_ok);
void	manage_instruction(int create, t_obj *a_stack, size_t n);
void	compare_and_exec_instr(char *instr, t_list **a_list, t_list **b_list);

#endif
