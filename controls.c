/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiller <aguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:23:50 by aguiller          #+#    #+#             */
/*   Updated: 2020/02/05 12:40:51 by aguiller         ###   ########.fr       */
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

int quit(app t_app)
{

}

void erease(t_app *app)
{
    app->color = 0;
    try_to_print(app->massive, app);
    app->color = 0xFFFFFF;
}