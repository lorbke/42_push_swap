# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 14:29:24 by lorbke            #+#    #+#              #
#    Updated: 2022/11/08 20:24:18 by lorbke           ###   ########.fr        #
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
FLAGS = -Wall -Wextra -Werror

SRC = ps_parse_args.c ps_index_args.c ps_stack_utils.c ps_operator_utils.c \
ps_operator.c ps_sort_utils.c ps_qsort.c ps_subsequence.c ps_insort.c \
ps_hardsort_cases.c ps_hardsort.c ps_main.c

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
