/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:00:26 by annaershova       #+#    #+#             */
/*   Updated: 2023/10/09 23:01:06 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rule_rr_rrr(t_list **a, t_list **b, void (f)(t_list **, char *))
{
	f(a, "");
	f(b, "");
}

void	ss(t_list **a, t_list **b, void (f)(t_list **, t_list **, int, char *))
{
	f(a, &(*a)->next, 2, "");
	f(b, &(*b)->next, 2, "");
}

void	rule_error(t_list **a_list, t_list **b_list)
{
	ft_putstr_fd("Error\n", 2);
	dealloc_list(a_list);
	dealloc_list(b_list);
	exit(1);
}

void	compare_and_exec_instr(char *instr, t_list **a_list, t_list **b_list)
{
	if (!ft_strncmp(instr, "pb\n", 3))
		rule_push(a_list, b_list, "");
	else if (!ft_strncmp(instr, "pa\n", 3))
		rule_push(b_list, a_list, "");
	else if (!ft_strncmp(instr, "sa\n", 3))
		rule_swap(a_list, &(*a_list)->next, 2, "");
	else if (!ft_strncmp(instr, "sb\n", 3))
		rule_swap(b_list, &(*b_list)->next, 2, "");
	else if (!ft_strncmp(instr, "ss\n", 3))
		ss(a_list, b_list, rule_swap);
	else if (!ft_strncmp(instr, "ra\n", 3))
		rule_rotate(a_list, "");
	else if (!ft_strncmp(instr, "rb\n", 3))
		rule_rotate(b_list, "");
	else if (!ft_strncmp(instr, "rr\n", 3))
		rule_rr_rrr(a_list, b_list, rule_rotate);
	else if (!ft_strncmp(instr, "rra\n", 4))
		rule_reverse(a_list, "");
	else if (!ft_strncmp(instr, "rrb\n", 4))
		rule_reverse(b_list, "");
	else if (!ft_strncmp(instr, "rrr\n", 4))
		rule_rr_rrr(a_list, b_list, rule_reverse);
	else
		rule_error(a_list, b_list);
}
