/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_alg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:35:44 by annaershova       #+#    #+#             */
/*   Updated: 2023/10/10 19:04:32 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	search_lis(size_t size, t_node **node, t_node **tmp)
{
	size_t	i;

	i = size;
	while (i--)
	{
		*tmp = *node + i;
		while ((*tmp)++ < *node + size)
		{
			if ((*tmp)->val > (*node + i)->val
				&& (*tmp)->len >= (*node + i)->len)
			{
				(*node + i)->next = *tmp;
				(*node + i)->len = (*tmp)->len + 1;
			}
		}
	}
	i = 0;
	*tmp = *node;
	while (i < size)
	{
		if ((*node + i)->len > (*tmp)->len)
			*tmp = *node + i;
		i++;
	}
}

static void	set_lis_in_list(t_list *list, t_node *tmp)
{
	while (tmp && list)
	{
		while (list)
		{
			if (((t_obj *)(list->content))->index == tmp->val)
			{
				((t_obj *)(list->content))->select = 1;
				break ;
			}
			list = list->next;
		}
		tmp = tmp->next;
	}
}

static void	large_inc_seq(size_t *arr, size_t size, t_list *list)
{
	size_t	i;
	t_node	*tmp;
	t_node	*node;

	i = 0;
	node = ft_calloc(size, sizeof(*node));
	if (!node)
		return ;
	while (i < size)
	{
		(node + i)->val = *(arr + i);
		i++;
	}
	search_lis(size, &node, &tmp);
	set_lis_in_list(list, tmp);
	free(node);
}

void	set_lis_elements(t_list **a_list, size_t n)
{
	t_list	*tmp_list;
	size_t	*arr;
	size_t	i;

	i = 0;
	arr = ft_calloc(n, sizeof(size_t));
	if (!arr)
		return ;
	tmp_list = *a_list;
	while (tmp_list && i < n)
	{
		*(arr + i) = ((t_obj *)(tmp_list->content))->index;
		tmp_list = tmp_list->next;
		i++;
	}
	large_inc_seq(arr, n, *a_list);
	free(arr);
}
