/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_res_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 02:41:57 by annaershova       #+#    #+#             */
/*   Updated: 2023/10/09 23:00:56 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

void	get_and_check_instruction(t_list **a_list, t_list **b_list)
{
	char	*instr;

	instr = get_next_line(0);
	while (instr)
	{
		compare_and_exec_instr(instr, a_list, b_list);
		free(instr);
		instr = get_next_line(0);
	}
	stop_sorting(a_list, b_list);
}

void	manage_instruction(int create, t_obj *a_stack, size_t n)
{
	static t_list	*a_list;
	static t_list	*b_list;

	if (create == 1)
	{
		a_list = ft_lstnew(a_stack);
		b_list = NULL;
		add_elements_to_list(&a_list, a_stack, n);
		return ;
	}
	if (create == 2)
	{
		dealloc_list(&a_list);
		dealloc_list(&b_list);
		return ;
	}
	get_and_check_instruction(&a_list, &b_list);
}
