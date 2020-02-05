/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehell <ehell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:23:50 by aguiller          #+#    #+#             */
/*   Updated: 2020/02/05 16:42:10 by ehell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int event_key(int key, t_app *app)
{
    if (key == 53)
        exit(quit(app));
    if (key == 35)
        app->projection = 'p';
    if (key == 34)
        app->projection = 'I';
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
    free(massive);
    free (app);
    return (0);
}
/*
void erease(t_app *app)
{
    app->color = 0;
    try_to_print(app->massive, app);
    app->color = 0xFFFFFF;
}*/