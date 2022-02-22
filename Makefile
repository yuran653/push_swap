# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 01:09:45 by jgoldste          #+#    #+#              #
#    Updated: 2022/02/22 06:49:19 by jgoldste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

SRCS		=	push_swap.c		parse_argv.c		init_stack.c	get_number.c\
				make_swap.c		make_rotate_reverse.c	make_push.c\
				free_func.c		error.c				ft_printf.c

SRCS_B		=	push_swap_bonus.c

HEADER		=	push_swap.h

HEADER_B	=	push_swap_bonus.h

OBJS		=	$(patsubst %.c,%.o,$(SRCS))

OBJS_B		=	$(patsubst %.c,%.o,$(SRCS_B))

D_FILES		=	$(patsubst %.c,%.d,$(SRCS))

D_FILES_B	=	$(patsubst %.c,%.d,$(SRCS_B))

INCLUDES	=	-I.

CFLAGS		=	-Wall -Wextra -Werror

CC			=	gcc

RM			=	rm -rf

LIB			=	./libft/libft.a

YELLOW		=	"\033[1;33m"
GREEN		=	"\033[1;32m"
END			=	"\033[0m"

.PHONY		:	all bonus libft clean fclean re rebonus

all			:	libft $(NAME)

libft		:	
				$(MAKE) -C $(dir $(LIB))

%.o			:	%.c $(HEADER)
				$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ -MD

$(NAME)		:	$(OBJS) $(LIB)
ifeq 			($(strip $(SRCS)),$(strip $(SRCS_B)))
				$(CC) $(CFLAGS) $(INCLUDES) $(LIB) -o $(NAME) $(OBJS)
				@echo ${GREEN} "\n\tPush_swap bonus is compiled\n" ${END}
else
				@$(RM) $(OBJS_B) $(D_FILES_B)
				$(CC) $(CFLAGS) $(INCLUDES) $(LIB) -o $(NAME) $(OBJS)
				@echo ${GREEN} "\n\tPush_swap is compiled\n" ${END}
endif

bonus		:	
				@$(RM) $(OBJS) $(D_FILES)
				@make SRCS='$(SRCS_B)' HEADER='$(HEADER_B)'

clean		:	
				@$(RM) $(OBJS) $(OBJS_B) $(D_FILES) $(D_FILES_B)
				@$(MAKE) -C $(dir $(LIB)) clean
				@echo ${YELLOW} "\n\tPush_swap 'clean' status: DONE\n" ${END}
				
fclean		:	clean
				@$(RM) $(NAME)
				@$(MAKE) -C $(dir $(LIB)) fclean
				@echo ${YELLOW} "\n\tPush_swap 'fclean' status: DONE\n" ${END}

re			:	fclean all

rebonus		:	fclean bonus