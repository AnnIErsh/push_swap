/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:15:42 by annaershova       #+#    #+#             */
/*   Updated: 2023/10/10 19:44:04 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_obj	*a;
	char	*str;

	if (argc >= 2 && argv)
	{
		a = ft_calloc(argc, sizeof(t_obj));
		if (!a)
			return (0);
		str = *(argv + 1);
		if (str && !*str)
			error_and_exit(a);
		init_stacks(a, argc - 1, argv);
		manage_instruction(1, a, argc - 1);
		manage_instruction(0, NULL, 0);
		if (!set_if_ok(0))
			ft_putstr_fd("KO\n", 1);
		else
			ft_putstr_fd("OK\n", 1);
		manage_instruction(2, NULL, 0);
		free(a);
	}
	return (0);
}
