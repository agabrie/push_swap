# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/03 11:21:00 by agabrie           #+#    #+#              #
#    Updated: 2018/09/03 11:31:47 by agabrie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make all -C push_swap
	@make all -C checker

re:
	@make re -C push_swap
	@make re -C checker

clean:
	@make clean -C push_swap
	@make clean -C checker

fclean:
	@make fclean -C push_swap
	@make fclean -C checker

pcompile:
	@make pcompile -C push_swap

ccompile:
	@make ccompile -C checker

libclean:
	@make libclean -C push_swap
	@make libclean -C checker

psclean:
	@make psclean -C push_swap

checkerclean:
	@make checkerclean -C checker

allclean:
	@make allclean -C push_swap
	@make allclean -C checker

ps:
	@make ps -C push_swap

check:
	@make check -C checker