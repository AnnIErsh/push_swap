/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 01:04:16 by annaershova       #+#    #+#             */
/*   Updated: 2023/10/09 23:36:52 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_str_to_list(t_str *str)
{
	t_str	str_a;
	t_str	str_b;

	str_a.push_str = "pb\n";
	str_a.push_back_str = "pa\n";
	str_a.swap_str = "sa\n";
	str_a.rotate_str = "ra\n";
	str_a.rev_str = "rra\n";
	str_a.both_rotate_str = "rr\n";
	str_a.both_rev_str = "rrr\n";
	str_b.push_str = "pa\n";
	str_b.push_back_str = "pb\n";
	str_b.swap_str = "sb\n";
	str_b.rotate_str = "rb\n";
	str_b.rev_str = "rrb\n";
	str_b.both_rotate_str = "rr\n";
	str_b.both_rev_str = "rrr\n";
	*str = str_a;
	*(str + 1) = str_b;
}

void	add_elements_to_list(t_list **a_list, t_obj *a_stack, size_t n)
{
	size_t	i;

	i = 1;
	while (i < n)
	{
		ft_lstadd_back(a_list, ft_lstnew(a_stack + i));
		i++;
	}
}

void	case_two_three_or_five(t_list **a_list, t_list **b_list, t_str *str)
{
	if (ft_lstsize(*a_list) == 2)
	{
		if (compare_obj((*a_list)->content, &((*a_list)->next)->content))
			rule_rotate(a_list, str->rotate_str);
		return ;
	}
	if (ft_lstsize(*a_list) == 5)
	{
		rule_push(a_list, b_list, str->push_str);
		rule_push(a_list, b_list, str->push_str);
	}
	if (ft_lstsize(*a_list) == 3)
	{
		rule(a_list, find_min, find_min_of_top_and_bottom, *str);
		while (check_order_and_continue(*a_list, compare_incr_order))
		{
			rule(a_list, find_min, find_min_of_top_and_bottom, *str);
			rule_reverse(a_list, str->rev_str);
			rule_swap(a_list, &((*a_list)->next), 2, str->swap_str);
		}
	}
}

static void	do_and_dealloc(t_list **a_list, t_list **b_list, t_str *str)
{
	put_current_position(*a_list);
	put_current_position(*b_list);
	put_current_position_in_a(*a_list);
	reset_moves_and_pos(*a_list);
	put_new_pos_out_for_list_to_push(*a_list);
	reset_moves_and_pos(*b_list);
	set_pos_after_transfer(a_list, b_list);
	calculate_all_moves(*a_list, *b_list);
	while (*b_list)
		move_and_push_back(a_list, b_list, str);
	find_zero_element(a_list, *str);
	dealloc_list(a_list);
	dealloc_list(b_list);
}

void	create_and_fill_list(t_obj *a_stack, size_t n)
{
	t_list	*a_list;
	t_list	*b_list;
	t_str	str[2];

	a_list = ft_lstnew(a_stack);
	b_list = NULL;
	set_str_to_list(str);
	add_elements_to_list(&a_list, a_stack, n);
	if (a_list)
	{
		if (stop_sorting(&a_list, &b_list))
			return ;
		case_two_three_or_five(&a_list, &b_list, str);
		if (stop_sorting(&a_list, &b_list))
			return ;
	}
	set_lis_elements(&a_list, n);
	put_current_position(a_list);
	put_current_position(b_list);
	set_pos_after_transfer(&a_list, &b_list);
	if (stop_sorting(&a_list, &b_list))
		return ;
	else
		transfer_elements(&a_list, &b_list, str);
	do_and_dealloc(&a_list, &b_list, str);
}
/*
---tmp printing funcs---
void	print_list(void *content)
{
	t_obj *obj = (t_obj*)content;
	printf("content: %ld ", obj->value);
	printf("select: %d ", obj->select);
	printf("seq_el: %d ", obj->seq);
	printf("end: %lu ", obj->end);
	printf("pos: %lu ", obj->curr_pos);
	printf("tmp_pose: %d ", obj->tmp_pos);
	printf("moves: %lu ", obj->moves);
	printf("pos_out: %d ", obj->pos_out);
	printf("pos_in: %d ", obj->pos_in);
	printf("index: %lu\n", obj->index);
}

	printf("total a:\n");
	ft_lstiter(a_list, print_list);
	printf("total b:\n");
	ft_lstiter(b_list, print_list);

	size_t count = ft_putstr_with_count("end", 1, 1);
	printf("wc -l: %lu\n", count);
*/
