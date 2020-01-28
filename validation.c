/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiller <aguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:52:54 by aguiller          #+#    #+#             */
/*   Updated: 2020/01/28 18:01:09 by aguiller         ###   ########.fr       */
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

int valid_onlydigits(int fd)
{
    char    *line;
    char    *new;
    int i;
    int len;

    len = 0;
    while(get_next_line(fd, &line))
    {
        len++;
        new = make_line(line);
        free(line);
        i = 0;
        while(new[i])
        {
            if (('0' > new[i] || new[i] > '9') && new[i] != '-')
                return (-1);
            i++;
        }
        free(new);
    }
    return (len);
}

int for_first(int fd, int *a)
{
    char *line;
    int     i;
    int     slova;

    slova = 0;
    i = 0;
    get_next_line(fd, &line);
    while (line[i])
    {
        if(line[i] != ' ')
        {
            slova++;
            while (line[i] != ' ' && line[i])
                i++;
        }
        else
            i++;
    }
    *a = slova;
    free(line);
    line = NULL;
    return (0);
}

int valid_for_count(int fd, char *line)
{
    int     i;
    int     slova;
    int     width;

    i = for_first(fd, &width);
    while(get_next_line(fd, &line))
    {
        i = 0;
        slova = 0;
        while (line[i])
        {
            if(line[i] != ' ')
            {
                slova++;
                while (line[i] != ' ' && line[i])
                    i++;
            }
            else
                i++;
        }
        free(line);
        if (width != slova)
            return (-1);
    }
    return (width);
}
