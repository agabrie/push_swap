# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/03 11:21:00 by agabrie           #+#    #+#              #
#    Updated: 2018/09/03 11:47:44 by agabrie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make all -C pswap
	@make all -C check

re:
	@make re -C pswap
	@make re -C check

clean:
	@make clean -C pswap
	@make clean -C check

fclean:
	@make fclean -C pswap
	@make fclean -C check

pcompile:
	@make pcompile -C pswap

ccompile:
	@make ccompile -C check

libclean:
	@make libclean -C pswap
	@make libclean -C check

psclean:
	@make psclean -C pswap

checkerclean:
	@make checkerclean -C check

allclean:
	@make allclean -C pswap
	@make allclean -C check

ps:
	@make ps -C pswap

ch:
	@make ch -C check