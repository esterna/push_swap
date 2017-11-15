/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:34:25 by esterna           #+#    #+#             */
/*   Updated: 2017/11/14 22:13:30 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack				*make_stk_cpy(t_stack *a)
{
	t_stack		*tmp_a;
	t_list		*tmp_lst;

	tmp_a = init_stack();
	tmp_a->head = ft_lstcpy(a->head);
	tmp_a->size = a->size;
	tmp_lst = tmp_a->head;
	while (tmp_lst->next != NULL)
		tmp_lst = tmp_lst->next;
	tmp_a->tail = tmp_lst;
	return (tmp_a);
}

void				reset_stacks(t_stack **tmp_a, t_stack **tmp_b, t_stack *a)
{
	stk_del(*tmp_a, *tmp_b);
	*tmp_a = make_stk_cpy(a);
	*tmp_b = init_stack();
}	

int					find_sort(t_stack *a, int debug)
{
	t_stack		*tmp_a;
	t_stack		*tmp_b;
	int			n[2];
	int			tmp;

	if (is_sorted(a) == 1)
		return (0);
	tmp_a = make_stk_cpy(a);
	tmp_b = init_stack();
	n[0] = 1;
	n[1] = rotate_sort(debug, tmp_a, tmp_b);
	reset_stacks(&tmp_a, &tmp_b, a);
	tmp = rev_rotate_sort(debug, tmp_a, tmp_b);
	if (tmp < n[1])
	{
		n[0] = 2;
		n[1] = tmp;
	}
	reset_stacks(&tmp_a, &tmp_b, a);
	tmp = insertion_sort(debug, tmp_a, tmp_b);
	if (tmp < n[1])
	{
		n[0] = 3;
		n[1] = tmp;
	}
	reset_stacks(&tmp_a, &tmp_b, a);
	tmp = merge_sort_stk(debug, tmp_a, tmp_b);
	if (tmp < n[1])
	{
		n[0] = 4;
		n[1] = tmp;
	}
	return (n[0]);
}
