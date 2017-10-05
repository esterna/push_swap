/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 21:24:39 by esterna           #+#    #+#             */
/*   Updated: 2017/10/04 16:32:53 by esterna          ###   ########.fr       */
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


static int			check_duplicates(t_list *lst)
{
	int			n;
	t_list		*tmp;

	while (lst != NULL)
	{
		n = *((int *)lst->content);
		tmp = lst->next;
		while (tmp != NULL)
		{
			if (n == *((int *)tmp->content))
				return (0);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (1);
}

int			str_to_stk(char *str, t_stack *stack)
{
	char		*tmp;
	long long	n;
	int			i;

	tmp = str;
	str += ft_strlen(str) - 1;
	while (str != tmp)
	{
		while ((ft_isdigit(*str) == 1 || *str == '-') && str != tmp)
			str--;
		n = ft_atoi(str + 1);
		if (n > INT_MAX || n < INT_MIN)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i = n;
		push(stack, ft_lstnew((const void *)(&i), sizeof(int)));
		while (ft_isspace(*str) == 1 && str != tmp)
			str--;
	}
	return (1);
}

int			setup_stacks(int argc, char **argv, t_stack *stack)
{
	int			i;
	int			j;
	long long	n;
	int			tmp;
	int			s;

	i = argc - 1;
	if (ft_strcmp(*(argv), "-v") == 0)
	{
		argv++;
		i--;
	}
	while (i >= 0)
	{
		j = 0;
		s = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != '-'
					&& ft_isspace(argv[i][j]) == 0)
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			s += ft_isspace(argv[i][j]);
			j++;
		}
		if (s > 0 && str_to_stk(argv[i], stack) == 0)
			return (0);
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		tmp = n;
		push(stack, ft_lstnew((const void *)(&tmp), sizeof(int)));
		i--;
	}
	if (check_duplicates(stack->head) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}
