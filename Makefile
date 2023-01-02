NAME		= push_swap
CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Werror -Wextra -fsanitize=address -g

INCLUDES	= includes

SRCS		= src/main.c src/input_check.c src/input_check_utils.c src/init.c src/stack.c src/do_s.c src/do_p.c src/do_r.c src/do_rr.c src/sort_tiny.c src/sort.c src/position.c src/cost.c src/do_move.c src/utils.c
OBJS		= ${SRCS:.c=.o}

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(basename $<).o -I $(INCLUDES)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) checker

re: fclean all

#test2:				$(NAME)	
#					$(eval ARG = $(jot -r 1 0 5000))
#					./push_swap $(ARG) | ./checker_Mac $(ARG)
#					@echo -n "Instructions: "
#					@./push_swap $(ARG) | wc -l
#
#test3:				$(NAME)	
#					$(eval ARG = $(shell shuf -i 0-100 -n 3))
#					./push_swap $(ARG) | ./checker_Mac $(ARG)
#					@echo -n "Instructions: "
#					@./push_swap $(ARG) | wc -l
#
#test5:				$(NAME)	
#					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
#					./push_swap $(ARG) | ./checker_Mac $(ARG)
#					@echo -n "Instructions: "
#					@./push_swap $(ARG) | wc -l
#
#test100:			$(NAME)	
#					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
#					./push_swap $(ARG) | ./checker_Mac $(ARG)
#					@echo -n "Instructions: "
#					@./push_swap $(ARG) | wc -l
#
#test500:			$(NAME)	
#					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
#					./push_swap $(ARG) | ./checker_Mac $(ARG)
#					@echo -n "Instructions: "
#					@./push_swap $(ARG) | wc -l
#
#test1000:			$(NAME)	
#					$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
#					./push_swap $(ARG) | ./checker_Mac $(ARG)
#					@echo -n "Instructions: "
#					@./push_swap $(ARG) | wc -l
