/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutahi <mboutahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:25:26 by mboutahi          #+#    #+#             */
/*   Updated: 2024/11/17 18:55:03 by mboutahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*nl_checker( char *line, size_t b_size)
{
	static char	*left;
	int			i;

	i = ft_strchr(line, '\n');
	if (i)
		left = ft_substr(line, i, b_size);
	return (left);
}
char	*get_next_line(int fd)
{
	size_t		b_size;
	static char	*line;
    char		buffer[b_size + 1];
    ssize_t		buffer_read;
	int			i;

	line = "";
	b_size = 7;
	i = ft_strchr(line, '\n');
    if (fd < 0 || b_size == 0)
        return (NULL);
	line = ft_strjoin(line, nl_checker(line, b_size));
	buffer_read = read(fd, buffer, b_size);
	buffer[buffer_read] = 0;
    line = ft_strjoin(line, buffer);
	if (ft_strchr(line, '\n'))
		line = ft_substr(line, 0, i - 1);
    return (line);
}
#include <stdio.h>
int main()
{
    int fd = open("file1.txt", O_RDONLY, 0777);
	    printf("%s", get_next_line(fd));
}
