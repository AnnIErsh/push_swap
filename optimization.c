/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:07:28 by annaershova       #+#    #+#             */
/*   Updated: 2023/10/09 22:30:45 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order_and_continue(t_list *lst, int (f)(void *, void *))
{
	static int	res;
	int			tmp;

	if (!res && lst && lst->next)
	{
		res = f(lst->content, lst->next->content);
		lst = lst->next;
		return (check_order_and_continue(lst, f));
	}
	tmp = res;
	res = 0;
	return (tmp);
}

int	find_min(t_list **list)
{
	t_obj	*obj_1;
	t_obj	*obj_2;
	t_obj	*obj_last;

	if (ft_lstsize(*list) < 2)
		return (0);
	obj_1 = (t_obj *)(*list)->content;
	obj_2 = (t_obj *)((*list)->next)->content;
	obj_last = (t_obj *)ft_lstlast(*list)->content;
	if (obj_1->index < obj_2->index && obj_1->index < obj_last->index)
		return (1);
	if (obj_2->index < obj_1->index && obj_2->index < obj_last->index)
		return (2);
	else
		return (3);
}

int	find_min_of_top_and_bottom(t_list **list)
{
	t_obj	*obj_2;
	t_obj	*obj_last;

	if (ft_lstsize(*list) < 2)
		return (0);
	obj_2 = (t_obj *)(*list)->content;
	obj_last = (t_obj *)ft_lstlast(*list)->content;
	if (obj_2->index < obj_last->index)
		return (1);
	else
		return (3);
}

t_list	*find_min_move_in_full_stack(t_list *list)
{
	size_t	tmp_min;
	t_list	*tmp_list;

	if (list)
		tmp_min = ((t_obj *)(list->content))->moves;
	tmp_list = list;
	while (list)
	{
		if (((t_obj *)(list->content))->moves < tmp_min)
		{
			tmp_min = ((t_obj *)(list->content))->moves;
			tmp_list = list;
		}
		list = list->next;
	}
	return (tmp_list);
}

int	set_if_ok(int set_ok)
{
	static int	res;

	if (!res && set_ok)
		res = set_ok;
	return (res);
}
