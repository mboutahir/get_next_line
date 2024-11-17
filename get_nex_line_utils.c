#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
		size_t  i;

		i = 0;
		while (s[i])
				i++;
		return (i);
}

char    *ft_strdup(const char *s1)
{
		int             i;
		char    *dub;

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

char    *ft_strjoin(char const *s1, char const *s2)
{
		char    *newstr;
		size_t  i;
		size_t  j;

		i = 0;
		j = 0;
		if (!s1 || !s2)
				return (NULL);
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

int    ft_strchr(const char *s, int c)
{
		int     i;

		i = 0;
		while (s[i] != (char)c && s[i])
				i++;
		if (s[i] == (char)c)
				return (i + 1);
		else
				return (0);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
		char    *substr;
		size_t  j;

		if (!s)
				return (NULL);
		j = 0;
		if (start >= ft_strlen(s))
		{
				return (ft_strdup(""));
		}
		if (len > (ft_strlen(s) - start))
				len = ft_strlen(s) - start;
		substr = malloc((len + 1) * sizeof(char));
		if (substr == NULL)
				return (NULL);
		while (j < len)
		{
				substr[j] = s[j + start];
				j++;
		}
		substr[j] = 0;
		return (substr);
}
