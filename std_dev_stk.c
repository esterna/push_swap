/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_dev_stk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 15:02:22 by esterna           #+#    #+#             */
/*   Updated: 2017/10/09 16:25:27 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					find_smallest(t_stack *a)
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

int					find_largest(t_stack *s)
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

int					in_range_occurrences(t_stack *s, int range)
{
	t_list	*tmp;
	int		n;

	n = 0;
	tmp = s->head;
	while (tmp)
	{
		if (*((int *)tmp->content) <= range)
			n++;
		tmp = tmp->next;
	}
	return (n);
}

int					std_dev_stk(t_stack *a)
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
		variance += (*((int *)tmp->content) - mean)
					* (*((int *)tmp->content) - mean);
		tmp = tmp->next;
	}
	variance /= a->size;
	return ((int)ft_round_dbl(ft_sqrt((double)variance), 0));
}
