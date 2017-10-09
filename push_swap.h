/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:52:50 by esterna           #+#    #+#             */
/*   Updated: 2017/10/09 16:25:39 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "libftprintf.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <limits.h>

typedef struct		s_stack
{
	struct s_list	*head;
	struct s_list	*tail;
	int				size;
}					t_stack;

int					deref(t_stack *s, char ch);

int					find_smallest(t_stack *a);

int					find_largest(t_stack *s);

int					in_range_occurrences(t_stack *s, int range);

void				swap(t_stack *stack);

void				reverse_rotate(t_stack *stack);

void				rotate(t_stack *stack);

int					execute(int debug, char *line,
							t_stack *a, t_stack *b);

t_stack				*init_stack(void);

int					is_sorted(t_stack *a);

int					is_sorted_reversed(t_stack *stack);

t_list				*pop(t_stack *stack);

void				print_stacks(int i, t_stack *a, t_stack *b);

void				push(t_stack *stack, t_list *x);

void				push_ab(t_stack *a, t_stack *b, char ch);

void				push_back_b_stk(int debug, t_stack *a, t_stack *b);

int					setup_stacks(int argc, char **argv, t_stack *stack);

void				small_sort(int debug, t_stack *a, t_stack *b);

void				sort_attempt_3(int debug, t_stack *a, t_stack *b);

int					std_dev_stk(t_stack *a);

void				stk_del(t_stack *a, t_stack *b);

#endif
