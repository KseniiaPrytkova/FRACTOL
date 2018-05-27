/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:55:37 by kprytkov          #+#    #+#             */
/*   Updated: 2017/12/20 18:55:38 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list_item;

	list_item = malloc(sizeof(t_list));
	if (!list_item)
		return (NULL);
	if (content != NULL && content_size != 0)
	{
		list_item->content = malloc(content_size);
		if (!list_item->content)
		{
			free(list_item);
			return (NULL);
		}
		ft_memcpy(list_item->content, content, content_size);
		list_item->content_size = content_size;
		list_item->next = NULL;
	}
	else
	{
		list_item->content = NULL;
		list_item->content_size = 0;
	}
	return (list_item);
}
