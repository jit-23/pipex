/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 04:48:39 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/05/03 04:48:41 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_content = ft_lstnew(f(lst->content));
	if (!new_content)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	new_list = new_content;
	lst = lst->next;
	while (lst)
	{
		new_content = ft_lstnew(f(lst->content));
		if (!new_content)
			ft_lstclear(&lst, del);
		else
			ft_lstadd_back(&new_list, new_content);
		lst = lst->next;
	}
	return (new_list);
}
