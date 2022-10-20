# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 14:29:24 by lorbke            #+#    #+#              #
#    Updated: 2022/10/20 02:00:30 by lorbke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFTDIR = ./libft
LIBFTLIB = libft.a

PUSHSWAPLIB = push_swap.a

CC = cc
AR = ar rcs
RM = rm -f
INCLUDES = -g -fsanitize=address,undefined
FLAGS = #-Wall -Wextra -Werror

SRC = test_functions.c main.c parse.c operations.c operator.c sort_utils.c \
quicksort.c solution_state.c stack_utils.c intvec_utils.c bruteforce_utils.c \
bruteforce.c test_operate.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${PUSHSWAPLIB}
	${CC} ${FLAGS} ${SRC} ${PUSHSWAPLIB} ${LIBFTDIR}/${LIBFTLIB} -o ${NAME}

${PUSHSWAPLIB}: ${OBJ} ${LIBFTDIR}/${LIBFTLIB}
	${AR} ${PUSHSWAPLIB} ${OBJ}

%.o:%.c
	${CC} ${FLAGS} ${INCLUDES} -c $< -o $@

${LIBFTDIR}/${LIBFTLIB}:
	make -C $(LIBFTDIR)

clean:
	${RM} ${OBJ}
	cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME} ${PUSHSWAPLIB}
	cd $(LIBFTDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
