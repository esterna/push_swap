/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 21:51:32 by esterna           #+#    #+#             */
/*   Updated: 2017/10/05 14:57:45 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			stk_del(t_stack *a, t_stack *b)
{
	t_list		*next_item;

	while (a->head != NULL)
	{
		next_item = a->head->next;
		free(a->head->content);
		free(a->head);
		a->head = next_item;
	}
	while (b->head != NULL)
	{
		next_item = b->head->next;
		free(b->head->content);
		free(b->head);
		b->head = next_item;
	}
	free(a);
	free(b);
}
