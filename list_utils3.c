/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:59:48 by annaershova       #+#    #+#             */
/*   Updated: 2023/10/09 22:37:17 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	del_list(void *content)
{
	t_obj	*obj;

	obj = (t_obj *)content;
	obj->curr_pos = 0;
	obj->end = 0;
	obj->index = 0;
	obj->moves = 0;
	obj->pos_in = 0;
	obj->pos_out = 0;
	obj->select = 0;
	obj->seq = 0;
	obj->tmp_pos = 0;
	obj->value = 0;
}

void	dealloc_list(t_list **list)
{
	ft_lstclear(list, del_list);
	*list = NULL;
}

void	move_list(t_list **list, t_str str, size_t pos)
{
	size_t	size;

	size = (size_t)ft_lstsize(*list) / 2;
	if (pos <= size)
	{
		while (((t_obj *)(*list)->content)->index)
			rule_rotate(list, str.rotate_str);
	}
	else
	{
		while (((t_obj *)(*list)->content)->index)
			rule_reverse(list, str.rev_str);
	}
	put_current_position(*list);
}

void	find_zero_element(t_list **list, t_str str)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (!((t_obj *)tmp->content)->index)
		{
			move_list(list, str, ((t_obj *)tmp->content)->curr_pos);
			break ;
		}
		tmp = tmp->next;
	}
}

void	set_pos_after_transfer(t_list **list, t_list **to_list)
{
	t_list	*tmp;

	tmp = *to_list;
	while (tmp)
	{
		find_position(*list, tmp, ft_lstsize(*to_list));
		tmp = tmp->next;
	}
}
