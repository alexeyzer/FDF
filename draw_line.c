/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:25:25 by alexzudin         #+#    #+#             */
/*   Updated: 2020/01/29 11:57:27 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_for_horizontal(t_koord point0, t_koord point1, void *mlx_ptr, void *win_ptr)
{
	int err;
    int diry;
    t_koord point;
  
    point = point0;
    err = 0;
    if (point1.new_y - point0.new_y >= 0)
        diry = 1;
    while (point.new_x <= point1.new_x)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, point.new_x, point.new_y, 0xFFFFFF);
        err = err + abs(point0.new_y - point1.new_y) + 1;
        if (err >= abs(point0.new_x - point1.new_x) + 1)
        {
            point.new_y = point.new_y + diry;
            err = err - (abs(point0.new_x - point1.new_x) + 1);
        }
        point.new_x++;
    }

}

void draw_for_vertical(t_koord point0, t_koord point1, void *mlx_ptr, void *win_ptr)
{
	int err;
    int diry;
    t_koord point;
  
    point = point0;
    err = 0;
    if (point1.new_x - point0.new_x >= 0)
        diry = 1;
    while (point.new_y <= point1.new_y)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, point.new_x, point.new_y, 0xFFFFFF);
        err = err + abs(point0.new_x - point1.new_x) + 1;
        if (err >= abs(point0.new_y - point1.new_y) + 1)
        {
            point.new_x = point.new_x + diry;
            err = err - (abs(point0.new_y - point1.new_y) + 1);
        }
        point.new_y++;
    }

}

void draw(t_koord point0, t_koord point1, void *mlx_ptr, void *win_ptr)
{
    int dx;
    int dy;

    dx = point1.new_x - point0.new_x;
    dy = point1.new_y - point0.new_y;
    if (abs(dx) > abs(dy))
    {
        if (point0.new_x >point1.new_x)
			draw_for_horizontal(point1, point0, mlx_ptr, win_ptr);
		else
			draw_for_horizontal(point0, point1, mlx_ptr, win_ptr);
    }
	else
	{
		if (point0.new_y >point1.new_y)
			draw_for_vertical(point1, point0, mlx_ptr, win_ptr);
		else
			draw_for_vertical(point0, point1, mlx_ptr, win_ptr);

	}
}