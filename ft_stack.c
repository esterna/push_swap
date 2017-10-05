/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 16:00:25 by esterna           #+#    #+#             */
/*   Updated: 2017/10/03 20:25:02 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack			*init_stack(void)
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

void			push(t_stack *stack, t_list *x)
{
	if (stack->size == 0)
		stack->tail = x;
	ft_lstadd(&(stack->head), x);
	stack->size++;
}

t_list				*pop(t_stack *stack)
{
	t_list	*top;

	if (stack->head == NULL)
		return (NULL);
	top = stack->head;
	stack->head = stack->head->next;
	stack->size--;
	if (stack->size == 0)
		stack->tail = NULL;
	return (top);
}


