# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 14:29:24 by lorbke            #+#    #+#              #
#    Updated: 2022/11/09 20:58:00 by lorbke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name macros
NAME = push_swap

# command macros
CC = cc
AR = ar rcs
RM = rm -f
ADD_FLAGS = #-g -fsanitize=address,undefined
FLAGS = -Wall -Wextra -Werror

# path macros
INC_PATH = includes
LIB_PATH = libft
LIBINC_PATH = $(LIB_PATH)/includes
OBJ_PATH = obj
SRC_PATH = src

# src and obj files macros
SRC = ps_parse_args.c ps_index_args.c ps_stack_utils.c ps_operator_utils.c \
ps_operator.c ps_sort_utils.c ps_qsort.c ps_subsequence.c ps_insort.c \
ps_hardsort_cases.c ps_hardsort.c ps_main.c
OBJ = $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))

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
	${CC} ${FLAGS} ${ADD_FLAGS} -I$(INC_PATH) -I$(LIBINC_PATH) -c $< -o $@

# phony targets
all: ${NAME}

makedir:
	@mkdir -p $(OBJ_PATH)
 
clean:
	${RM} -r $(OBJ_PATH)
	cd $(LIB_PATH) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	cd $(LIB_PATH) && $(MAKE) fclean

re: fclean makedir all

.PHONY: all clean fclean re
