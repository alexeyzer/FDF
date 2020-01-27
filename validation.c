/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:52:54 by aguiller          #+#    #+#             */
/*   Updated: 2020/01/27 19:23:54 by alexzudin        ###   ########.fr       */
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

int valider(int fd)
{
    char    *line;
    char    *new;
    int i;

    while(get_next_line(fd, &line))
    {
        new = make_line(line);
        free(line);
        i = 0;
        while(new[i])
        {
            if ('0' > new[i] || new[i] > '9')
                return (-1);
            i++;
        }
        free(new);
    }
    return (0);
}