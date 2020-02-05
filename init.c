/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiller <aguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:06:06 by alexzudin         #+#    #+#             */
/*   Updated: 2020/02/05 12:33:58 by aguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_app *app_init(t_koord **massive, int x, int y)
{
	t_app *app;

	app = (t_app*)malloc(sizeof(t_app));
	if(!(app->mlx_ptr = mlx_init()))
		return (NULL);
	app->width = 500;
	app->height = 500;
	app->zoom = 10;
	app->max_x = x;
	app->max_y = y;
	app->color = 0xFFFFFF;
    app->projection = 'I';
	app->massive = massive;
	if(!(app->win_ptr = mlx_new_window(app->mlx_ptr, app->width, app->height, "fdf")))
		return (NULL);

	return (app);
}

void to_iso(t_koord **massive, t_app *app)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (app->zoom < 0)
        app->zoom = 0;
    while(i < app->max_y)
    {
        j = 0;
        while(j < app->max_x)
        {
            massive[i][j].new_x = app->width / 2 + ((j - i) * cos(0.523599)) * app->zoom;
            massive[i][j].new_y = app->height / 2 + (-massive[i][j].old_z + ((j + i) * sin(0.523599))) * app->zoom;
            j++;
        }
        i++;
    }
}

void to_paralell(t_koord **massive, t_app *app)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (app->zoom < 0)
        app->zoom = 0;
    while(i < app->max_y)
    {
        j = 0;
        while(j < app->max_x)
        {
            massive[i][j].new_x = app->width / 2 + j * app->zoom;
            massive[i][j].new_y = app->height / 2 + i * app->zoom;
            j++;
        }
        i++;
    }
}