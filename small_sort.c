/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 16:51:57 by esterna           #+#    #+#             */
/*   Updated: 2017/10/09 16:52:25 by esterna          ###   ########.fr       */
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
