/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_attempt_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 18:53:16 by esterna           #+#    #+#             */
/*   Updated: 2017/10/04 20:10:21 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				split_stacks_ab(int debug, t_stack *a, t_stack *b, char ch)
{
	int		med;
	int		i;
	int		ugh;
	int		n;
	int		next;
	int		tmp;
	int		third_qua;
	int		mode;

	i = 0;
	if (a->size <= 5 && ch == 'a')
	{
		small_sort(debug, a, b);
		return ;
	}
	if (is_sorted(a) == 1 && b->size == 0)
		return ;
	tmp = find_med_stk(a);
	med = find_qua_stk(a, tmp);
	third_qua = find_3qua_stk(a, tmp);
	n = a->size / 4 + (a->size % 4 != 0 ? 1 : 0);
	mode = 0;
	while (i < n && ch == 'a' && mode < 2)
	{
		if ((a->head != NULL && (ugh = *((int *)a->head->content)) <= med)
				&& !(a->size > 1 && (next = *((int *)a->head->next->content)) <= med && next < ugh))
		{
			execute(debug, "pb", a, b, 1);
			if (*((int *)b->head->content) < *((int *)b->tail->content) &&
					(a->head != NULL && (ugh = *((int *)a->head->content)) > med))
				execute(debug, "rr", a, b, 1);
			else if (*((int *)b->head->content) < *((int *)b->tail->content))
				execute(debug, "rb", a, b, 1);
			if (*((int *)b->head->content) < *((int *)b->tail->content) &&
					(a->size != 0 && (ugh = *((int *)a->tail->content)) <= med) && ugh > *((int *)a->head->content))
				execute(debug, "rrr", a, b, 1);
			else if (*((int *)b->head->content) < *((int *)b->tail->content))
				execute(debug, "rrb", a, b, 1);
			if (b->size > 1 && *((int *)b->head->content) < *((int *)b->head->next->content) &&
					a->size > 1 && (next = *((int *)a->head->next->content)) <= med && next < ugh)
				execute(debug, "ss", a, b, 1);
			else if (b->size > 1 && *((int *)b->head->content) < *((int *)b->head->next->content))
				execute(debug, "sb", a, b, 1);
			i++;
		}
		else if (a->size > 1 && (next = *((int *)a->head->next->content)) <= med && next < ugh)
			execute(debug, "sa", a, b, 1);
		else
			execute(debug, "ra", a, b, 1);
		if (i == n)
		{
			if (mode == 0)
				med = tmp;
			else
				med = third_qua;
			mode++;
			i = 0;
		}
	}
/*	tmp = find_med_stk(b);
	third_qua = find_qua_stk(b, tmp);
	med = find_3qua_stk(b, tmp);
	n = b->size / 4 + (b->size % 4 != 0 ? 1 : 0);
	mode = 2;
	while (i < n && ch == 'b' && mode > 0 && b->size > 0)
	{
		if (((b->head != NULL && (ugh = *((int *)b->head->content)) >= med)
					&& !(b->size > 1 && (next = *((int *)b->head->next->content)) >= med && next > ugh)))
		{
			execute(debug, "pa", a, b, 1);
			if (*((int *)a->head->content) > *((int *)a->tail->content) &&
					(b->head != NULL && (ugh = *((int *)b->head->content)) < med))
				execute(debug, "rr", a, b, 1);
			else if (*((int *)a->head->content) > *((int *)a->tail->content))
				execute(debug, "ra", a, b, 1);
			if (*((int *)a->head->content) > *((int *)a->tail->content) &&
					(b->size != 0 && (ugh = *((int *)b->tail->content)) > med) && ugh < *((int *)b->head->content))
				execute(debug, "rrr", a, b, 1);
			else if (*((int *)a->head->content) > *((int *)a->tail->content))
				execute(debug, "rra", a, b, 1);
			if (a->size > 1 && *((int *)a->head->content) > *((int *)a->head->next->content) &&
					b->size > 1 && (next = *((int *)b->head->next->content)) > med && next > ugh)
				execute(debug, "ss", a, b, 1);
			else if (a->size > 1 && *((int *)a->head->content) > *((int *)a->head->next->content))
				execute(debug, "sa", a, b, 1);	
			i++;
		}
		else if (b->size > 1 && (next = *((int *)b->head->next->content)) >= med && next > ugh)
			execute(debug, "sb", a, b, 1);
		else
			execute(debug, "rb", a, b, 1);
		if (i == n)
		{
			if (mode == 2)
				med = tmp;
			else
				med = third_qua;
			mode--;
			i = 0;
		}
	}*/
	while (ch == 'b'  && b->size > 0)
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
					(b->size != 0 && *((int *)b->tail->content)) > *((int *)b->head->content))
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
	split_stacks_ab(debug, a, b, 'a');
	split_stacks_ab(debug, a, b, 'b');
}

void					attempt_2(int debug, t_stack *a, t_stack *b)
{
	while (b->size != 0 || is_sorted(a) != 1)
	{
		split_stacks_ab(debug, a, b, 'a');
		if (is_sorted(a) == 1)
		{
			while (b->size != 0)
				execute(debug, "pa\n", a, b, 1);
		}

	}	
}
