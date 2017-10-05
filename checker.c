/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 16:58:52 by esterna           #+#    #+#             */
/*   Updated: 2017/10/04 15:56:20 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					main(int argc, char **argv)
{
	char		*line;
	t_stack		*a;
	t_stack		*b;
	int			debug;

	line = NULL;
	if (argc == 1)
		return (0);
	debug = (ft_strcmp(*(argv + 1), "-v") == 0) ? 1 : 0;
	a = init_stack();
	b = init_stack();
	if (setup_stacks(argc - 1, argv + 1, a) == 0)
		return (0);
	while (get_next_line(0, &line) > 0)
		execute(debug, line, a, b, 0);
	if (is_sorted(a) == 1 && b->size == 0)
		ft_putstr("OK\n");
	else
	{
		ft_putstr("KO\n");
		ft_lstdel(&(b->head), ft_bzero);
	}
	free(line);
	ft_lstdel(&(a->head), ft_bzero);
	free(a);
	free(b);
	return (0);
}
