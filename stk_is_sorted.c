/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_is_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 22:18:03 by esterna           #+#    #+#             */
/*   Updated: 2017/10/05 22:18:31 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					is_sorted(t_stack *stack)
{
	t_list	*tmp;
	int		ugh;
	int		why;

	if (stack->head == NULL)
		return (0);
	tmp = stack->head;
	while (tmp->next != NULL)
	{
		ugh = *((int *)tmp->content);
		why = *((int *)tmp->next->content);
		if (ugh > why)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int					is_sorted_reversed(t_stack *stack)
{
	t_list	*tmp;
	int		ugh;
	int		why;

	if (stack->head == NULL)
		return (0);
	tmp = stack->head;
	while (tmp->next != NULL)
	{
		ugh = *((int *)tmp->content);
		why = *((int *)tmp->next->content);
		if (ugh < why)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
