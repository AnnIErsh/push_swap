/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 23:03:10 by annaershova       #+#    #+#             */
/*   Updated: 2023/10/06 23:04:04 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_index(void *content_1, void *content_2)
{
	t_obj	*tmp_1;
	t_obj	*tmp_2;

	tmp_1 = (t_obj *)content_1;
	tmp_2 = (t_obj *)content_2;
	if (tmp_1->index + 1 == tmp_2->index)
		return (0);
	return (1);
}

int	compare_incr_order(void *content_1, void *content_2)
{
	t_obj	*tmp_1;
	t_obj	*tmp_2;

	tmp_1 = (t_obj *)content_1;
	tmp_2 = (t_obj *)content_2;
	if (tmp_1->index < tmp_2->index)
		return (0);
	return (1);
}

int	compare_obj(void *content_1, void *content_2)
{
	t_obj	*tmp_1;
	t_obj	*tmp_2;

	tmp_1 = (t_obj *)content_1;
	tmp_2 = (t_obj *)content_2;
	if (tmp_1->index > tmp_2->index)
		return (1);
	return (0);
}
