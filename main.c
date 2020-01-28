/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:17:18 by aguiller          #+#    #+#             */
/*   Updated: 2020/01/27 23:37:06 by alexzudin        ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	int		fd;
	int		count;

	count = 0;
	if ((fd = checkarg(argc, argv)) == 0)
		return (0);
	if (valid_onlydigits(fd) < 0)
	{
		ft_putendl("error");
		return (0);
	}
	if (close(fd) < 0)
		return (0);
	if ((fd = checkarg(argc, argv)) == 0)
		return (0);
	return (0);
}
