/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 16:58:52 by esterna           #+#    #+#             */
/*   Updated: 2017/10/06 21:18:01 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			result(int n, t_stack *a, t_stack *b)
{
	if (n == 1 && is_sorted(a) == 1 && b->size == 0)
		ft_putstr("OK\n");
	else if (n == 1)
		ft_putstr("KO\n");
}

int					main(int argc, char **argv)
{
	char		*line;
	t_stack		*a;
	t_stack		*b;
	int			debug;
	int			n;

	n = 1;
	line = NULL;
	if (argc == 1)
		return (0);
	debug = (ft_strcmp(*(argv + 1), "-v") == 0) ? 1 : 0;
	a = init_stack();
	b = init_stack();
	if (setup_stacks(argc - 1, argv + 1, a) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	while (n == 1 && get_next_line(0, &line) > 0)
	{
		n = execute(debug, line, a, b);
		ft_strdel(&line);
	}
	result(n, a, b);
	free(line);
	stk_del(a, b);
	return (0);
}
