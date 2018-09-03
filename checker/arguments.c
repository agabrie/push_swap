/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:45:27 by agabrie           #+#    #+#             */
/*   Updated: 2018/09/03 08:08:53 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rule(t_stackdata *a, t_stackdata *b, char *line, int debug)
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
		MESSAGE("ERROR", FRED);
	DEBUGIT(a, b, debug, line);
}

void	freestack(t_stackdata *stack)
{
	if (stack->lst)
	{
		while (stack->lst)
		{
			free(stack->lst);
			stack->lst = stack->lst->next;
		}
		free(stack->lst);
	}
}

int		lst_size(t_stackdata *stack)
{
	t_stack *head;
	int		i;

	if (!stack->lst)
		return (0);
	head = stack->lst;
	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

void	initialise(t_ps *ps)
{
	ps->debug = 0;
	ps->a.size = 0;
	ps->b.size = 0;
	ps->a.lst = NULL;
	ps->b.lst = NULL;
	ps->moves = 0;
	ps->line = malloc(10);
	*ps->line = malloc(10);
}

void	init(t_ps *ps, char **av, int ac)
{
	int		i;
	char	**args;

	args = (char**)malloc(sizeof(char*) * ac);
	arrcpy(av, args);
	i = 1;
	initialise(ps);
	ps->debug = (ft_strequ(args[0], "-d") ? 1 : 0);
	if (ac == 2 + ps->debug)
	{
		freearray(args);
		if (ps->debug)
			args = ft_strsplit(ft_strjoin("-d ", (av[1 + ps->debug])), ' ');
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
}
