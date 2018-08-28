/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 08:14:12 by agabrie           #+#    #+#             */
/*   Updated: 2018/08/28 12:17:53 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			main(int ac, char **av)
{
	t_ps		ps;
	char		*line;

	if (ac > 1)
	{
		init(&ps, av, ac);
		line = malloc(10);
		while (get_next_line(0, &line) > 0)
		{
			rule(&ps.a, &ps.b, line, ps.debug);
			free(line);
		}
		if (line)
			free(line);
		check_sorted(&ps.a, &ps.b);
	}
	return (0);
}
