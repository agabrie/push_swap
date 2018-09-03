# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/15 08:15:41 by agabrie           #+#    #+#              #
#    Updated: 2018/09/03 11:44:32 by agabrie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap.a

CNAME	=	../push_swap

SRCS	=	stack_ops.c a_ops.c b_ops.c both_ops.c push_swap.c arguments.c \
			values.c extra.c extra2.c algorithm.c

OBJS	=	$(SRCS:.c=.o)

LIBFT	=	../libft/libft.a

GCC		=	gcc -Wall -Werror -Wextra -g

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

psclean:
		@/bin/rm -rf $(CNAME)

fclean: clean libclean

allclean : clean libclean psclean
		make allclean -C ../libft

re: allclean all pcompile
		@make fclean

pcompile:
		@make re -C ../libft
		@$(GCC) main.c $(NAME) $(LIBFT) -o $(CNAME)

ps: all pcompile libclean clean