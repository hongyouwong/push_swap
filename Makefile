# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 10:06:21 by vkurkela          #+#    #+#              #
#    Updated: 2022/12/27 01:18:48 by hwong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS = push_swap
CHECKERS = checker

SRCS = push_swap_files/push_swap.c push_swap_files/sort_stack.c \
		push_swap_files/sort_three.c push_swap_files/sort_five.c \
		push_swap_files/big_sort.c push_swap_files/shortest_way.c

SCRS_CHKS = checker_files/checker.c checker_files/read_instructions.c \
		checker_files/execute_rules.c checker_files/check_rules.c \

OBJ = *.o

GREEN = \033[1;32m
RED = \033[1;31m
YEL = \033[1;33m
WHT = \033[1;37m
EOC = \033[1;0m

INCLUDES = includes/push_swap.h
INCLUDES_CHKS = includes/checker.h

LIBFT = libft/libft.a
UTILS = utils/utils.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(PS)

$(PS):
	echo "$(WHT)Compiling libraries...$(EOC)"
	${MAKE} -C libft
	${MAKE} -C UTILS
	echo "$(GREEN)Libraries done.$(EOC)"

	echo "$(WHT)Compiling push_swap...$(EOC)"
	$(CC) $(FLAGS) -c $(SRCS) -I$(INCLUDES)
	$(CC) $(FLAGS) -o $(PS) $(OBJ) $(LIBFT) $(UTILS)
	mkdir obj
	mv $(OBJ) ./obj
	echo "$(GREEN)push_swap build completed.$(EOC)"
	
	echo "$(WHT)Compiling checker...$(EOC)"
	$(CC) $(FLAGS) -c $(SCRS_CHKS) -I$(INCLUDES_CHKS)
	$(CC) $(FLAGS) -o $(CHECKERS) $(OBJ) $(LIBFT) $(UTILS)
	mv $(OBJ) ./obj
	echo "$(GREEN)checker build completed.$(EOC)"
	
clean:
	echo "$(WHT)Removing o-files...$(EOC)"
	/bin/rm -f $(OBJ)
	/bin/rm -Rf obj
	${MAKE} -C libft clean
	${MAKE} -C utils clean
	echo "$(GREEN)Clean done.$(EOC)"

fclean: clean
	echo "$(WHT)Removing object- and binary -files...$(EOC)"
	/bin/rm -f $(PS) $(CHECKERS)
	${MAKE} -C libft fclean
	${MAKE} -C utils fclean
	echo "$(GREEN)Fclean done.$(EOC)"

re: fclean all
