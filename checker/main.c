/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 08:14:12 by agabrie           #+#    #+#             */
/*   Updated: 2018/09/02 22:13:01 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#define V (vis)

void setup_vis(t_vis *vis, t_ps *ps)
{
	V->lv = 0;//
	//col_endl_fd(FRED, "Here 1",2);
	V->gsci = mlx_init();//
	//col_endl_fd(FRED, "Here 2",2);
	V->ws.y = 500+13;//
	V->gsxt = 500;//
	V->gsy = 500;//
	//col_endl_fd(FRED, "Here 3",2);
	V->ls = ps->size;//
	//ft_nbrendl_fd(V->ls, 2);
	//col_endl_fd(FRED, "Here 4",2);
	V->sbf = 4;//
	V->fr.y = 504;//
	//col_endl_fd(FRED, "Here 5",2);
	V->bs.x = ((V->gsxt/V->ls < 1) ? 1 : (V->gsxt/V->ls));//
	//col_endl_fd(FRED, "Here 6",2);
	V->gsxa = V->bs.x * V->ls;//
	//col_endl_fd(FRED, "Here 7",2);
	V->fr.x = V->gsxa + 4;//
	//col_endl_fd(FRED, "Here 8",2);
	V->ws.x = (V->gsxa * 2) + 20;//
	//col_endl_fd(FRED, "Here 9",2);
	V->win = mlx_new_window(V->gsci, V->ws.x, V->ws.y, "Lx PS");//
	//col_endl_fd(FRED, "Here 10",2);
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
	int		i;
	char	**args;
	t_stackdata temp;

	args = (char**)malloc(sizeof(char*) * ac);
	arrcpy(av, args);
	i = 1;
	initialise(ps);
	ps->debug = (ft_strequ(args[0], "-v") ? 1 : 0);
	if (ac == 2 + ps->debug)
	{
		freearray(args);
		if (ps->debug)
			args = ft_strsplit(ft_strjoin("-v ", (av[1 + ps->debug])), ' ');
		else
			args = ft_strsplit(av[1 + ps->debug], ' ');
		ARRLEN(args, ac);
	}
	check_dups(args);
	while (ac - (i + 1) >= (0 + ps->debug) && ac - (i + 1) < ac)
	{
		CHECKNUM();
		push(&ps->a, ft_atoi(args[ac - (i + 1)]));
		i++;
	}
	freearray(args);
	ps->size = (lst_size(&ps->a) + lst_size(&ps->b));
	ps->debug = 0;
	temp_stack(&temp, ps->size);
	ps->a = normalise(&temp, lst_size(&ps->a), &ps->a);
}

int	vcheck(t_psv *psv)
{
	char **line;
	static int moves;
	t_ps *ps;
	t_vis *vis;

	ps = psv->ps;
	vis = psv->vis;
	moves = 0;
	line = malloc(10);
	*line = malloc(10);
	ft_memdel((void *)line);

	if (g_n_l(0, line) > 0)
	{
		/*if(!moves)
		{
			while(1){}
		}*/
		rule(&ps->a, &ps->b, *line, ps->debug);
		if(ps->size < 1274)
				draw_graph(vis, ps);
		ft_memdel((void *)line);
		moves++;
	}
	free(line);
	if (ps->debug)
		MOVES();
	//check_sorted(&ps->a, &ps->b);
	return(0);
}

void	check(t_ps *ps)
{
	char **line;
	int moves;

	moves = 0;
	line = malloc(10);
	*line = malloc(10);
	ft_memdel((void *)line);

	while (g_n_l(0, line) > 0)
	{
		rule(&ps->a, &ps->b, *line, ps->debug);
		ft_memdel((void *)line);
		moves++;
	}
	free(line);
	if (ps->debug)
		MOVES();
}

int	key_event(int key_code/*, void *param*/)
{
	if(key_code == 53)
		exit(0);
	return (0);
}

int			main(int ac, char **av)
{
	t_psv		psv;
	t_ps		ps;
	//char		**line;
	//int			moves;
	t_vis		vis;

	if (ac > 1)
	{
		//moves = 0;
		if (ft_strequ(av[1], "-v"))
		{
			
			
			visinit(&ps, av, ac);
			psv.ps = &ps;
			setup_vis(&vis, &ps);
			psv.vis = &vis;
			draw_graph(&vis, &ps);
			mlx_key_hook(vis.win, key_event, 0);
			mlx_loop_hook(vis.gsci, vcheck, &psv);
			mlx_loop(vis.gsci);
		}
		else
		{
			init(&ps, av, ac);
			check(&ps);
		}
		/*line = malloc(10);
		*line = malloc(10);
		ft_memdel((void *)line);
		//printbothstacks(&ps.a, &ps.b);
		while (g_n_l(0, line) > 0)
		{
			rule(&ps.a, &ps.b, *line, ps.debug);
			if(ft_strequ(av[1], "-v") && ps.size < 1274)
				draw_graph(&vis, &ps);
			ft_memdel((void *)line);
			moves++;
		}
		free(line);
		if (ps.debug)
			MOVES();
		
		
		mlx_loop(vis.gsci);
		*/
	check_sorted(&ps.a, &ps.b);
	}
	
	exit(0);
}
