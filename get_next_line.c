/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutahi <mboutahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:25:26 by mboutahi          #+#    #+#             */
/*   Updated: 2024/11/20 15:40:42 by mboutahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

static char *storeleft(char *left)
{
    int     i;
    int     j;
    char    *line;

    i = 0;
    j = 0;
    if (!left)
	{
    return (NULL);
	}
    if (!*left)
	{
    free(left);
    return (NULL);
	}
    while (left[i] && left[i] != '\n')
        i++;
    if (left[i] == '\n')
        i++;
    if (!left[i])
    {
        free(left);
        return (NULL);
    }
    line = malloc((ft_strlen(left + i) + 1) * sizeof(char));
    if (!line)
    {
        free(left);
        return (NULL);
    }
    while (left[i])
        line[j++] = left[i++];
    line[j] = '\0';
    free(left);
    return (line);
}

static char *getl(char *left)
{
    int     i;
    int     j;
    char    *line;

    i = 0;
    if (!left)
	{
    return (NULL);
	}
    if (!*left)
	{
    free(left);
    return (NULL);
	}
    while (left[i] && left[i] != '\n')
        i++;
    if (left[i] == '\n')
        i++;
    line = malloc((i + 1) * sizeof(char));
    if (!line)
	{
        return (NULL);
	}
    j = 0;
    while (j < i)
    {
        line[j] = left[j];
        j++;
    }
    line[j] = '\0';
    return (line);
}

char *get_next_line(int fd)
{
    static char *left;
    char        *line;
    char        *buffer;
    char        *temp;
    ssize_t     buffer_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        free(left);
        left = NULL;
        return (0);
    }
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
    {
        free(left);
        left = NULL;
        return (NULL);
    }
    while ((buffer_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[buffer_read] = '\0';
        temp = left;
		left = ft_strjoin(left, buffer);
        free(temp);
		if (!left)
		{
    		free(buffer);
    		return (NULL);
		}
        if (ft_strchr(left, '\n'))
            break;
    }
    free(buffer);
    if (buffer_read < 0)
    {
        free(left);
        left = NULL;
        return (NULL);
    }
    line = getl(left);
    left = storeleft(left);
    return (line);
}
