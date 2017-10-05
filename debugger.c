/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 15:15:34 by esterna           #+#    #+#             */
/*   Updated: 2017/09/28 15:37:51 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					print_stacks(int i, t_stack *a, t_stack *b)
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
