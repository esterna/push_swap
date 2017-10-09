/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_attempt_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 20:36:15 by esterna           #+#    #+#             */
/*   Updated: 2017/10/06 23:49:43 by esterna          ###   ########.fr       */
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

void				sort_attempt_3(int debug, t_stack *a, t_stack *b, int dev)
{
	int		range;
	int		n;
	int		i;
	char	ch;

	while (a->size > 5)
	{
		i = 0;
		range = find_smallest(a) + dev;
		n = in_range_occurrences(a, range);
		while (i < n)
		{
			ch = (search_stack(find_smallest(a), a) <= (a->size / 2)) ? 't' : 'b';
			if ((a->size > 0 && deref(a, 'h') <= range) && !(a->size > 1
				&& deref(a, 'n') <= range && deref(a, 'n') < deref(a, 'h')))
			{
				execute(debug, "pb", a, b);
				push_stk_optim(debug, a, b, range);
				i++;
			}
			else if (a->size > 1 && deref(a, 'n') <= range
					&& deref(a, 'n') < deref(a, 'h'))
				execute(debug, "sa", a, b);
			else if (ch == 't')
				execute(debug, "ra", a, b);
			else
				execute(debug, "rra", a, b);
		}
	}
}
