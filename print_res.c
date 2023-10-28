/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 02:39:48 by annaershova       #+#    #+#             */
/*   Updated: 2023/10/09 22:59:39 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_putstr_with_count(char *s, int fd, int stop)
{
	static size_t	count;
	size_t			tmp;
	size_t			len;

	len = ft_strlen(s);
	write(fd, s, len);
	if (s && *s)
		count++;
	if (stop && count)
	{
		tmp = count - 1;
		count = 0;
		return (tmp);
	}
	return (count);
}

int	stop_sorting(t_list **a_list, t_list **b_list)
{
	if (!*b_list && !check_order_and_continue(*a_list, compare_index))
	{
		if (a_list)
			dealloc_list(a_list);
		set_if_ok(1);
		return (1);
	}
	return (0);
}
