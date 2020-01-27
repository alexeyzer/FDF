/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiller <aguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:52:54 by aguiller          #+#    #+#             */
/*   Updated: 2020/01/27 14:53:43 by aguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

int checkline(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        i++;
    }
    return (i);

}

int valider(int fd)
{
    int i;
    char    **lin;
    char    *line;

    i = 0;
    get_next_line(fd, &line);
    printf("%s", line);
    lin = ft_split_whitespaces(line);
    
    while(lin[i])
    {
        i++;
    }

    return (0);
}