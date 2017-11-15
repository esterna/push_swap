/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 19:04:10 by esterna           #+#    #+#             */
/*   Updated: 2017/11/14 22:59:57 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					(*g_sort_method[5])(int debug, t_stack *a, t_stack *b) =
{
		[0] = small_sort,
		[1] = rotate_sort,
		[2] = rev_rotate_sort,
		[3] = insertion_sort,
		[4] = merge_sort_stk
};

int					main(int argc, char **argv)
{
	int			debug;
	t_stack		*a;
	t_stack		*b;
	int			sort_method;

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
	else
	{
		sort_method = 4;//find_sort(a, 0);
	//	ft_printf("\n%d\n\n", sort_method);
		(g_sort_method[sort_method])(debug, a, b);
	}
	stk_del(a, b);
	return (0);
}
