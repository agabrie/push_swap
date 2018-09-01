/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zee <zee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 08:14:12 by agabrie           #+#    #+#             */
/*   Updated: 2018/09/01 08:12:04 by zee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			main(int ac, char **av)
{
	t_ps		ps;
	char		**line;
	int			moves;

	if (ac > 1)
	{
		moves = 0;
		init(&ps, av, ac);
		line = malloc(10);
		*line = malloc(10);
		ft_memdel((void *)line);
		while (g_n_l(0, line) > 0)
		{
			rule(&ps.a, &ps.b, *line, ps.debug);
			ft_memdel((void *)line);
			moves++;
		}
		free(line);
		if (ps.debug)
			MOVES();
		check_sorted(&ps.a, &ps.b);
	}
	exit(0);
}
