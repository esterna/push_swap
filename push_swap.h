/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:52:50 by esterna           #+#    #+#             */
/*   Updated: 2017/10/04 20:52:56 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "libftprintf.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <limits.h>

typedef struct			s_stack
{
	struct s_list	*head;
	struct s_list	*tail;
	int				size;
}						t_stack;

void				swap(t_stack *stack);

void				reverse_rotate(t_stack *stack);

void				rotate(t_stack *stack);

void				execute(int debug, char *line, t_stack *a, t_stack *b, int p);

int					find_med_stk(t_stack *stack);

int					find_qua_stk(t_stack *stack, int med);

int					find_3qua_stk(t_stack *stack, int med);

int					find_largest(t_stack *s);

int					find_smallest(t_stack *a);

t_stack				*init_stack(void);

int					is_sorted(t_stack *a);

int					is_sorted_reversed(t_stack *stack);

void				merge_sort_stacks(int debug, t_stack *a, t_stack *b);

t_list				*pop(t_stack *stack);

void				print_stacks(int i, t_stack *a, t_stack *b);

void				push(t_stack *stack, t_list *x);

void				push_ab(t_stack *a, t_stack *b, char ch);

int					setup_stacks(int argc, char **argv, t_stack *stack);

void				small_sort(int debug, t_stack *a, t_stack *b);

void				sort_stkb(int debug, t_stack *a, t_stack *b);

void				sort_new(int debug, t_stack *a, t_stack *b);

void				split_stacks_ab(int debug, t_stack *a, t_stack *b, char ch);

void				attempt_2(int debug, t_stack *a, t_stack *b);

void				sort_attempt_3(int debug, t_stack *a, t_stack *b);

#endif
