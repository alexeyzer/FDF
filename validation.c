/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:52:54 by aguiller          #+#    #+#             */
/*   Updated: 2020/01/27 18:01:52 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

char *make_line(char *line)
{
    int     i;
    int     probel;
    char    *new;
    int     j;

    i = 0;
    j = 0;
    probel = 0;
    while (line[i])
    {
        if(line[i] == ' ')
            probel++;
        i++;
    }
    new = (char*)(malloc(sizeof(char) *(i - probel + 1)));
    i = 0;
    while (line[i])
    {
        if(line[i] != ' ')
            new[j++] = line[i];
        i++;
    }
    new[j] = '\0';
    return (new);
}
int forfirst(int fd)
{
    int i;
    char *new;
    char *line;

    get_next_line(fd, &line);
    i = 0;
    new = make_line(line);
    free(line);
    while(new[i])
    {
        if (ft_isdigit(new[i])< 0)
            return (-1);
        i++;
    }
    free(new);
    return (i);
}
int valider(int fd)
{
    int count;
    char    *line;
    char    *new;
    int i;

    if((count = forfirst(fd)) < 0)
        return (-1);
    while(get_next_line(fd, &line))
    {
        new = make_line(line);
        free(line);
        i = 0;
        while(new[i])
        {
            if (ft_isdigit(new[i])< 0)
                return (-1);
            i++;
        }
        free(new);
        if(i != count)
            return (-1);
    }
    return (0);
}