/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:18:28 by aguiller          #+#    #+#             */
/*   Updated: 2020/01/29 11:49:26 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# define BUFF_SIZE 8
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

typedef struct  s_koord
{
    int new_x;
    int new_y;
    int old_z;
}               t_koord;

int	get_next_line(const int fd, char **line);
int valid_onlydigits(int fd);
int valid_for_count(int fd, char *line);
int read_tomass(int len_x, int len_y, int fd);
void draw(t_koord point0, t_koord point1, void *mlx_ptr, void *win_ptr);

#endif
