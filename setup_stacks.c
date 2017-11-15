/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 21:24:39 by esterna           #+#    #+#             */
/*   Updated: 2017/10/10 23:25:59 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int					str_to_stk(char *str, t_stack *stack)
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
		if (str == tmp)
			break;
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

static int			nbr_check(int i, char **argv)
{
	int			j;
	int			s;

	j = 0;
	s = 1;
	while (argv[i][j] != '\0' && (s += ft_isspace(argv[i][j])))
	{
		if (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != '-'
				&& ft_isspace(argv[i][j]) == 0)
			return (-1);
		j++;
	}
	return (s);
}

int					setup_stacks(int argc, char **argv, t_stack *stack)
{
	int			i;
	long long	n;
	int			s;

	i = (ft_strcmp(*(argv), "-v") == 0 && argv++) ? argc - 2 : argc - 1;
	while (i >= 0)
	{
		s = nbr_check(i, argv);
		if (s == -1 || (s > 1 && str_to_stk(argv[i], stack) == 0) ||
			((n = ft_atoi(argv[i])) > INT_MAX || n < INT_MIN))
			return (0);
		push(stack, ft_lstnew((const void *)(&n), sizeof(int)));
		i--;
	}
	if (check_duplicates(stack->head) == 0)
		return (0);
	return (1);
}
