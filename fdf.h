/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiller <aguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:18:28 by aguiller          #+#    #+#             */
/*   Updated: 2020/02/06 13:37:28 by aguiller         ###   ########.fr       */
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
    int color;
}               t_koord;

typedef struct s_app
{
    void	*mlx_ptr;
	void	*win_ptr;
    void	*im_ptr;
    int	    bpp;
    int	    size_line;
    int     height;
    int     width;
    int     zoom;
    int     max_x;
    int     max_y;
    int     py;
    int     px;
    char    projection;
    int     color;
    int	    max_z;
    int	    min_z;
    char    *dadr;
    t_koord **massive;
}              t_app;

t_app   *app_init(t_koord **massive, int x, int y);
int	    get_next_line(const int fd, char **line);
int     valid_onlydigits(int fd);
int     valid_for_count(int fd, char *line);
t_koord     **read_tomass(int len_x, int len_y, int fd);
void    draw(t_koord point0, t_koord point1, t_app *app);
void try_to_print(t_koord **massive, t_app *app);
void to_iso(t_koord **massive, t_app *app);
void to_paralell(t_koord **massive, t_app *app);
void    setuper(t_app *app);
int    event_key(int key, t_app *app);
void    erease(t_app *app);
int     reprint(t_app *app);
int     quit(t_app *app);
void    make_menu(t_app *app);
void    choose_zoom(t_app *app, t_koord **massive);
void find_min_max(t_koord **massive, t_app *app);
char color(t_koord p1, t_koord p2, int i, int max_z);
void pixel_put(t_app *app, int x, int y, char colour);

#endif
