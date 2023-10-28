/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:54:34 by annaershova       #+#    #+#             */
/*   Updated: 2023/10/06 22:06:36 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	common_moves(int in, int tmp_pos)
{
	size_t	res;

	res = 0;
	if ((tmp_pos < 0 && in < 0) || (tmp_pos > 0 && in > 0))
	{
		if (tmp_pos < 0 && in < 0)
		{
			tmp_pos *= (-1);
			in *= (-1);
		}
		if (tmp_pos > in)
			res = in;
		else
			res = tmp_pos;
	}
	return (res);
}

static void	check_pos(t_list *b_list, int tmp_pos, int in, int together)
{
	if (tmp_pos < 0)
		tmp_pos *= (-1);
	if (in < 0)
		in *= (-1);
	((t_obj *)(b_list->content))->moves = tmp_pos + in - together;
}

void	calculate_all_moves(t_list *a_list, t_list *b_list)
{
	int		in;
	int		out;
	int		tmp_pos;
	t_list	*tmp_list;
	size_t	together;

	together = 0;
	while (b_list)
	{
		in = ((t_obj *)(b_list->content))->pos_in;
		out = ((t_obj *)(b_list->content))->pos_out;
		tmp_list = a_list;
		while (tmp_list)
		{
			if (out == ((t_obj *)(tmp_list->content))->pos_in)
			{
				tmp_pos = ((t_obj *)(tmp_list->content))->tmp_pos;
				together = common_moves(in, tmp_pos);
				check_pos(b_list, tmp_pos, in, together);
				break ;
			}
			tmp_list = tmp_list->next;
		}
		b_list = b_list->next;
	}
}
