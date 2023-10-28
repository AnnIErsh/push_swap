/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:08:48 by annaershova       #+#    #+#             */
/*   Updated: 2023/10/06 19:27:43 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_current_position(t_list *list)
{
	size_t	i;

	i = 0;
	while ((size_t)ft_lstsize(list))
	{
		((t_obj *)(list->content))->curr_pos = i;
		list = list->next;
		i++;
	}
}

void	put_current_position_in_a(t_list *list)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_lstsize(list);
	while (list)
	{
		if (i > size / 2)
			((t_obj *)(list->content))->tmp_pos = (size - i) * (-1);
		else
			((t_obj *)(list->content))->tmp_pos = i;
		((t_obj *)(list->content))->curr_pos = i;
		list = list->next;
		i++;
	}
}

void	reset_moves_and_pos(t_list *list)
{
	size_t	i;

	i = 0;
	if (!list)
		return ;
	while (list && list->next)
	{
		((t_obj *)(list->content))->moves = 0;
		((t_obj *)(list->content))->curr_pos = i;
		((t_obj *)(list->content))->end = 0;
		((t_obj *)(list->content))->pos_in = 0;
		((t_obj *)(list->content))->pos_out = 0;
		list = list->next;
		i++;
	}
	((t_obj *)(list->content))->moves = 0;
	((t_obj *)(list->content))->end = 1;
	((t_obj *)(list->content))->curr_pos = i;
}

void	rule(t_list **list, int (f1)(t_list **), int (f2)(t_list **), t_str str)
{
	size_t	index;
	size_t	index_next;

	if (!list || !(*list)->next)
		return ;
	if (f1(list) == 2)
	{
		if (swap_or_rotate(list, f2) == 's')
			rule_swap(list, &(*list)->next, 2, str.swap_str);
		else if (swap_or_rotate(list, f2) == 'r')
			rule_rotate(list, str.rotate_str);
	}
	else if (f1(list) == 3)
	{
		index = ((t_obj *)((*list)->content))->index;
		index_next = ((t_obj *)((*list)->next->content))->index;
		if (index > index_next)
			rule_swap(list, &(*list)->next, 2, str.swap_str);
		rule_reverse(list, str.rev_str);
	}
}

void	calculate_moves(t_list *list)
{
	int	x_tmp;
	int	y_tmp;

	if (ft_lstsize(list) && check_order_and_continue(list, compare_index))
	{
		while (list)
		{
			x_tmp = ((t_obj *)(list->content))->pos_out;
			if (x_tmp < 0)
				x_tmp *= (-1);
			y_tmp = ((t_obj *)(list->content))->pos_in;
			if (y_tmp < 0)
				y_tmp *= (-1);
			((t_obj *)(list->content))->moves = x_tmp + y_tmp;
			list = list->next;
		}
	}
}
