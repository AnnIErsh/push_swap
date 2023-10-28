/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 22:30:37 by annaershova       #+#    #+#             */
/*   Updated: 2023/10/09 22:33:49 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	get_moves(size_t moves, int get)
{
	static size_t	tmp_moves;

	if (get)
		return (tmp_moves);
	else
		tmp_moves = moves;
	return (tmp_moves);
}

void	moving(t_list **b, t_list **a, void (*f)(t_list **, char *), char *s)
{
	size_t	moves;

	moves = get_moves(0, 1);
	while (moves)
	{
		f(b, s);
		f(a, "");
		moves--;
	}
}

void	move_together(t_list **a_list, t_list **b_list, int b_in, int a_pos)
{
	size_t	moves;
	char	*str;
	void	(*f)(t_list **, char *);

	str = "";
	if (b_in < 0 && a_pos < 0)
	{
		b_in *= (-1);
		a_pos *= (-1);
		f = &rule_reverse;
		str = "rrr\n";
	}
	else if (b_in > 0 && a_pos > 0)
	{
		f = rule_rotate;
		str = "rr\n";
	}
	else
		return ;
	if (b_in > a_pos)
		moves = a_pos;
	else
		moves = b_in;
	get_moves(moves, 0);
	moving(b_list, a_list, f, str);
}

void	set_move(t_list **a_list, t_list **b_list, t_str *str, t_list *tmp_list)
{
	int		in;
	int		out;
	int		dir;
	t_list	*dir_list;

	dir_list = get_direction_list(*a_list, tmp_list);
	in = ((t_obj *)(tmp_list->content))->pos_in;
	out = ((t_obj *)(tmp_list->content))->pos_out;
	dir = ((t_obj *)(dir_list->content))->tmp_pos;
	move_together(a_list, b_list, in, dir);
	while (in != ((t_obj *)((*b_list)->content))->pos_in)
		separate_move(b_list, get_direction(in), str + 1);
	while (out != ((t_obj *)((*a_list)->content))->pos_in)
		separate_move(a_list, get_direction(dir), str);
}

void	move_and_push_back(t_list **a_list, t_list **b_list, t_str *str)
{
	t_list	*tmp_list;

	if (check_order_and_continue(*a_list, compare_index) && !*b_list)
		return ;
	put_current_position(*a_list);
	put_current_position_in_a(*a_list);
	put_current_position(*b_list);
	reset_moves_and_pos(*a_list);
	put_new_pos_out_for_list_to_push(*a_list);
	reset_moves_and_pos(*b_list);
	set_pos_after_transfer(a_list, b_list);
	calculate_all_moves(*a_list, *b_list);
	tmp_list = find_min_move_in_full_stack(*b_list);
	set_move(a_list, b_list, str, tmp_list);
	rule_push(b_list, a_list, (str + 1)->push_str);
	put_current_position(*a_list);
	put_current_position_in_a(*a_list);
	put_current_position(*b_list);
	reset_moves_and_pos(*a_list);
	put_new_pos_out_for_list_to_push(*a_list);
}
