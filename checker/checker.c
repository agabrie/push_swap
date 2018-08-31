/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:20:44 by agabrie           #+#    #+#             */
/*   Updated: 2018/08/31 12:10:45 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		check_dups(char **av)
{
	int i;
	int j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strequ(av[i], av[j]))
			{
				ERR();
			}
			j++;
		}
		i++;
	}
}

void		printbothstacks(t_stackdata *a, t_stackdata *b)
{
	ft_putendl_fd("", 2);
	col_str_fd(FCYN, CAT("Stack ", CAT(VAR(a), " : ")), 2);
	ft_nbrendl_fd(lst_size(a), 2);
	printstack(a->lst);
	ft_putendl_fd("", 2);
	col_str_fd(FMAG, CAT("Stack ", CAT(VAR(b), " : ")), 2);
	ft_nbrendl_fd(lst_size(b), 2);
	printstack(b->lst);
	ft_putendl_fd("", 2);
}

void		check_sorted(t_stackdata *a, t_stackdata *b)
{
	t_stack *head;

	if (lst_size(b))
	{
		MESSAGE("KO", FRED);
	}
	head = a->lst;
	while (head && head->next)
	{
		if (head->value < head->next->value)
			head = head->next;
		else
		{
			MESSAGE("KO", FRED);
		}
	}
	MESSAGE("OK", FGRN);
}

int			longest_int(t_stack *stack)
{
	t_stack	*head;
	int		longest;

	if (stack)
		head = stack;
	else
		return (0);
	longest = ft_intlen(head->value);
	while (head)
	{
		if (ft_intlen(head->value) > longest)
			longest = ft_intlen(head->value);
		head = head->next;
	}
	return (longest);
}
