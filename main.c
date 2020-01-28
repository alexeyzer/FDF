/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiller <aguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:17:18 by aguiller          #+#    #+#             */
/*   Updated: 2020/01/28 17:51:57 by aguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		checkarg(int argc, char **argv)
{
	int fd;

	if (argc <= 1)
	{
		ft_putendl("Usage : ./fdf <filename> [ case_size z_size ]");
		return (0);
	}
	if (argc > 4)
	{
		ft_putendl("Usage : ./fdf <filename> [ case_size z_size ]");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
	{
		ft_putendl("Could not to open the file");
		return (0);
	}
	return (fd);
}
int err()
{
	ft_putendl("error");
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int len_x;
	int len_y;

	line = NULL;
	if ((fd = checkarg(argc, argv)) == 0)
		return (0);
	if ((len_y = valid_onlydigits(fd)) < 0)
		return(err());
	if (close(fd) < 0)
		return (0);
	fd = checkarg(argc, argv);
	if ((len_x = valid_for_count(fd, line)) < 0)
		return(err());
	if (close(fd) < 0)
		return (0);
	fd = checkarg(argc, argv);
	read_tomass(len_x, len_y, fd);
	return (0);
}
