/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_attempt_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 20:36:15 by esterna           #+#    #+#             */
/*   Updated: 2017/10/04 21:27:44 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					std_deviation_stk(t_stack *a)
{
	int		tot;
	t_list	*tmp;
	int		mean;
	int		variance;

	tot = 0;
	tmp = a->head;
	while (tmp)
	{
		tot += *((int *)tmp->content);
		tmp = tmp->next;
	}
	mean = tot / a->size;
	tmp = a->head;
	variance = 0;
	while (tmp)
	{
		variance += (*((int *)tmp->content) - mean) * (*((int *)tmp->content) - mean);
		tmp = tmp->next;
	}
	variance /= a->size;
	return ((int)ft_round_dbl(ft_sqrt((double)variance), 0));
}

void				sort_attempt_3(int debug, t_stack *a, t_stack *b)
{
	int		smallest;
	int		range;
	int		n;
	t_list	*tmp;
	int		i;
	int		ugh;
	int		next;
	int		stddev;

	stddev = std_deviation_stk(a);
	while (a->size > 5)
	{
		n = 0;
		smallest = find_smallest(a);
		range = smallest + stddev;
		tmp = a->head;
		while (tmp)
		{
			if (*((int *)tmp->content) <= range)
				n++;
			tmp = tmp->next;
		}
		i = 0;
		while (i < n)
		{
			if ((a->head != NULL && (ugh = *((int *)a->head->content)) <= range)
					&& !(a->size > 1 && (next = *((int *)a->head->next->content)) <= range && next < ugh))
			{
				execute(debug, "pb", a, b, 1);
				if (*((int *)b->head->content) < *((int *)b->tail->content) &&
						(a->head != NULL && (ugh = *((int *)a->head->content)) > range))
					execute(debug, "rr", a, b, 1);
				else if (*((int *)b->head->content) < *((int *)b->tail->content))
					execute(debug, "rb", a, b, 1);
				if (*((int *)b->head->content) < *((int *)b->tail->content) &&
						(a->size != 0 && (ugh = *((int *)a->tail->content)) <= range && ugh > *((int *)a->head->content)))
					execute(debug, "rrr", a, b, 1);
				else if (*((int *)b->head->content) < *((int *)b->tail->content))
					execute(debug, "rrb", a, b, 1);
				if (b->size > 1 && *((int *)b->head->content) < *((int *)b->head->next->content) &&
						(a->size > 1 && (next = *((int *)a->head->next->content)) <= range && next < ugh))
					execute(debug, "ss", a, b, 1);
				else if (b->size > 1 && *((int *)b->head->content) < *((int *)b->head->next->content))
					execute(debug, "sb", a, b, 1);
				i++;
			}
			else if ((a->size > 1 && (next = *((int *)a->head->next->content)) <= range && next < ugh))
				execute(debug, "sa", a, b, 1);
			else
				execute(debug, "ra", a, b, 1);
		}
	}
	small_sort(debug, a, b);
	while (b->size > 0)
	{
		if (!(b->size > 1 && *((int *)b->head->next->content) > *((int *)b->head->content)))
		{
			execute(debug, "pa", a, b, 1);
			if (*((int *)a->head->content) > *((int *)a->tail->content) &&
					b->head != NULL)
				execute(debug, "rr", a, b, 1);
			else if (*((int *)a->head->content) > *((int *)a->tail->content))
				execute(debug, "ra", a, b, 1);
			if (*((int *)a->head->content) > *((int *)a->tail->content) &&
					(b->size != 0 && *((int *)b->tail->content) > *((int *)b->head->content)))
				execute(debug, "rrr", a, b, 1);
			else if (*((int *)a->head->content) > *((int *)a->tail->content))
				execute(debug, "rra", a, b, 1);
			if (a->size > 1 && *((int *)a->head->content) > *((int *)a->head->next->content) &&
					(b->size > 1 && *((int *)b->head->next->content) > *((int *)b->head->content)))
				execute(debug, "ss", a, b, 1);
			else if (a->size > 1 && *((int *)a->head->content) > *((int *)a->head->next->content))
				execute(debug, "sa", a, b, 1);	
			i++;
		}
		else if (b->size > 1 && *((int *)b->head->next->content) > *((int *)b->head->content))
			execute(debug, "sb", a, b, 1);
		else
			execute(debug, "rb", a, b, 1);
	}
}
