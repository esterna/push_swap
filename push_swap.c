/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 19:04:10 by esterna           #+#    #+#             */
/*   Updated: 2017/10/04 20:51:20 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					main(int argc, char **argv)
{
	int			debug;
	t_stack		*a;
	t_stack		*b;
	t_list		*next_item;


	if (argc == 1)
		return (0);
	debug = (ft_strcmp(*(argv + 1), "-v") == 0) ? 1 : 0;
	a = init_stack();
	b = init_stack();
	if (setup_stacks(argc - 1, argv + 1, a) == 0 || is_sorted(a) == 1)
	{
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
		return (0);
	}
	if (a->size <= 5) 
		small_sort(debug, a, b);
	else
		sort_attempt_3(debug, a, b);
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
	return (0);
}
