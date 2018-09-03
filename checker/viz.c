/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 13:37:13 by agabrie           #+#    #+#             */
/*   Updated: 2018/09/03 08:08:22 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#define WHITEAF 0x00FFFFFF

void	draw_rectangle(t_vis *vis, t_point *start, t_point *end)
{
	int x;
	int y;

	y = start->y;
	x = start->x;
	while (x <= end->x)
	{
		mlx_pixel_put(vis->gsci, vis->win, x, start->y, WHITEAF);
		mlx_pixel_put(vis->gsci, vis->win, x++, end->y, WHITEAF);
	}
	while (y < end->y)
	{
		mlx_pixel_put(vis->gsci, vis->win, start->x, y, WHITEAF);
		mlx_pixel_put(vis->gsci, vis->win, end->x, y++, WHITEAF);
	}
}

void	drawsolidrect(t_point *start, t_point *end, t_vis *vis)
{
	int x;
	int y;

	y = start->y;
	while (y >= end->y)
	{
		x = start->x;
		while (x <= end->x)
		{
			mlx_pixel_put(vis->gsci, vis->win, x, y, WHITEAF);
			x++;
		}
		y--;
	}
}

void	drawbars(t_point *start, t_point *end, t_stackdata *stack, t_vis *vis)
{
	t_point	strt;
	t_point	nd;
	t_stack	*head;
	int		i;

	if (!stack->lst)
		return ;
	head = stack->lst;
	i = 0;
	while (head)
	{
		vis->lv = head->value;
		strt = set_point(end->y - 2, start->x + 2 + i);
		nd = set_point(strt.y - head->value * vis->bs.x, strt.x + vis->bs.x);
		drawsolidrect(&strt, &nd, vis);
		head = head->next;
		i += vis->bs.x;
	}
}

void	draw_frames(t_vis *vis, t_ps *ps)
{
	t_point start;
	t_point end;

	start = set_point(4, 4);
	end = set_point(vis->fr.y + 4, vis->fr.x + 4);
	draw_rectangle(vis, &start, &end);
	drawbars(&start, &end, &ps->a, vis);
	start = set_point(start.y, end.x + vis->sbf);
	end = set_point(end.y, start.x + vis->fr.x);
	draw_rectangle(vis, &start, &end);
	drawbars(&start, &end, &ps->b, vis);
}

void	draw_graph(t_vis *vis, t_ps *ps)
{
	mlx_clear_window(vis->gsci, vis->win);
	draw_frames(vis, ps);
}
