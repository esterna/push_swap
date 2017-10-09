/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 16:57:23 by esterna           #+#    #+#             */
/*   Updated: 2017/10/05 19:15:16 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			swap(t_stack *stack)
{
	t_list	*i1;
	t_list	*i2;

	i1 = pop(stack);
	i2 = pop(stack);
	if (i1 != NULL)
		push(stack, i1);
	if (i2 != NULL)
		push(stack, i2);
}

void			push_ab(t_stack *a, t_stack *b, char ch)
{
	t_list	*tmp;

	tmp = pop(ch == 'a' ? b : a);
	if (tmp != NULL)
		push(ch == 'a' ? a : b, tmp);
}

void			rotate(t_stack *stack)
{
	t_list	*tmp;

	if (stack->size < 2)
		return ;
	tmp = pop(stack);
	if (tmp != NULL)
	{
		ft_lstaddend(&(stack->head), tmp);
		stack->size++;
		stack->tail = tmp;
	}
}

void			reverse_rotate(t_stack *stack)
{
	t_list	*lst;
	t_list	*tmp;

	if (stack->size < 2)
		return ;
	lst = stack->head;
	while (lst->next->next != NULL)
		lst = lst->next;
	tmp = lst->next;
	lst->next = NULL;
	tmp->next = stack->head;
	stack->head = tmp;
	stack->tail = lst;
}
