/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort_part2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 22:19:48 by annaershova       #+#    #+#             */
/*   Updated: 2023/10/10 19:09:02 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_index(t_obj **obj, long *arr, size_t n)
{
	size_t	i;
	size_t	j;
	t_obj	*tmp;

	i = 0;
	while (i < n)
	{
		tmp = *obj + i;
		j = 0;
		while (j < n)
		{
			if (tmp->value == *(arr + j))
			{
				tmp->index = j;
				tmp->moves = 0;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	presort_stack(t_obj *a_stack, size_t n)
{
	size_t	i;
	long	*arr;

	i = 0;
	arr = ft_calloc(n, sizeof(long));
	if (!arr)
		return ;
	while (i < n)
	{
		*(arr + i) = (*(a_stack + i)).value;
		i++;
	}
	sort_merge(arr, 0, n - 1);
	set_index(&a_stack, arr, n);
	free(arr);
}

void	alloc_init_arr(long **arr_1, long **arr_2, size_t n1, size_t n2)
{
	*arr_1 = ft_calloc(n1, sizeof(long));
	*arr_2 = ft_calloc(n2, sizeof(long));
	if (!*arr_1 || !*arr_2)
		return ;
}

void	dealloc_arr(long **arr_1, long **arr_2)
{
	free(*arr_1);
	free(*arr_2);
}
