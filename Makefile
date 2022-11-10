# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 14:29:24 by lorbke            #+#    #+#              #
#    Updated: 2022/11/10 21:03:08 by lorbke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH = src checker

# name macros
NAME = push_swap
CHECKER = checker

# command macros
CC = cc
AR = ar rcs
RM = rm -f
ADD_FLAGS = #-g -fsanitize=address,undefined
FLAGS = -Wall -Wextra -Werror

# path macros
LIB_PATH = libft
LIB_INC = $(LIB_PATH)/includes
INC = includes
SRC_PATH = src
OBJ_PATH = obj
CHECKER_PATH = checker_bonus

# src and obj files macros
SRC = ps_parse_args.c ps_index_args.c ps_stack_utils.c ps_operator_utils.c \
ps_operator.c ps_sort_utils.c ps_qsort.c ps_subsequence.c ps_insort.c \
ps_hardsort_cases.c ps_hardsort.c ps_main.c
OBJ = $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))
CHECKER_SRC = ps_parse_args.c ps_index_args.c ps_stack_utils.c ps_operator_utils.c \
ps_operator.c ps_sort_utils.c get_next_line.c get_next_line_utils.c checker_main.c 
CHECKER_OBJ = $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(CHECKER_SRC)))))


# archive macros
LIBFT_AR = libft.a

# default target
default: makedir all

# file targets
${NAME}: $(OBJ)
	@make -C $(LIB_PATH)
	${CC} ${FLAGS} $(OBJ) ${LIB_PATH}/${LIBFT_AR} -o ${NAME}
	@echo "make: push_swap success!"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	${CC} ${FLAGS} ${ADD_FLAGS} -I$(INC) -I$(LIB_INC) -c $< -o $@

$(CHECKER): $(CHECKER_OBJ)
	$(CC) $(FLAGS) $(CHECKER_OBJ) ${LIB_PATH}/${LIBFT_AR} -o $(CHECKER)

$(OBJ_PATH)/%.o: $(CHECKER_PATH)/%.c
	${CC} ${FLAGS} ${ADD_FLAGS} -I$(INC) -I$(LIB_INC) -c $< -o $@

# phony targets
all: ${NAME}

makedir:
	@mkdir -p $(OBJ_PATH)

bonus: makedir $(NAME) $(CHECKER)

clean:
	${RM} -r $(OBJ_PATH)
	cd $(LIB_PATH) && $(MAKE) clean

fclean: clean
	${RM} ${NAME} $(CHECKER)
	cd $(LIB_PATH) && $(MAKE) fclean

re: fclean makedir all

.PHONY: all clean fclean re
