/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 08:14:12 by agabrie           #+#    #+#             */
/*   Updated: 2018/08/31 12:08:00 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			main(int ac, char **av)
{
	t_ps		ps;
	char		*line;
	int			moves;

	if (ac > 1)
	{
		moves = 0;
		init(&ps, av, ac);
		line = malloc(10);
		while (gnl(0, &line))
		{
			rule(&ps.a, &ps.b, line, ps.debug);
			free(line);
			moves++;
		}
		col_str_fd(FYEL, "Number of Moves : ", 2);
		ft_nbrendl_fd(moves, 2);
		check_sorted(&ps.a, &ps.b);
	}
	return (0);
}
