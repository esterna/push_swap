/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 19:04:10 by esterna           #+#    #+#             */
/*   Updated: 2017/10/09 16:31:15 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					search_stack(int n, t_stack *stack)
{
	t_list		*curr;
	int			check;
	int			p;

	p = 0;
	curr = stack->head;
	while (curr != NULL)
	{
		if ((check = *((int *)curr->content)) == n)
			return (p);
		p++;
		curr = curr->next;
	}
	return (-1);
}

void				small_sort(int debug, t_stack *a, t_stack *b)
{
	int		n;

	if ((n = a->size) <= 2)
	{
		execute(debug, "sa", a, b);
		return ;
	}
	while (a->size != n || is_sorted(a) != 1)
	{
		if (a->size > 1 && deref(a, 'h') > deref(a, 't'))
			execute(debug, "ra", a, b);
		else if (a->size > 1 && deref(a, 'h') > deref(a, 'n'))
			execute(debug, "sa", a, b);
		else if (a->size > 0 && (b->size == 0 ||
				deref(a, 'h') > deref(b, 'h')))
			execute(debug, "pb", a, b);
		else
			execute(debug, "pb", a, b);
		if (b->size > 0 && deref(b, 'h') < deref(b, 't'))
			execute(debug, "rb", a, b);
		else if (b->size > 1 && deref(b, 'h') < deref(b, 'n'))
			execute(debug, "sb", a, b);
		while (is_sorted(a) == 1 && a->size != n)
			execute(debug, "pa", a, b);
	}
}

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
	{
		sort_attempt_3(debug, a, b);
		push_back_b_stk(debug, a, b);
	}
	stk_del(a, b);
	return (0);
}
