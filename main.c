/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:00:11 by annaershova       #+#    #+#             */
/*   Updated: 2023/10/10 19:07:51 by annaershova      ###   ########.fr       */
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
		create_and_fill_list(a, argc - 1);
		free(a);
	}
	return (0);
}
