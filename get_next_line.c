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
#define BUFFER_SIZE 5
#endif

static char	*getl(char *left)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (left[i] != '\n' && left[i])
		i++;
	if (left[i] == '\n')
		i++;
	line = malloc(i + 1);

	while (j < i)
	{
		line[j] = left[j];
		j++;
	}
	line[j] = 0;
	return (line);
}
static char	*storeleft(char *left)
{
	int				i;
	int				j;
	static char		*line;
	int				k;	

	i = 0;
	j = 0;
	k = 0;
	while (left[i] != '\n' && left[i])
		i++;
	if (left[i] == '\n')
		i++;
	while (left[i + j] != '\n' && left[i])
		j++;
	line = malloc(j + 1);
	
	while (k < j)
	{
		line[k] = left[i + k];
		k++;
	}
	line[k] = 0;
	// free(left);
	return (line);
}
char	*get_next_line(int fd)
{
	static char	*left;
	char		*line;
   	char		buffer[BUFFER_SIZE + 1];
    ssize_t		buffer_read;
	char		*temp;
	
	line = NULL;
	buffer_read = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
    	return (NULL);
	//buffer_read = read(fd, buffer, BUFFER_SIZE);
	while (1)  //(buffer_read = read(fd, buffer, BUFFER_SIZE))  > 0)
	{
		buffer_read = read(fd, buffer, BUFFER_SIZE);
		buffer[buffer_read] = '\0';
		temp = left;
		left = ft_strjoin(left, buffer);
		free(temp);
		if (ft_strchr(left, '\n') || buffer_read <= 0)
			break;
	}
	if(!left || *left == '\0')
		return NULL;
	temp = left;
	line = getl(left);
	left = storeleft(left);
	free (temp);
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
