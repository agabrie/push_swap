/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 08:20:40 by agabrie           #+#    #+#             */
/*   Updated: 2018/09/03 08:49:57 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#define LV (vis->lv)
#define GSCI (vis->gsci)
#define WS (vis->ws)
#define GSXT (vis->gsxt)
#define GSY (vis->gsy)
#define LS (vis->ls)
#define SBF (vis->sbf)
#define FR (vis->fr)
#define BS (vis->bs)
#define GSXA (vis->gsxa)
#define WIN (vis->win)

void		setup_vis(t_vis *vis, t_ps *ps)
{
	LV = 0;
	GSCI = mlx_init();
	WS.y = 500 + 13;
	GSXT = 500;
	GSY = 500;
	LS = ps->size;
	SBF = 4;
	FR.y = 504;
	BS.x = ((GSXT / LS < 1) ? 1 : (GSXT / LS));
	GSXA = BS.x * LS;
	FR.x = GSXA + 4;
	WS.x = (GSXA * 2) + 20;
	WIN = mlx_new_window(GSCI, WS.x, WS.y, "Lx PS");
}

void		visinit(t_ps *ps, char **av, int ac)
{
	int			i;
	char		**args;
	t_stackdata temp;

	args = (char**)malloc(sizeof(char*) * ac);
	arrcpy(av, args);
	i = 1;
	initialise(ps);
	if (ac == 3)
	{
		freearray(args);
		args = ft_strsplit(av[2], ' ');
		ARRLEN(args, ac);
	}
	check_dups(args);
	while (ac - (i + 1) >= (0) && ac - (i + 1) < ac)
	{
		CHECKNUM();
		push(&ps->a, ft_atoi(args[ac - (i + 1)]));
		i++;
	}
	freearray(args);
	ps->size = (lst_size(&ps->a) + lst_size(&ps->b));
	temp_stack(&temp, ps->size);
	ps->a = normalise(&temp, lst_size(&ps->a), &ps->a);
}

int			vcheck(t_psv *psv)
{
	t_ps	*ps;
	t_vis	*vis;

	ps = psv->ps;
	vis = psv->vis;
	ft_memdel((void *)(ps->line));
	if (g_n_l(0, ps->line) > 0)
	{
		rule(&ps->a, &ps->b, *ps->line, ps->debug);
		psv->ps->moves++;
		if (ps->size < 1274)
			draw_graph(vis, ps);
		ft_memdel((void *)(ps->line));
	}
	return (0);
}

int			key_event(int key_code, t_psv *psv)
{
	t_ps	*ps;
	t_vis	*vis;

	ps = psv->ps;
	vis = psv->vis;
	if (key_code == 53)
	{
		MOVES();
		check_sorted(&ps->a, &ps->b);
	}
	return (0);
}
