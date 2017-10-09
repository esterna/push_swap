/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 23:50:24 by esterna           #+#    #+#             */
/*   Updated: 2017/10/07 00:30:31 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (b->size > 1 && deref(b, 'n') > deref(b, 'h'))
		{
			execute(debug, "sb", a, b);
			if (deref(a, 'h') < deref(b, 'h'))
				execute(debug, "pb", a, b);
		}
		else
		{
			execute(debug, "pa", a, b);
			push_stk_optim_b(debug, a, b);
		}
	}
}

void				push_stk_optim(int debug, t_stack *a, t_stack *b)
{
	if (deref(b, 'h') < deref(b, 't') && deref(a, 'h') < deref(a, 't'))
		execute(debug, "rr", a, b);
	else if (deref(b, 'h') < deref(b, 't'))
		execute(debug, "rb", a, b);
	if (deref(b, 'h') < deref(b, 't') && deref(a, 'h') > deref(a, 't'))
		execute(debug, "rrr", a, b);
	else if (deref(b, 'h') < deref(b, 't'))
		execute(debug, "rrb", a, b);
	if (a->size > 1 && b->size > 1 && deref(b, 'h') < deref(b, 'n') &&
			deref(a, 'n') < deref(a, 'h'))
		execute(debug, "ss", a, b);
	else if (b->size > 1 && deref(b, 'h') < deref(b, 'n'))
		execute(debug, "sb", a, b);
}

void				sort_stk(int debug, t_stack *a, t_stack *b)
{
	int ugh, geez;
	while (a->size > 5 && is_sorted(a) == 0)
	{
		if (deref(a, 'h') > deref(a, 't'))
			execute(debug, "rra", a, b);
		else if (deref(a, 'n') < deref(a, 'h'))
			execute(debug, "sa", a, b);
		else if ((ugh = deref(a, 'h')) > (geez = deref(a, 't')))
			execute(debug, "ra", a, b);
		else
		{
			execute(debug, "pb", a, b);
			push_stk_optim(debug, a, b);
		}
	}
	push_back_b_stk(debug, a, b);
}
