/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:23:30 by annaershova       #+#    #+#             */
/*   Updated: 2023/10/09 22:28:53 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rule_swap(t_list **node, t_list **node_2, int i, char *str)
{
	t_list	*tmp;

	if (!i || !*node || !*node_2)
	{
		ft_putstr_with_count(str, 1, 0);
		return ;
	}
	tmp = *node;
	*node = *node_2;
	*node_2 = tmp;
	i--;
	rule_swap(&(*node)->next, &(*node_2)->next, i, str);
}

static t_list	*get_first_node_and_pop(t_list **stack)
{
	t_list	*tmp;
	t_list	*new_node;

	if (!*stack)
		return (NULL);
	tmp = *stack;
	new_node = ft_lstnew(tmp->content);
	*stack = (*stack)->next;
	free(tmp);
	tmp = NULL;
	return (new_node);
}

void	rule_push(t_list **from_stack, t_list **to_stack, char *str)
{
	t_list	*tmp;

	if (*from_stack)
	{
		tmp = *from_stack;
		*from_stack = (*from_stack)->next;
		ft_lstadd_front(to_stack, ft_lstnew(tmp->content));
		free(tmp);
		tmp = NULL;
		ft_putstr_with_count(str, 1, 0);
	}
}

void	rule_rotate(t_list **stack, char *str)
{
	t_list	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = get_first_node_and_pop(stack);
	ft_lstadd_back(stack, tmp);
	ft_putstr_with_count(str, 1, 0);
}

void	rule_reverse(t_list **stack, char *str)
{
	t_list	*tmp;
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	ft_lstadd_front(stack, ft_lstnew(last->content));
	tmp->next = NULL;
	free(last);
	last = NULL;
	ft_putstr_with_count(str, 1, 0);
}
