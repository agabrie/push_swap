/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 08:14:12 by agabrie           #+#    #+#             */
/*   Updated: 2018/09/03 10:18:44 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
	t_ps		ps;

	if (ac > 1)
	{
		init(&ps, av, ac);
		if (lst_size(&ps.a) < 20)
		{
			frankenstein(&ps);
			pushbacktoa(&ps);
		}
		else if (lst_size(&ps.a) < 50)
		{
			dtt(&ps);
			backtoa(&ps);
		}
		else
		{
			partition(&ps);
			backtoa(&ps);
		}
		freestack(&ps.a);
	}
	exit(0);
}
