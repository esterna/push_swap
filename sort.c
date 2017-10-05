/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 19:58:39 by esterna           #+#    #+#             */
/*   Updated: 2017/10/04 21:29:18 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				(*g_sort_stk[127]) (t_stack *stack) =
{
		['s'] = swap,
		['r'] = rotate,
		['2'] = reverse_rotate
};

void				execute(int debug, char *line, t_stack *a, t_stack *b, int p)
{
	char ch;
	
	if (p == 1)
		ft_printf("%s\n", line);
	if (g_sort_stk[(int)(*line)] != NULL)
	{
		ch = *line;
		line++;
		if (*line == 'r' && *(line + 1) != '\0')
		{
			line++;
			if (*line == 'a' || *line == 'b')
				g_sort_stk['2']((*line) == 'a' ? a : b);
			else
			{
				g_sort_stk['2'](a);
				g_sort_stk['2'](b);
			}
		}
		else if (*line == 'r' || *line == 's')
		{
			g_sort_stk[(int)ch](a);
			g_sort_stk[(int)ch](b);
		}
		else
			g_sort_stk[(int)ch]((*line) == 'a' ? a : b);
	}
	else
		push_ab(a, b, *(line + 1));
	print_stacks(debug, a, b);
}

void				small_sort(int debug, t_stack *a, t_stack *b)
{
	int		n;
	int		ugh;
	int		why;
	int		death;
	
	n = a->size;
	print_stacks(debug, a, b);
	if (a->size <= 1 || is_sorted(a))
			return ;
	if (a->size == 2)
	{
		execute(debug, "sa", a, b, 1);
		return ;
	}
	while (a->size != n || is_sorted(a) != 1)
	{
		death = 0;
		ugh = 0;
		why = 0;

		if ((death = a->size) > 1
				&& (ugh = *((int *)a->head->content)) > (why = *((int *)a->tail->content)))
			execute(debug, "ra", a, b, 1);
		else if (a->size > 1 && *((int *)a->head->content) > *((int *)a->head->next->content))
			execute(debug, "sa", a, b, 1);
		else if (a->head != NULL  && (b->head == NULL ||
					*((int *)a->head->content) > *((int *)b->head->content)))
			execute(debug, "pb", a, b, 1);
		if (b->head != NULL && *((int *)b->head->content) < *((int *)b->tail->content))
			execute(debug, "rb", a, b, 1);
		else if (b->head != NULL && b->head->next != NULL && *((int *)b->head->content) < *((int *)b->head->next->content))
			execute(debug, "sb", a, b, 1);
		if (is_sorted(a) == 1)
			while (a->size != n)
				execute(debug, "pa", a, b, 1);
	}
}

int					find_med_stk(t_stack *stack)
{
	int			med;
	t_list		*curr;
	t_list		*tmp;
	int			n;
	int			k;

	curr = stack->head;
	n = stack->size / 2 + (stack->size % 4 != 0 ? 1 : 0);
	while (curr != NULL)
	{
		med = *((int *)curr->content);
		tmp = stack->head;
		k = 0;
		while (tmp != NULL)
		{
			if (*((int *)tmp->content) <= med)
				k++;	
			if (k > n)
				break ;
			tmp = tmp->next;
		}
		if (k == n)
			return (med);
		curr = curr->next;
	}
	return (med);
}

int					find_qua_stk(t_stack *stack, int med)
{
	int			qua;
	t_list		*curr;
	t_list		*tmp;
	int			n;
	int			k;

	curr = stack->head;
	n = stack->size / 4 + (stack->size % 4 != 0 ? 1 : 0);
	while (curr != NULL)
	{
		qua = *((int *)curr->content);
		tmp = stack->head;
		k = 0;
		while (tmp != NULL)
		{
			if (*((int *)tmp->content) <= qua &&
					*((int *)tmp->content) < med)
				k++;	
			if (k > n)
				break ;
			tmp = tmp->next;
		}
		if (k == n)
			return (qua);
		curr = curr->next;
	}
	return (qua);
}

int					find_3qua_stk(t_stack *stack, int med)
{
	int			qua;
	t_list		*curr;
	t_list		*tmp;
	int			n;
	int			k;

	curr = stack->head;
	n = stack->size / 4 + (stack->size % 4 != 0 ? 1 : 0);
	while (curr != NULL)
	{
		qua = *((int *)curr->content);
		tmp = stack->head;
		k = 0;
		while (tmp != NULL)
		{
			if (*((int *)tmp->content) <= qua &&
					*((int *)tmp->content) > med)
				k++;	
			if (k > n)
				break ;
			tmp = tmp->next;
		}
		if (k == n)
			return (qua);
		curr = curr->next;
	}
	return (qua);
}


int					find_avg_stk(t_stack *stack)
{
	t_list		*tmp;
	int			result;

	result = 0;
	tmp = stack->head;
	while (tmp != NULL)
	{
		result += *((int *)tmp->content);
		tmp = tmp->next;
	}
	return ((int)ft_round_dbl((double)result/stack->size, 0));
}

void				split_stacks(int debug, t_stack *a, t_stack *b)
{
	int		med;
	int		i;
	int		ugh;
	int		n;

	i = 0;
	if (a->size <= 5)
	{
		sort_new(debug, a, b);
		return ;
	}
	med = find_med_stk(a);
	n = a->size/2;
	while (i < n)
	{
		if (a->head != NULL && (ugh = *((int *)a->head->content)) <= med)
		{
			ft_putstr("pb\n");
			push(b, pop(a));
			print_stacks(debug, a, b);
			i++;
		/*	if (b->head != NULL && b->tail != NULL
					&& *((int *)b->head->content) < *((int *)b->tail->content))
			{
				ft_putstr("rb\n");
				rotate(b);
				print_stacks(debug, a, b);
			}	
			if (b->head != NULL && b->head->next != NULL
					&& *((int *)b->head->content) < *((int *)b->head->next->content))
			{
				ft_putstr("sb\n");
				swap(b);
				print_stacks(debug, a, b);
			}*/
		}
		else
		{
			ft_putstr("ra\n");
			rotate(a);
			print_stacks(debug, a, b);
		}
	}
	if (b->size <= 5)
		sort_stkb(debug, a, b);
	split_stacks(debug, a, b);
}

void				merge_sort_stacks(int debug, t_stack *a, t_stack *b)
{
	print_stacks(debug, a, b);
	if (a->size == 2)
	{
		ft_putstr("sa\n");
		swap(a);
		print_stacks(debug, a, b);
		return ;
	}
	while (b->size != 0 || is_sorted(a) != 1)
	{
	/*	if (a->head != NULL && a->tail != NULL
				&& *((int *)a->head->content) > *((int *)a->tail->content))
		{
			ft_putstr("ra\n");
			rotate(a);
		}	
		else if (a->head->next != NULL && *((int *)a->head->content) > *((int *)a->head->next->content))
		{
			ft_putstr("sa\n");
			swap(a);
		}*/
		split_stacks(debug, a, b);
		if (is_sorted(a) == 1)
		{
			while (b->size != 0)
			{
				ft_putstr("pa\n");
				push(a, pop(b));
				print_stacks(debug, a, b);
			}
		}

	}

}
