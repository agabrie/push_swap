/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 08:14:12 by agabrie           #+#    #+#             */
/*   Updated: 2018/09/03 08:08:21 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#define V (vis)

void	setup_vis(t_vis *vis, t_ps *ps)
{
	V->lv = 0;
	V->gsci = mlx_init();
	V->ws.y = 500 + 13;
	V->gsxt = 500;
	V->gsy = 500;
	V->ls = ps->size;
	V->sbf = 4;
	V->fr.y = 504;
	V->bs.x = ((V->gsxt / V->ls < 1) ? 1 : (V->gsxt / V->ls));
	V->gsxa = V->bs.x * V->ls;
	V->fr.x = V->gsxa + 4;
	V->ws.x = (V->gsxa * 2) + 20;
	V->win = mlx_new_window(V->gsci, V->ws.x, V->ws.y, "Lx PS");
}

t_stackdata	normalise(t_stackdata *temp, int size, t_stackdata *a)
{
	t_stack	*head;
	t_stack	*node;
	int		i;
	int		j;
	t_stack	*temphold;

	i = 0;
	temphold = temp->lst;
	while (i++ < size)
	{
		j = 1;
		head = a->lst;
		node = a->lst;
		while (j++ < i)
			node = node->next;
		while (head)
		{
			if (head->value > node->value)
				temphold->value--;
			head = head->next;
		}
		temphold = temphold->next;
	}
	freestack(a);
	return (*temp);
}

void	temp_stack(t_stackdata *temp, int size)
{
	int i;

	i = 0;
	temp->lst = NULL;
	while (i++ < size)
		push(temp, size);
	temp->size = lst_size(temp);
}

void	visinit(t_ps *ps, char **av, int ac)
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

int		vcheck(t_psv *psv)
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

void	check(t_ps *ps)
{
	ft_memdel((void *)ps->line);

	while (g_n_l(0, ps->line) > 0)
	{
		rule(&ps->a, &ps->b, *ps->line, ps->debug);
		ft_memdel((void *)ps->line);
		ps->moves++;
	}
	free(ps->line);
	if (ps->debug)
		MOVES();
}

int	key_event(int key_code, t_psv *psv)
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
