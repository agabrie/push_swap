/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 13:37:13 by agabrie           #+#    #+#             */
/*   Updated: 2018/09/02 14:50:30 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "checker.h"
#define WHITEAF 0x00FFFFFF
void    draw_rectangle(t_vis *vis, t_point *start, t_point *end)
{
    int x = start->x;
    int y = start->y;

    while(x <= end->x)
    {
        mlx_pixel_put(vis->gsci, vis->win, x, start->y, WHITEAF);
        mlx_pixel_put(vis->gsci, vis->win, x++, end->y, WHITEAF);
    }
    while(y < end->y)
    {
        mlx_pixel_put(vis->gsci, vis->win, start->x, y, WHITEAF);
        mlx_pixel_put(vis->gsci, vis->win, end->x, y++, WHITEAF);
    }
}

void    draw_frames(t_vis *vis)
{
    t_point start;
    t_point end;
    start = set_point(2, 2);
    end = set_point(vis->fr.y + 2, vis->fr.x + 2);
    draw_rectangle(vis, &start, &end);
}

void    draw_bars_a()
{

}

void    draw_bars_b()
{

}

void    draw_graph(t_vis *vis, t_ps *ps)
{
    if(ps->a.lst)
        return ;
    return ;
    mlx_clear_window(vis->gsci, vis->win);
}