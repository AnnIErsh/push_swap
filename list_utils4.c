/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:14:39 by annaershova       #+#    #+#             */
/*   Updated: 2023/10/10 19:09:44 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_temp_arr(long **arr, t_list *tmp_list, size_t size)
{
	size_t	i;

	i = 0;
	while (tmp_list && i < size)
	{
		*(*arr + i) = ((t_obj *)(tmp_list->content))->index;
		tmp_list = tmp_list->next;
		i++;
	}
}

static void	set_new_pos(long *arr, t_list *tmp_list, size_t size)
{
	size_t	i;

	while (tmp_list)
	{
		i = 0;
		while (i < size)
		{
			if (*(arr + i) == (long)((t_obj *)(tmp_list->content))->index)
			{
				if (i > size / 2)
					((t_obj *)(tmp_list->content))->pos_in = (size - i) * (-1);
				else
					((t_obj *)(tmp_list->content))->pos_in = i;
				break ;
			}
			i++;
		}
		tmp_list = tmp_list->next;
	}
}

void	put_new_pos_out_for_list_to_push(t_list *list)
{
	long	*arr;
	size_t	size;

	arr = ft_calloc(ft_lstsize(list), sizeof(long));
	if (!arr)
		return ;
	size = ft_lstsize(list);
	fill_temp_arr(&arr, list, size);
	sort_merge(arr, 0, size - 1);
	set_new_pos(arr, list, size);
	free(arr);
}

void	find_position(t_list *list, t_list *to_list, size_t size_y)
{
	size_t	count_from_top;
	size_t	count_from_bottom;
	size_t	curr_pos;

	count_from_top = 0;
	count_from_bottom = 0;
	while (list)
	{
		if (!compare_obj(to_list->content, list->content))
			count_from_bottom++;
		else
			count_from_top++;
		list = list->next;
	}
	curr_pos = ((t_obj *)(to_list->content))->curr_pos;
	if (count_from_top > count_from_bottom)
		((t_obj *)(to_list->content))->pos_out = count_from_bottom * (-1);
	else
		((t_obj *)(to_list->content))->pos_out = count_from_top;
	if (curr_pos > size_y / 2)
		((t_obj *)(to_list->content))->pos_in = curr_pos - size_y;
	else
		((t_obj *)(to_list->content))->pos_in = curr_pos;
}

char	swap_or_rotate(t_list **list, int (comp_func)(t_list **))
{
	if (!*list || ft_lstsize(*list) < 3)
		return ('-');
	if (comp_func(list) == 1)
		return ('s');
	if (comp_func(list) == 3)
		return ('r');
	return ('-');
}
