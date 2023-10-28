/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:02:28 by annaershova       #+#    #+#             */
/*   Updated: 2023/10/06 01:23:35 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_half_array(long *arr, long *half_arr, size_t size, size_t edge)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		*(half_arr + i) = *(arr + edge + i);
		i++;
	}
}

static void	restore_array(long *arr, long *half_arr, size_t *i, size_t merged_i)
{
	*(arr + merged_i) = *(half_arr + *i);
	(*i)++;
}

static void	fill_arr_rest(long *arr, long *half_arr, size_t *i, size_t *merged)
{
	*(arr + *merged) = *(half_arr + *i);
	(*i)++;
	(*merged)++;
}

void	merge_parts(long *arr, size_t left, size_t mid, size_t right)
{
	size_t	i;
	size_t	j;
	size_t	merged_index;
	long	*arr_1;
	long	*arr_2;

	alloc_init_arr(&arr_1, &arr_2, mid - left + 1, right - mid);
	fill_half_array(arr, arr_1, mid - left + 1, left);
	fill_half_array(arr, arr_2, right - mid, mid + 1);
	i = 0;
	j = 0;
	merged_index = left;
	while (i < mid - left + 1 && j < right - mid)
	{
		if (*(arr_1 + i) < *(arr_2 + j))
			restore_array(arr, arr_1, &i, merged_index);
		else
			restore_array(arr, arr_2, &j, merged_index);
		merged_index++;
	}
	while (i < mid - left + 1)
		fill_arr_rest(arr, arr_1, &i, &merged_index);
	while (j < right - mid)
		fill_arr_rest(arr, arr_2, &j, &merged_index);
	dealloc_arr(&arr_1, &arr_2);
}

void	sort_merge(long *arr, size_t left, size_t right)
{
	long	mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;
		sort_merge(arr, left, mid);
		sort_merge(arr, mid + 1, right);
		merge_parts(arr, left, mid, right);
	}
}
