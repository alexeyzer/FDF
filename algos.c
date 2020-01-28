/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiller <aguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 18:39:04 by ehell             #+#    #+#             */
/*   Updated: 2020/01/28 18:01:23 by aguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

t_koord **malloc_massiv(int x, int y)
{
    int         i;
    t_koord     **massive;

    i = 0;
    if (!(massive = (t_koord**)(malloc(sizeof(t_koord**) * y))))
        return (NULL);
    while (i < y)
    {
        if (!(massive[i] = (t_koord*)(malloc(sizeof(t_koord) * x))))
            return (NULL);
        i++;
    }
    return (massive);
}

void parser(int fd, t_koord **massive)
{
    char *line;
    int i;
    int j;
    int k;

    i = 0;
    while (get_next_line(fd, &line))
    {
        j = 0;
        k = 0;
        while (line[j])
        {
            if (line[j] != ' ')
            {
                massive[i][k].old_z = ft_atoi(&(line[j]));
                k++;
                while (line[j] != ' ' && line[j])
                    j++;
            }
            else
                j++;
        }
        i++;
        free(line);
    }
}

void to_iso(t_koord **massive, int y, int x)
{
    //massive[y][x].new_x = (x - y) * cos(0.523599);
    massive[y][x].new_x = x;
    //massive[y][x].new_y = massive[y][x].old_z + (x + y) * sin(0.523599);
    massive[y][x].new_y = y;
}

void try_to_print(t_koord **massive, int x, int y)
{
    void	*mlx_ptr;
	void	*win_ptr;
    int i;
    int j;

    i = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 200, 200, "first");
    while(i < y)
    {
        j = 0;
        while(j < x)
        {
            if (massive[i][j + 1].new_x)
                brezen_alg(massive[i][j], massive[i][j + 1], mlx_ptr, win_ptr);
            if (massive[i + 1][j].new_x)
                brezen_alg(massive[i][j], massive[i + 1][j], mlx_ptr, win_ptr);
            j++;
        }
        i++;
    }
    mlx_loop(mlx_ptr);
}
int read_tomass(int len_x, int len_y, int fd)
{
    t_koord **massive;
    int     i;
    int     j;

    massive = malloc_massiv(len_x, len_y);
    parser(fd, massive);
    i = 0;
    while(i < len_y)
    {
        j = 0;
        while(j < len_x)
        {
            to_iso(massive, i, j);
            j++;
        }
        i++;
    }
    try_to_print(massive, len_x, len_y);
    return (0);
}

void brezen_alg(t_koord point1, t_koord point2, void *mlx_ptr, void *win_ptr)
{
    int err;
    int diry;
    t_koord point;
  
    point = point1;
    err = 0;
    if (point2.new_y - point1.new_y >= 0)
        diry = 1;
    if (point2.new_y - point1.new_y < 0)
        diry = -1;
    while (point.new_x <= point2.new_x)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, point.new_x, point.new_y, 0xFFFFFF);
        err = err + abs(point1.new_x - point2.new_y) + 1;
        if (err >= abs(point1.new_x - point2.new_x) + 1)
        {
            point.new_y = point.new_y + diry;
            err = err - (abs(point1.new_x - point2.new_x) + 1);
        }
        point.new_x++;
    }
}