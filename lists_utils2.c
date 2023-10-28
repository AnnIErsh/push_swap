/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:22:33 by aershova          #+#    #+#             */
/*   Updated: 2023/10/06 22:41:40 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_seq_order(t_list *list)
{
	size_t	curr_pos;

	while (list)
	{
		if (!((t_obj *)(list->content))->select)
		{
			curr_pos = ((t_obj *)(list->content))->curr_pos;
			if (curr_pos < (size_t)ft_lstsize(list) / 2)
				return (0);
			else
				return (-1);
		}
		list = list->next;
	}
	return (1);
}

void	transfer_elements(t_list **list, t_list **to_list, t_str *str)
{
	while (ft_lstsize(*list))
	{
		if (!((t_obj *)(*list)->content)->select)
			rule_push(list, to_list, str->push_str);
		else
		{
			if (!check_seq_order(*list))
				rule_rotate(list, str->rotate_str);
			else if (check_seq_order(*list) == -1)
				rule_reverse(list, str->rev_str);
			else
				break ;
		}
		put_current_position(*list);
	}
}

void	separate_move(t_list **list, int dir, t_str *str)
{
	void	(*f)(t_list **, char *);
	char	*tmp_str;

	f = NULL;
	tmp_str = NULL;
	if (dir > 0)
	{
		f = &rule_rotate;
		tmp_str = str->rotate_str;
	}
	else if (dir < 0)
	{
		f = &rule_reverse;
		tmp_str = str->rev_str;
	}
	f(list, tmp_str);
}

int	get_direction(int move)
{
	if (move > 0)
		return (1);
	else if (move < 0)
		return (-1);
	return (0);
}

t_list	*get_direction_list(t_list *a_list, t_list *tmp_list)
{
	int	pos_out;
	int	pos_in;

	while (a_list)
	{
		pos_out = ((t_obj *)(tmp_list->content))->pos_out;
		pos_in = ((t_obj *)(a_list->content))->pos_in;
		if (pos_out == pos_in)
			break ;
		a_list = a_list->next;
	}
	return (a_list);
}
