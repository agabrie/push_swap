/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 13:37:13 by agabrie           #+#    #+#             */
/*   Updated: 2018/09/02 22:20:20 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void    drawsolidrect(t_point *start, t_point *end, t_vis *vis)
{
    int x;
    int y;

    y = start->y;
    while(y >= end->y)
    {
        x = start->x;
        while(x <= end->x)
        {
            mlx_pixel_put(vis->gsci, vis->win, x, y, WHITEAF);
            x++;
        }
        y--;
    }
}

void    drawbars(t_point *start, t_point *end, t_stackdata *stack, t_vis *vis)
{
    t_point strt;
    t_point nd;
    t_stack *head;
    
    if(!stack->lst)
        return ;
    head = stack->lst;
    //strt = set_point(400, 10);
    //nd = set_point(200, 80); 
    /*strt = set_point(end->y - 2, start->x + 2);
    col_str_fd(FYEL, "strt stuff : ", 2);
    ft_nbrendl_fd(strt.y, 2);
    col_str_fd(FYEL, "lv stuff : ", 2);
    ft_nbrendl_fd(vis->lv, 2);
    col_str_fd(FYEL, "ls stuff : ", 2);
    ft_nbrendl_fd(vis->ls, 2);
    col_str_fd(FYEL, "gsy stuff : ", 2);
    ft_nbrendl_fd(vis->gsy, 2);
    ft_putchar_fd('\n', 2);
    */
    //nd = set_point(head->value * vis->bs.x, strt.x + vis->bs.x);
    int i;
    i = 0;
   while(head)
    {
        vis->lv = head->value;
       // col_str_fd(FYEL, "value of bar : ", 2);
        //ft_nbrendl_fd(vis->lv, 2);
        
        strt = set_point(end->y - 2, start->x + 2 + i);
        nd = set_point(strt.y - head->value * vis->bs.x, strt.x + vis->bs.x);
        /*col_str_fd(FCYN, "head value : ", 2);
        ft_nbrendl_fd(head->value, 2);
        col_str_fd(FCYN, "start coords : ", 2);
        put_coords_fd(&strt, 2);
        col_str_fd(FCYN, "end coords :   ", 2);
        put_coords_fd(&nd, 2);
        */drawsolidrect(&strt, &nd, vis);
      //  return ;
        head = head->next;
        i += vis->bs.x;
    }
    //ft_putchar_fd('\n', 2);
}

void    draw_frames(t_vis *vis, t_ps *ps)
{
    t_point start;
    t_point end;

    start = set_point(4, 4);
    end = set_point(vis->fr.y + 4, vis->fr.x + 4);
    draw_rectangle(vis, &start, &end);
    drawbars(&start, &end, &ps->a, vis);
    start = set_point(start.y , end.x + vis->sbf);
    end = set_point(end.y, start.x + vis->fr.x);
    draw_rectangle(vis, &start, &end);
    drawbars(&start, &end, &ps->b, vis);
}

/*void    draw_bars_a(t_ps *ps, )
{
    t_point start;
    t_point end;
    start = set_point(4, 4);
    end = set_point(vis->fr.y + 4, vis->fr.x + 4);
    draw_rectangle(vis, &start, &end);
    if(ps)
        return ;
    return ;
}

void    draw_bars_b()
{
    return ;
}
*/
void    draw_graph(t_vis *vis, t_ps *ps)
{
    mlx_clear_window(vis->gsci, vis->win);
    draw_frames(vis, ps);
   // draw_bars_a(ps);
}