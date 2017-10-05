/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:03:28 by esterna           #+#    #+#             */
/*   Updated: 2017/10/03 18:17:41 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int						find_smallest(t_stack *a)
{
	t_list		*current;
	int			smallest;

	current = a->head;
	smallest = *((int *)current->content);
	while (current != NULL)
	{
		if (*((int *)current->content) < smallest)
			smallest = *((int *)current->content);
		current = current->next;
	}
	return (smallest);
}

int						find_largest(t_stack *s)
{
	t_list		*current;
	int			largest;

	current = s->head;
	largest = *((int *)current->content);
	while (current != NULL)
	{
		if (*((int *)current->content) > largest)
			largest = *((int *)current->content);
		current = current->next;
	}
	return (largest);
}

int						rotate_direction(t_stack *s, int n)
{
	int			i;
	t_list		*current;

	i = 0;
	current = s->head;
	while (*((int *)current->content) != n && current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i <= s->size/2 ? 1 : 0);
}

void					sort_new(int debug, t_stack *a, t_stack *b)
{
	int		smallest;
	int		direction;
	int		current;

	while (a->size > 0)
	{
		smallest = find_smallest(a);
		direction = rotate_direction(a, smallest);
		while ((current = *((int *)a->head->content)) != smallest)
		{
			if (direction == 1)
			{
				ft_putstr("ra\n");
				rotate(a);
			}
			else
			{
				ft_putstr("rra\n");
				reverse_rotate(a);
			}
			print_stacks(debug, a, b);
		}
		ft_putstr("pb\n");
		push(b, pop(a));
		print_stacks(debug, a, b);
	}
	while (b->size > 0)
	{
		ft_putstr("pa\n");
		push(a, pop(b));
		print_stacks(debug, a, b);
	}
}

void					sort_stkb(int debug, t_stack *a, t_stack *b)
{
	int		largest;
	int		direction;
	int		current;
	int		n;

	n = b->size;
	while (b->size > 0)
	{
		largest = find_largest(b);
		direction = rotate_direction(b, largest);
		while ((current = *((int *)b->head->content)) != largest)
		{
			if (direction == 1)
			{
				ft_putstr("rb\n");
				rotate(b);
			}
			else
			{
				ft_putstr("rrb\n");
				reverse_rotate(b);
			}
			print_stacks(debug, a, b);
		}
		ft_putstr("pa\n");
		push(a, pop(b));
		print_stacks(debug, a, b);
	}
	while (b->size < n)
	{
		ft_putstr("pb\n");
		push(b, pop(a));
		print_stacks(debug, a, b);
	}
}
