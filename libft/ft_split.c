/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:01:30 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/12/30 19:09:01 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

 static int	ft_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	size_string(char const *str, char c, int i)
{
	int	size;

	size = 0;
	while (str[i] != c && str[i])
	{
		size++;
		i++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		count;
	char	**strings;
	int		size;

	i = 0;
	j = 0;
	count = ft_count(s, c);
	strings = (char **)malloc(sizeof(char *) * (count + 1));
	if (!strings)
		return (NULL);
	while (i < count)
	{
		while (s[j] == c)
			j++;
		size = size_string(s, c, j);
		strings[i] = ft_substr(s, j, size);
		j += size;
		i++;
	}
	strings[i] = 0;
	return (strings);
} 
/*
static int	ft_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	size_string(char const *str, char c, int i)
{
	int	size;

	size = 0;
	while (str[i] != c && str[i])
	{
		size++;
		i++;
	}
	return (size);
}

static int	words_len(char *str, int c, int i)
{
	int	j;

	j = 0;
	while (str && str[i] == c)
		i++;
	while (str && str[i] != c)
	{
		i++;
		j++;
	}
	return (j);
}

static void free_all(char **str)
{
	int i;

	i = -1;
	while(str && str[++i])
		free(str[i]);
	if (str)
		free(str[i]);
	exit(1);
}

static char **fill_strings(char *str, char sep, int count, char **strings)
{
	int j;
	int i;
	int a;

	a = 0;
	i = 0;
	while(a < count)
	{
		strings[a] = (char *)malloc(sizeof(char *) * words_len(str, sep, i));
		if (!strings[a])
			free_all(strings);
		while(str && str[i] == sep)
			i++;
		while(str && str[i] != sep)
		{
			strings[a][j] = str[i];
			i++;
			j++;
		}
		strings[a][j] = '\0';
	}
	return (strings);
}

char	**ft_split(char *str, char sep)
{
	int		i;
	int		j;
	int		count;
	char	**strings;
	int		size;

	i = 0;
	j = 0;
	count = ft_count(str, sep);
	strings = (char **)malloc(sizeof(char *) * (count + 1));
	if (!strings)
		return (NULL);
	strings = fill_strings(str, sep, count, strings);
	return (strings);
}

 int main()
{
	int i = 0;
	char **ptr;
	ptr = ft_split("a s d f g h", ' ');
	for (i = 0; ptr[i]; i++)
	{
		printf("%s\n", ptr[i]);
		free(ptr[i]);
	}
	free(ptr);
	return 0;
} */