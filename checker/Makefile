# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/15 08:15:41 by agabrie           #+#    #+#              #
#    Updated: 2018/08/27 12:57:05 by agabrie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= checker.a

CNAME	= ../check

SRCS	= stack_ops.c a_ops.c b_ops.c both_ops.c checker.c arguments.c

OBJS	= $(SRCS:.c=.o)

LIBFT	= ../libft/libft.a

GCC		= gcc -Wall -Werror -Wextra -g

all : $(NAME)

$(NAME) :
		@$(GCC) -c $(SRCS)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)
		@echo "Library [$(NAME)] updated!"

clean:
		@/bin/rm -rf $(OBJS)

libclean:
		@/bin/rm -rf $(NAME)

checkerclean:
		@/bin/rm -rf $(CNAME)

fclean: clean libclean

allclean : clean libclean checkerclean
		make allclean -C ../libft

re: allclean all ccompile
		@make fclean

ccompile:
		@make re -C ../libft
		@$(GCC) main.c $(NAME) $(LIBFT) -o $(CNAME)
