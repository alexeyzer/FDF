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

char	color(t_koord p1, t_koord p2, int i, int max_z)
{
	char	colour;

	colour = 0x10;
	if (p1.old_z == p2.old_z)
		return (colour + (p1.old_z / max_z) * 100);
	if (p1.old_z > p2.old_z)
		return (colour + (p1.old_z / max_z) * 100 - 10 * i);
	return (colour);
}
