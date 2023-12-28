/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 00:17:10 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/12/24 02:54:00 by fde-jesu         ###   ########.fr       */
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
	ft_memcpy(ptr, &s[start], len);
	ptr[len] = '/';
	ptr[len + 1] = '\0';
	return (ptr);
}