/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 00:17:10 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/12/30 19:53:58 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr_path(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	s_size;

	s_size = ft_strlen(s);
	if (!s)
		return (NULL);
	if (s_size < start)
		return (ft_strdup(""));
	if (len > (s_size - start))
		len = s_size - start;
	ptr = (char *)malloc(sizeof(char) * (len + 2));
	if (!ptr)
		return (NULL);
	ptr[len] = '/';
	ptr[len+1] = '\0';
	return (ptr);
}

/* 

static char	**freetab(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		free(arr[i++]);
	if (arr)
		free(arr);
	return (0);
}

static int	word_count(const char *s, char c)
{
	int	i;
	int	count;

	if (!s || !s[0])
		return (0);
	i = -1;
	count = 0;
	while (s[++i])
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			count++;
	return (count);
}

static int	words_len(const char *s, char c, int i)
{
	int	l;

	l = 0;
	while (s && s[i] && s[i] == c)
		i++;
	while (s && s[i] && s[i++] != c)
		l++;
	return (l);
}

static char	**fill_arr(int words, const char *s, char c, char **arr)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (k < words)
	{
		j = 0;
		arr[k] = (char *)malloc(sizeof(char) * (words_len(s, c, i) + 2));
		if (!arr[k])
			return (freetab(arr));
		while (s && s[i] && s[i] == c)
			i++;
		while (s && s[i] && s[i] != c)
			arr[k][j++] = s[i++];
		arr[k][j++] = '/';
		arr[k][j] = '\0';
		k++;
	}
	arr[k] = 0;
	return (arr);
}

char	**ft_splitpath(char *s, char c)
{
	int		words;
	char	**arr;

	if (!s || !s[0])
		return (NULL);
	words = word_count(s, c);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	arr = fill_arr(words, s, c, arr);
	return (arr);
} */