/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 08:14:12 by agabrie           #+#    #+#             */
/*   Updated: 2018/09/02 14:27:45 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#define V (vis)

void setup_vis(t_vis *vis, t_ps *ps)
{
	V->lv = 0;//
	V->gsci = mlx_init();//
	V->ws.y = 1013;//
	V->gsxt = 500;//
	V->gsy = 500;//
	V->ls = ps->size;//
	V->sbf = 1;//
	V->fr.y = 504;//

	V->bs.x = ((V->gsxt/V->ls < 1) ? 1 : V->gsxt/V->ls);//
	V->gsxa = V->bs.x * V->ls;//
	V->fr.x = V->gsxa + 4;//
	
	V->ws.x = (V->gsxa * 2) + 13;//
	V->win = mlx_new_window(V->gsci, V->ws.x, V->ws.y, "Lx PS");//
}

int			main(int ac, char **av)
{
	t_ps		ps;
	char		**line;
	int			moves;
	t_vis		vis;

	if (ac > 1)
	{
		moves = 0;
		init(&ps, av, ac);
		line = malloc(10);
		*line = malloc(10);
		ft_memdel((void *)line);
		setup_vis(&vis, &ps);
		while (g_n_l(0, line) > 0)
		{
			rule(&ps.a, &ps.b, *line, ps.debug);
			if(ft_strequ(av[3], "-v") && ps.size < 1276)
				draw_graph(&vis, &ps);
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
