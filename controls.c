/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehell <ehell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:23:50 by aguiller          #+#    #+#             */
/*   Updated: 2020/02/06 15:20:12 by ehell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int event_key(int key, t_app *app)
{
    if (key == 53)
        exit(quit(app));
    if (key == 35)
    {
        app->projection = 'P';
        choose_zoom(app, app->massive);
    }
    if (key == 34)
    {
        choose_zoom(app, app->massive);
        app->projection = 'I';
    }
    if (key == 24)
        app->zoom = app->zoom + 1;
    if (key == 27)
        app->zoom = app->zoom - 1;
    if (key == 13)
        app->py = app->py - 3;
    if (key == 1)
        app->py = app->py + 3;
    if (key == 2)
        app->px = app->px + 3;
    if (key == 0)
        app->px = app->px - 3;
    return (reprint(app));
}

int reprint(t_app *app)
{
    if (app->projection == 'I')
        to_iso(app->massive, app);
    if (app->projection == 'P')
        to_paralell(app->massive, app);
    try_to_print(app->massive, app);
    return (0);
}

int quit(t_app *app)
{
    t_koord **massive;
    int i;  

    massive = app->massive;
    i = 0;
    while (i < app->max_y)
    {
        free(massive[i]);
        i++;
    }
    mlx_destroy_image(app->mlx_ptr, app->im_ptr);
    mlx_destroy_window(app->mlx_ptr, app->win_ptr);
    free(massive);
    free (app);
    return (0);
}

void    make_menu(t_app *app)
{
    mlx_string_put(app->mlx_ptr, app->win_ptr, 5, 5, 0xFFFFFF, "MENU");
    mlx_string_put(app->mlx_ptr, app->win_ptr, 5, 20, 0xFFFFFF, "'I' - iso");
    mlx_string_put(app->mlx_ptr, app->win_ptr, 5, 35, 0xFFFFFF, "'P' - parallel");
    mlx_string_put(app->mlx_ptr, app->win_ptr, 5, 50, 0xFFFFFF, "'+' - increase");
    mlx_string_put(app->mlx_ptr, app->win_ptr, 5, 65, 0xFFFFFF, "'-' - decrease");
    mlx_string_put(app->mlx_ptr, app->win_ptr, 5, 80, 0xFFFFFF, "'W' - upward");
    mlx_string_put(app->mlx_ptr, app->win_ptr, 5, 95, 0xFFFFFF, "'S' - down");
    mlx_string_put(app->mlx_ptr, app->win_ptr, 5, 110, 0xFFFFFF, "'A' - left");
    mlx_string_put(app->mlx_ptr, app->win_ptr, 5, 125, 0xFFFFFF, "'D' - right");
}

void    choose_zoom(t_app *app, t_koord **massive)
{
    int dx;
    int dy;

    app->zoom = 10;
    dx = - ((app->width - 200) / 2 + ((0 - app->max_y) * cos(0.523599)) * app->zoom)
   + (app->width - 200) / 2 + ((app->max_x - 0) * cos(0.523599)) * app->zoom;
    dy = - (app->height / 2 + (-massive[0][0].old_z))
    + app->height / 2 + (-massive[app->max_y - 1][app->max_x - 1].old_z + ((app->max_x + app->max_y) * sin(0.523599))) * app->zoom;
    dy += abs(app->max_z - app->min_z) * app->zoom;
       if (dx > dy)
         app->zoom = (app->width - 200) / dx * app->zoom;
       else if (dx < dy)
            app->zoom = app->height / dy * app->zoom;
      if (app->zoom == 0)
         app->zoom = 1;
    // if (dy - abs(app->max_z - app->min_z) * app->zoom < abs(app->max_z - app->min_z) * app->zoom)
    // {
    //     if (app->max_z > app->min_z)
    //         app->cent_y = dy / 2;
    //     else
    //         app->cent_y = -dy / 2;        
    // }
//     app->cent_x = (-((0 - app->max_y) * cos(0.523599) * app->zoom)
//    + ((app->max_x - 0) * cos(0.523599) * app->zoom)) / 2;
    // ft_putnbr(app->cent_y);
    // ft_putnbr(app->cent_x);
}