/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 15:15:34 by esterna           #+#    #+#             */
/*   Updated: 2017/10/09 16:49:17 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				deref(t_stack *stack, char ch)
{
	if (ch == 'h')
		return (*((int *)stack->head->content));
	else if (ch == 't')
		return (*((int *)stack->tail->content));
	else
		return (*((int *)stack->head->next->content));
}

void			(*g_sort_stk[127]) (t_stack *stack) =
{
	['s'] = swap,
	['r'] = rotate,
	['2'] = reverse_rotate
};

int				execute_p3(char *line, t_stack *a, t_stack *b)
{
	if (*line == 'a' || *line == 'b')
		g_sort_stk['2']((*line) == 'a' ? a : b);
	else if (*line == 'r')
	{
		g_sort_stk['2'](a);
		g_sort_stk['2'](b);
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

int				execute_p2(char ch, char *line, t_stack *a, t_stack *b)
{
	if (*line == 'r' && *(line + 1) != '\0' && *(line + 2) == '\0')
		return (execute_p3(++line, a, b));
	else if ((*line == 'r' || *line == 's') && *(line + 1) == '\0')
	{
		g_sort_stk[(int)ch](a);
		g_sort_stk[(int)ch](b);
	}
	else if ((*line == 'a' || *line == 'b') && *(line + 1) == '\0')
		g_sort_stk[(int)ch]((*line) == 'a' ? a : b);
	else
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

int				execute(int debug, char *line, t_stack *a, t_stack *b)
{
	char	ch;
	int		n;

	if (debug > 1 && ft_printf("%s\n", line))
		debug = (debug > 2) ? 1 : debug;
	if (g_sort_stk[(int)(*line)] != NULL)
	{
		ch = *line;
		line++;
		n = execute_p2(ch, line, a, b);
		print_stacks(debug, a, b);
		return (n);
	}
	else if (*line == 'p' && (*(line + 1) == 'a' || *(line + 1) == 'b')
				&& *(line + 2) == '\0')
		push_ab(a, b, *(line + 1));
	else
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	print_stacks(debug, a, b);
	return (1);
}

void			print_stacks(int i, t_stack *a, t_stack *b)
{
	t_list	*tmp;

	if (i != 1)
		return ;
	tmp = a->head;
	ft_putstr("A:");
	while (tmp != NULL)
	{
		ft_printf(" %d", *((int *)tmp->content));
		tmp = tmp->next;
	}
	ft_putstr("\nB:");
	tmp = b->head;
	while (tmp != NULL)
	{
		ft_printf(" %d", *((int *)tmp->content));
		tmp = tmp->next;
	}
	ft_putchar('\n');
}
