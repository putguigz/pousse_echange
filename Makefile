# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpetit <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/23 13:49:56 by gpetit            #+#    #+#              #
#    Updated: 2021/06/24 14:46:10 by gpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

CC= clang

CFLAGS= -Wall -Wextra -Werror -g3

LIBFT= -Llibft -lft 

SRCS= $(addprefix srcs/, main.c init.c free.c stack_creation.c \
	input_conformity.c push_swap.c stack_switch.c stack_rotations.c \
	stack_reverse_rotations.c sort_mini_list.c sort_big_list.c stack_metrics.c \
	sort_3_to_5.c movements_printer.c sort_big_list_median.c \
	sort_big_list_optimal_path.c sort_big_list_pushback_a.c sort_big_list_others.c \
	stack_pushes.c)

OBJS= $(SRCS:.c=.o)

%.o: %.c
	$(CC) -Iincludes $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re 


