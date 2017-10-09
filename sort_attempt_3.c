/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_attempt_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 20:36:15 by esterna           #+#    #+#             */
/*   Updated: 2017/10/09 16:49:51 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				push_stk_optim_b(int debug, t_stack *a, t_stack *b)
{
	if (b->size > 0 && deref(b, 'h') < deref(b, 't')
			&& deref(a, 'h') > deref(a, 't'))
		execute(debug, "rr", a, b);
	else if (deref(a, 'h') > deref(a, 't'))
		execute(debug, "ra", a, b);
	if (b->size > 0 && deref(b, 'h') < deref(b, 't')
			&& deref(a, 'h') > deref(a, 't'))
		execute(debug, "rrr", a, b);
	else if (deref(a, 'h') > deref(a, 't'))
		execute(debug, "rra", a, b);
	if (a->size > 1 && deref(a, 'h') > deref(a, 'n') &&
			(b->size > 1 && deref(b, 'n') > deref(b, 'h')))
		execute(debug, "ss", a, b);
	else if (a->size > 1 && deref(a, 'h') > deref(a, 'n'))
		execute(debug, "sa", a, b);
}

void				push_back_b_stk(int debug, t_stack *a, t_stack *b)
{
	if (is_sorted(a) == 0)
		small_sort(debug, a, b);
	while (b->size > 0)
	{
		if (!(b->size > 1 && deref(b, 'n') > deref(b, 'h')))
		{
			execute(debug, "pa", a, b);
			push_stk_optim_b(debug, a, b);
		}
		else if (b->size > 1 && deref(b, 'n') > deref(b, 'h'))
		{
			execute(debug, "sb", a, b);
			if (deref(a, 'h') < deref(b, 'h'))
				execute(debug, "pb", a, b);
		}
		else
			execute(debug, "rb", a, b);
	}
}

void				push_stk_optim(int debug, t_stack *a, t_stack *b, int range)
{
	if (deref(b, 'h') < deref(b, 't') &&
			(a->size > 0 && deref(a, 'h') > range))
		execute(debug, "rr", a, b);
	else if (deref(b, 'h') < deref(b, 't'))
		execute(debug, "rb", a, b);
	if (deref(b, 'h') < deref(b, 't') && (a->size != 0 && deref(a, 't') <= range
		&& deref(a, 't') > deref(a, 'h')))
		execute(debug, "rrr", a, b);
	else if (deref(b, 'h') < deref(b, 't'))
		execute(debug, "rrb", a, b);
	if (b->size > 1 && deref(b, 'h') < deref(b, 'n') &&
			(a->size > 1 && deref(a, 'n') <= range
			&& deref(a, 'n') < deref(a, 'h')))
		execute(debug, "ss", a, b);
	else if (b->size > 1 && deref(b, 'h') < deref(b, 'n'))
		execute(debug, "sb", a, b);
}

static void			helper_func(int debug, int range, t_stack *a, t_stack *b)
{
	char		ch;

	ch = (search_stack(find_smallest(a), a) <= (a->size / 2)) ? 't' : 'b';
	if (a->size > 1 && deref(a, 'n') <= range
			&& deref(a, 'n') < deref(a, 'h'))
		execute(debug, "sa", a, b);
	else if (ch == 't')
		execute(debug, "ra", a, b);
	else
		execute(debug, "rra", a, b);
}

void				sort_attempt_3(int debug, t_stack *a, t_stack *b)
{
	int		range;
	int		n;
	int		i;

	while (a->size > 5)
	{
		i = 0;
		range = find_smallest(a) + std_dev_stk(a);
		n = in_range_occurrences(a, range);
		while (i < n)
		{
			if ((a->size > 0 && deref(a, 'h') <= range) && !(a->size > 1
				&& deref(a, 'n') <= range && deref(a, 'n') < deref(a, 'h')))
			{
				execute(debug, "pb", a, b);
				push_stk_optim(debug, a, b, range);
				i++;
			}
			else
				helper_func(debug, range, a, b);
		}
	}
}
