/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 19:04:10 by esterna           #+#    #+#             */
/*   Updated: 2017/10/09 15:03:16 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					main(int argc, char **argv)
{
	int			debug;
	t_stack		*a;
	t_stack		*b;

	if (argc == 1)
		return (0);
	debug = (ft_strcmp(*(argv + 1), "-v") == 0) ? 3 : 2;
	a = init_stack();
	b = init_stack();
	if (setup_stacks(argc - 1, argv + 1, a) == 0)
	{
		stk_del(a, b);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (1 < a->size && a->size <= 5)
		small_sort(debug, a, b);
	while (is_sorted(a) == 0)
		sort_attempt_3(debug, a, b, std_deviation_stk(a));
	stk_del(a, b);
	return (0);
}
