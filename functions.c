/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehell <ehell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:26:57 by aguiller          #+#    #+#             */
/*   Updated: 2020/02/07 18:40:29 by ehell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	find_min_max(t_koord **massive, t_app *app)
{
	int	i;
	int	j;
	int	min;
	int	max;

	i = 0;
	min = 2147483647;
	max = -214783648;
	while (i < app->max_y)
	{
		j = 0;
		while (j < app->max_x)
		{
			if (massive[i][j].old_z < min)
				min = massive[i][j].old_z;
			if (massive[i][j].old_z > max)
				max = massive[i][j].old_z;
			j++;
		}
		i++;
	}
	app->min_z = min;
	app->max_z = max;
}

void	color_for_all(t_app *app)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < app->max_y)
	{
		j = 0;
		while (j < app->max_x)
		{
			app->massive[i][j].color = 0x10 + (app->massive[i][j].old_z - app->min_z) / (app->max_z - app->min_z) * (0xFF - 0x10);
			if (app->massive[i][j].color < 0x59 && app->massive[i][j].color > 0x11)
				ft_putstr("here");
			j++;
		}
		i++;
	}
}

char	color(t_koord p1, t_koord p2, int i)
{
	char	colour;

	colour = abs(p1.color - p2.color);
	if (p1.old_z == p2.old_z)
		return (p1.color);
	else
		return (p1.color + (1 - i / (p2.old_z - p1.old_z)) * colour);
}
