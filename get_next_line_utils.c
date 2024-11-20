/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutahi <mboutahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:53:42 by mboutahi          #+#    #+#             */
/*   Updated: 2024/11/20 14:55:40 by mboutahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dub;

	i = 0;
	while (s1[i])
		i++;
	dub = malloc(sizeof(char) * (i + 1));
	if (dub == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dub[i] = s1[i];
		i++;
	}
	dub[i] = '\0';
	return (dub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
	 	s1 = "";
	if (!s2)
		s2 = "";
	newstr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		newstr[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		newstr[i] = s2[j];
		j++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c && s[i])
		i++;
	if (s[i] == (char)c)
		return (i);
	else
		return (0);
}