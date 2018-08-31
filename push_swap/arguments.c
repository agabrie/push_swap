/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:45:27 by agabrie           #+#    #+#             */
/*   Updated: 2018/08/31 10:42:36 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rule(t_stackdata *a, t_stackdata *b, char *line)
{
	if (ft_strequ(line, "sa"))
		sa(a);
	else if (ft_strequ(line, "sb"))
		sb(b);
	else if (ft_strequ(line, "ss"))
		ss(a, b);
	else if (ft_strequ(line, "pa"))
		pa(a, b);
	else if (ft_strequ(line, "pb"))
		pb(a, b);
	else if (ft_strequ(line, "ra"))
		ra(a);
	else if (ft_strequ(line, "rb"))
		rb(b);
	else if (ft_strequ(line, "rr"))
		rr(a, b);
	else if (ft_strequ(line, "rra"))
		rra(a);
	else if (ft_strequ(line, "rrb"))
		rrb(b);
	else if (ft_strequ(line, "rrr"))
		rrr(a, b);
	else
	{
		if(ft_strequ(line, ""))
			col_endl_fd(FYEL, "THIS HERE IS NOT FOR THE PROGRAM ITSELF 2", 2);
		else
			col_endl_fd(FYEL, line, 2);
		MESSAGE("ERROR", FRED);
	}
	//printbothstacks(a, b);
}

void		windows_tests(t_stackdata *a, t_stackdata *b)
{
	rule(a, b, "rra");
	rule(a, b, "pb");
	rule(a, b, "sa");
	rule(a, b, "rra");
	rule(a, b, "pa");
}

void	initialise(t_ps *ps)
{
	ps->debug = 0;
	ps->a.size = 0;
	ps->b.size = 0;
	ps->a.lst = NULL;
	ps->b.lst = NULL;
}

void		init(t_ps *ps, char **av, int ac)
{
	int				i;
	char			**args;
	t_stackdata		temp;

	args = (char**)malloc(sizeof(char *) * ac);
	arrcpy(av, args);
	i = 1;
	initialise(ps);
	if (ac == 2)
	{
		freearray(args);
		args = ft_strsplit(av[1], ' ');
		ARRLEN(args, ac);
	}
	check_dups(args);
	while (ac - (i + 1) >= (0) && ac - (i + 1) < ac)
	{
		if (!ft_isnum(args[ac - (i + 1)]))
		{
			ERR();
		}
		push(&ps->a, ft_atoi(args[ac - (i + 1)]));
		i++;
	}
	temp_stack(&temp, lst_size(&ps->a));
	freearray(args);
	ps->a = normalise(&temp, lst_size(&ps->a), &ps->a);
}
