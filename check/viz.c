/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 13:37:13 by agabrie           #+#    #+#             */
/*   Updated: 2018/09/03 08:52:52 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#define WHITEAF 0x00FFFFFF
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

void	draw_rectangle(t_vis *vis, t_point *start, t_point *end)
{
	int x;
	int y;

	y = start->y;
	x = start->x;
	while (x <= end->x)
	{
		mlx_pixel_put(GSCI, WIN, x, start->y, WHITEAF);
		mlx_pixel_put(GSCI, WIN, x++, end->y, WHITEAF);
	}
	while (y < end->y)
	{
		mlx_pixel_put(GSCI, WIN, start->x, y, WHITEAF);
		mlx_pixel_put(GSCI, WIN, end->x, y++, WHITEAF);
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
			mlx_pixel_put(GSCI, WIN, x, y, WHITEAF);
			x++;
		}
		y--;
	}
}

void	drawbars(t_point *st, t_point *end, t_stackdata *s, t_vis *vis)
{
	t_point	strt;
	t_point	nd;
	t_stack	*head;
	int		i;

	if (!s->lst)
		return ;
	head = s->lst;
	i = 0;
	while (head)
	{
		LV = head->value;
		strt = set_point(end->y - 2, st->x + 2 + i);
		nd = set_point(strt.y - head->value * BS.x, strt.x + BS.x);
		drawsolidrect(&strt, &nd, vis);
		head = head->next;
		i += BS.x;
	}
}

void	draw_frames(t_vis *vis, t_ps *ps)
{
	t_point start;
	t_point end;

	start = set_point(4, 4);
	end = set_point(FR.y + 4, FR.x + 4);
	draw_rectangle(vis, &start, &end);
	drawbars(&start, &end, &ps->a, vis);
	start = set_point(start.y, end.x + SBF);
	end = set_point(end.y, start.x + FR.x);
	draw_rectangle(vis, &start, &end);
	drawbars(&start, &end, &ps->b, vis);
}

void	draw_graph(t_vis *vis, t_ps *ps)
{
	mlx_clear_window(vis->gsci, vis->win);
	draw_frames(vis, ps);
}
