/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 08:14:12 by agabrie           #+#    #+#             */
/*   Updated: 2018/08/28 17:09:12 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			main(int ac, char **av)
{
	t_ps		ps;
	char		*line;
	int moves;

	if (ac > 1)
	{
		moves = 0;
		init(&ps, av, ac);
		line = malloc(10);
		while (get_next_line(0, &line) > 0)
		{
			if(ft_strcmp(line, ""))
			{
				rule(&ps.a, &ps.b, line, ps.debug);
				moves++;
			}
			else
				break ;
		}
		//free(line);
		col_str_fd(FYEL, "Number of Moves : ", 2);
		ft_nbrendl_fd(moves, 2);
		check_sorted(&ps.a, &ps.b);
	}
	return (0);
}
