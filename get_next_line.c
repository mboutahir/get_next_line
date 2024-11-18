/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutahi <mboutahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:25:26 by mboutahi          #+#    #+#             */
/*   Updated: 2024/11/18 17:42:56 by mboutahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 7
#endif

char	*nl_checker( char *line)
{
	char	*left;
	int			i;

	i = ft_strchr(line, '\n');
	// if (left != NULL)
	// 	free(left);
	if (i != 0)
		left = ft_substr(line, i + 1, ft_strlen(line) - (i + 1));
		// printf("%s", left);
	else
		left = NULL;
		
	return (left);
}
char	*get_next_line(int fd)
{
	static char	*left;
	char		*line;
    char		buffer[BUFFER_SIZE + 1];
    ssize_t		buffer_read;
	char		*temp;
	
	line = ft_strdup("");
    if (fd < 0 || BUFFER_SIZE == 0)
        return (NULL);
		if (left)
		{
			temp = line;
			line = ft_strjoin(line, left); // Append leftovers to line
			free(temp); // Free the old line
			free(left); // Free the old leftovers
			left = NULL; // Reset leftovers
		}
		buffer_read = read(fd, buffer, BUFFER_SIZE);
	while(buffer_read > 0)
	{
		buffer[buffer_read] = 0;
		temp = line;
		line = ft_strjoin(line, buffer);
		free(temp);
		if (ft_strchr(line, '\n') != 0)
		{
			left = nl_checker(line);
			temp = line;
			line = ft_substr(line, 0, ft_strchr(line, '\n') + 1);
			free(temp); // Free the old line
			return (line);
		}
	}
	if (ft_strlen(line) == 0)
		{
			free(line); // Free the empty `line`
			return (NULL); // Nothing left to read
		}
	return (line);
}
#include <stdio.h>
int main()
{
	int fd = open("file1.txt", O_RDONLY, 0777);
	char *line;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}
