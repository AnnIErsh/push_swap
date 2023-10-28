/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:07:04 by annaershova       #+#    #+#             */
/*   Updated: 2023/10/09 20:11:10 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_and_exit(t_obj *data)
{
	if (data)
		free(data);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static void	check_errors(char *str, long number, t_obj *data)
{
	char	*tmp;

	tmp = str;
	if (tmp && (*tmp == '-' || *tmp == '+'))
		tmp++;
	while (tmp && *tmp)
	{
		if (ft_isdigit(*tmp))
			tmp++;
		else
			error_and_exit(data);
	}
	if (number == 0 && ft_strncmp("0", str, ft_strlen(str)))
		error_and_exit(data);
	if (number > 2147483647 || number < -2147483648)
		error_and_exit(data);
}

static void	find_duplicates(t_obj *a_stack, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if ((*(a_stack + i)).value == (*(a_stack + j)).value)
				error_and_exit(a_stack);
			j++;
		}
		i++;
	}
}

void	init_stacks(t_obj *a_stack, size_t n, char **arg)
{
	char	*str;
	long	number;
	size_t	i;

	i = 0;
	while (i < n)
	{
		str = *(arg + i + 1);
		number = ft_atoi(str);
		check_errors(str, number, a_stack);
		(*(a_stack + i)).value = number;
		(*(a_stack + i)).curr_pos = i;
		(*(a_stack + i)).seq = 0;
		(*(a_stack + i)).select = 0;
		(*(a_stack + i)).pos_out = 0;
		(*(a_stack + i)).pos_in = 0;
		(*(a_stack + i)).end = 0;
		(*(a_stack + i)).tmp_pos = 0;
		i++;
	}
	find_duplicates(a_stack, n);
	presort_stack(a_stack, n);
}
