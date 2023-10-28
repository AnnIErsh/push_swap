# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 04:06:21 by annaershova       #+#    #+#              #
#    Updated: 2023/10/09 23:09:12 by annaershova      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

FLAGS = -Wall -Werror -Wextra

CC = gcc

SRC = main.c \
	  parse.c \
	  rules.c \
	  lists.c \
	  lists_utils.c \
	  lists_utils2.c \
	  list_utils3.c \
	  list_utils4.c \
	  calculation.c \
	  moves.c \
	  compare.c \
	  lis_alg.c \
	  presort.c \
	  presort_part2.c \
	  optimization.c \
	  print_res.c
	  
BONUS_SRC = checker.c \
			checker_utils.c \
			get_next_line.c \
			get_next_line_utils.c \
			print_res_bonus.c 

EXCLUDES = 	main.c

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME):
	make --directory libft/ bonus
	$(CC) $(FLAGS) $(SRC) -L libft/ -lft -o $(NAME)
	make --directory libft/ clean
$(LIBFT):
	make --directory ./libft bonus

bonus: $(BONUS)

$(BONUS):
	make --directory libft/ bonus
	$(CC) $(FLAGS) $(filter-out $(EXCLUDES), $(SRC)) $(BONUS_SRC) -L libft/ -lft -o $(BONUS)
	make --directory libft/ clean

clean:
	rm -rf $(NAME) $(BONUS)

fclean: clean
	make --directory ./libft fclean

re: fclean all

.PHONY: all clean fclean re libft