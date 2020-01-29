/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 18:39:04 by ehell             #+#    #+#             */
/*   Updated: 2020/01/29 14:59:52 by alexzudin        ###   ########.fr       */
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
    massive[y][x].new_x = 250 + ((x - y) * cos(0.523599)) * 20;
    massive[y][x].new_y = 250 + (-massive[y][x].old_z + ((x + y) * sin(0.523599))) * 20;
}

void try_to_print(t_koord **massive, int x, int y)
{
    void	*mlx_ptr;
	void	*win_ptr;
    int i;
    int j;

    i = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "first");
    while(i < y)
    {
        j = 0;
        while(j < x)
        {
            if(j + 1 < x)
                draw(massive[i][j], massive[i][j + 1], mlx_ptr, win_ptr);
            if (i + 1 < y)
                draw(massive[i][j], massive[i + 1][j], mlx_ptr, win_ptr);
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
