/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutahi <mboutahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:25:26 by mboutahi          #+#    #+#             */
/*   Updated: 2024/11/18 16:27:07 by mboutahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 7
#endif

char	*nl_checker( char *line, size_t b_size)
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
	
	line = "";
    if (fd < 0 || BUFFER_SIZE == 0)
        return (NULL);
	line = ft_strjoin(line, left);
	//printf("%s", line);
	buffer_read = read(fd, buffer, BUFFER_SIZE);
	while(buffer_read > 0)
	{
		buffer[buffer_read] = 0;
		line = ft_strjoin(line, buffer);
		left = nl_checker(line, BUFFER_SIZE);
		// line = ft_strjoin(line, nl_checker(line, BUFFER_SIZE));
		
		if (ft_strchr(line, '\n') != 0)
			return (ft_substr(line, 0, ft_strchr(line, '\n') + 1));
	}
	return (line);
}
#include <stdio.h>
int main()
{
	
	
    int fd = open("file1.txt", O_RDONLY, 0777);
	 get_next_line(fd);
	    printf("%s", get_next_line(fd));
}
