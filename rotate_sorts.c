/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_sorts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:20:22 by esterna           #+#    #+#             */
/*   Updated: 2017/11/14 23:05:56 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					rotate_sort(int debug, t_stack *a, t_stack *b)
{
	int		i;
	int		n;

	i = a->size + 1;
	n = 0;
	while (is_sorted(a) == 0 && b->size == 0 && i > 0)
	{
		execute(debug, "ra", a, b);
		i--;
		n++;
	}
	return (is_sorted(a) == 1 ? n : INT_MAX);
}

int					rev_rotate_sort(int debug, t_stack *a, t_stack *b)
{
	int		i;
	int		n;

	i = a->size + 1;
	n = 0;
	while (is_sorted(a) == 0 && b->size == 0 && i > 0)
	{
		execute(debug, "rra", a, b);
		i--;
		n++;
	}
	return (is_sorted(a) == 1 ? n : INT_MAX);
}

int					insertion_sort(int debug, t_stack *a, t_stack *b)
{
	int		n;

	n = 0;
	while (is_sorted(a) == 0 && b->size == 0)
	{
		execute(debug, "pb", a, b);
		n++;
		while (a->size > 0 && b->size > 0 && deref(a, 'h') > deref(b, 'h'))
		{
			execute(debug, "pb", a, b);
			n++;
		}
		while (a->size > 0 && b->size > 0 && deref(a, 'h') < deref(b, 'h'))
		{
			execute(debug, "pa", a, b);
			execute(debug, "sa", a, b);
			n += 2;
		}
		if (a->size == 0)
			while (b->size > 0)
			{
				execute(debug, "pa", a, b);
				n++;
			}
	}
	return (n);
}

int				find_med(t_stack *a)
{
	t_list			*tmp;
	long long		total;

	total = 0;
	tmp = a->head;
	while (tmp != NULL)
	{
		total += *((int *)tmp->content);
		tmp = tmp->next;
	}
	return (total / a->size);
}

int				merge_sort_stk(int debug, t_stack *a, t_stack *b)
{
	int			med;
	int			occ;
	int			n;
	char		ch;

	n = 0;
	while (a->size > 5)
	{
		med = find_med(a);
		occ = in_range_occurrences(a, med);
		while (occ > 0 && a->size > 5)
		{
			if (a->size > 0 && deref(a, 'h') <= med)
			{
				execute(debug, "pb", a, b);
				occ--;
			}
			else
				execute(debug, "ra", a, b);
			n++;
		}
	}
	n += small_sort(debug, a, b);
	while (b->size > 0)
	{
		ch = (search_stack(find_smallest(b), b) <= (a->size / 2)) ? 't' : 'b';
		med = find_largest(b);
		while (b->size > 0 && deref(b, 'h') != med)
		{
			if (ch == 't')
				execute(debug, "rb", a, b);
			else
				execute(debug, "rrb", a, b);
			n++;
		}
		execute(debug, "pa", a, b);
		n++;
	}
	return (n);
}
