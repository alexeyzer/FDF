/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehell <ehell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 18:39:04 by ehell             #+#    #+#             */
/*   Updated: 2020/01/25 18:40:58 by ehell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include "mlx.h"

struct  s_koord
{
    int x;
    int y;
};

void brezen_alg(struct s_koord point1, struct s_koord point2, void *mlx_ptr, void *win_ptr)
{
    int err;
    int diry;
    struct s_koord point;
  
    point = point1;
    err = 0;
    if (point2.y - point1.y >= 0)
        diry = 1;
    if (point2.y - point1.y < 0)
        diry = -1;
    while (point.x <= point2.x)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, point.x, point.y, 0xFFFFFF);
        err = err + abs(point1.y - point2.y) + 1;
        if (err >= abs(point1.x - point2.x) + 1)
        {
            point.y = point.y + diry;
            err = err - (abs(point1.x - point2.x) + 1);
        }
        point.x++;
    }
}