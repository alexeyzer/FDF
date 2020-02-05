/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiller <aguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:23:50 by aguiller          #+#    #+#             */
/*   Updated: 2020/02/05 13:31:53 by aguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int event_key(int key, t_app *app)
{
    app->height = 500;
    if (key == 53)
        exit(0);
    if (key == 35)
        app->projection = 'p';
    if (key == 34)
        app->projection = 'I';
    if (key == 24)
        app->zoom = app->zoom + 1;
    if (key == 27)
        app->zoom = app->zoom - 1;
    return (reprint(app));
}

int reprint(t_app *app)
{
    erease(app);
    if (app->projection == 'I')
        to_iso(app->massive, app);
    else
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

void erease(t_app *app)
{
    app->color = 0;
    try_to_print(app->massive, app);
    app->color = 0xFFFFFF;
}