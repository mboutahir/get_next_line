/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line _bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutahi <mboutahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:25:26 by mboutahi          #+#    #+#             */
/*   Updated: 2024/11/27 20:39:49 by mboutahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

static char	*storeleft(char **left)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!*left)
		return (NULL);
	if (!**left)
		return (free(**left), NULL);
	while (*left[i] && *left[i] != '\n')
		i++;
	if (*left[i] == '\n')
		i++;
	if (!*left[i])
		return (free(*left), NULL);
	line = malloc((ft_strlen(*left + i) + 1) * sizeof(char));
	if (!line)
		return (free(*left), NULL);
	while (*left[i])
		line[j++] = *left[i++];
	line[j] = '\0';
	free(*left);
	return (line);
}

static char	*getl(char **left)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!*left)
		return (**left = NULL, NULL);
	if (!**left)
		return (free(*left), *left = NULL, NULL);
	while (*left[i] && *left[i] != '\n')
		i++;
	if (*left[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = *left[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*func(char **left, ssize_t buffer_read)
{
	char	*line;

	if (buffer_read < 0)
		return (free(*left), *left = NULL, NULL);
	line = getl(*left);
	if (!line)
		return (free(*left), *left = NULL, NULL);
	*left = storeleft(*left);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*left[10240];
	char		*buffer;
	ssize_t		buffer_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 10240)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(left[10240]), left[10240] = NULL, NULL);
	while (1)
	{
		buffer_read = read(fd, buffer, BUFFER_SIZE);
		if (buffer_read <= 0)
			break ;
		buffer[buffer_read] = '\0';
		line = left[10240];
		left[10240] = ft_strjoin(left[10240], buffer);
		free(line);
		if (!left[10240])
			return (free(buffer), NULL);
		if (ft_strchr(left[10240], '\n'))
			break ;
	}
	return (free(buffer), func(&left[10240], buffer_read));
}
