# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esterna <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/26 17:01:46 by esterna           #+#    #+#              #
#    Updated: 2017/10/04 20:50:59 by esterna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
DEPS = libft.a\
	   libftprintf.a
FUNCTIONS = debugger.c\
			ft_lstnew.c\
			get_next_line.c\
			spr_stack.c\
		    ft_lstdel.c\
		    ft_stack.c\
			setup_stacks.c\
			sort.c\
			sort_new.c\
			sort_attempt_2.c\
			sort_attempt_3.c

all: $(NAME)

$(NAME): 
	@gcc $(CFLAGS) -g -o $(NAME) $(NAME).c $(FUNCTIONS) $(DEPS)
	@gcc $(CFLAGS) -g -o checker checker.c $(FUNCTIONS) $(DEPS)

clean:

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f checker
	@/bin/rm -rf *.dSYM

re: fclean all
