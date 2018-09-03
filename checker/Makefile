# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/15 08:15:41 by agabrie           #+#    #+#              #
#    Updated: 2018/09/03 11:28:36 by agabrie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= checker.a

CNAME	= ../check

SRCS	= stack_ops.c a_ops.c b_ops.c both_ops.c checker.c arguments.c viz.c\
		  vizinit.c normalise.c

OBJS	= $(SRCS:.c=.o)

LIBFT	= ../libft/libft.a

GCC		= gcc -Wall -Werror -Wextra -g

FRWORK	= -framework OpenGL -framework AppKit

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
		@$(GCC) main.c $(NAME) $(LIBFT) -lmlx $(FRWORK) -o $(CNAME)

check: ccompile libclean