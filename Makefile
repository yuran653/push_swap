# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 01:09:45 by jgoldste          #+#    #+#              #
#    Updated: 2022/03/29 17:28:02 by jgoldste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

NAME_B		=	checker

SRCS		=	push_swap.c			parse_argv.c		get_number.c\
				init_stack.c		free_error_func.c	ft_printf.c\
				make_swap.c			make_push.c			make_rotate_reverse.c\
				sort_insert.c		sort_utils.c\
				sort_upto_five.c	sort_more_five.c

SRCS_B		=	checker.c			parse_argv.c		get_number.c\
				init_stack.c		free_error_func.c	ft_printf.c		sort_utils.c\
				make_swap_bonus.c	make_push_bonus.c	make_rotate_reverse_bonus.c\
				$(GNL)get_next_line.c	$(GNL)get_next_line_utils.c

HEADER		=	push_swap.h

HEADER_B	=	checker.h

OBJS		=	$(patsubst %.c,%.o,$(SRCS))

OBJS_B		=	$(patsubst %.c,%.o,$(SRCS_B))

D_FILES		=	$(patsubst %.c,%.d,$(SRCS))

D_FILES_B	=	$(patsubst %.c,%.d,$(SRCS_B))

INCLUDES	=	-I.

CFLAGS		=	-Wall -Wextra -Werror

CC			=	gcc

RM			=	rm -rf

LIB			=	./libft/libft.a

GNL			=	./get_next_line/

YELLOW		=	"\033[1;33m"
GREEN		=	"\033[1;32m"
END			=	"\033[0m"

.PHONY		:	all bonus libft clean fclean re rebonus

all			:	libft $(NAME)

bonus		:	libft $(NAME_B)

libft		:	
				$(MAKE) -C $(dir $(LIB))

%.o			:	%.c $(HEADER)
				$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ -MD

$(NAME)		:	$(OBJS) $(LIB)
				$(CC) $(CFLAGS) $(INCLUDES) $(LIB) -o $(NAME) $(OBJS)
				@echo ${GREEN} "\n\tPush_swap is compiled\n" ${END}

$(NAME_B)	:	$(OBJS_B) $(LIB)
				$(CC) $(CFLAGS) $(INCLUDES) $(LIB) -o $(NAME_B) $(OBJS_B)
				@echo ${GREEN} "\n\tChecker is compiled\n" ${END}

clean		:	
				@$(RM) $(OBJS) $(OBJS_B) $(D_FILES) $(D_FILES_B)
				@$(MAKE) -C $(dir $(LIB)) clean
				@echo ${YELLOW} "\n\tPush_swap 'clean' status: DONE\n" ${END}
				
fclean		:	clean
				@$(RM) $(NAME) $(NAME_B)
				@$(MAKE) -C $(dir $(LIB)) fclean
				@echo ${YELLOW} "\n\tPush_swap 'fclean' status: DONE\n" ${END}

re			:	fclean all

rebonus		:	fclean bonus