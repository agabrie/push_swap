/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 08:14:12 by agabrie           #+#    #+#             */
/*   Updated: 2018/09/03 08:23:58 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			main(int ac, char **av)
{
	t_psv		psv;
	t_ps		ps;
	t_vis		vis;

	if (ac > 1)
	{
		if (ft_strequ(av[1], "-v"))
		{
			visinit(&ps, av, ac);
			psv.ps = &ps;
			setup_vis(&vis, &ps);
			psv.vis = &vis;
			draw_graph(&vis, &ps);
			mlx_key_hook(vis.win, key_event, &psv);
			mlx_loop_hook(vis.gsci, vcheck, &psv);
			mlx_loop(vis.gsci);
		}
		else
		{
			init(&ps, av, ac);
			check(&ps);
		}
		check_sorted(&ps.a, &ps.b);
	}
	exit(0);
}
