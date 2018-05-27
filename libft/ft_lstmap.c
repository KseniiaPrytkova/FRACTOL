/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:57:19 by kprytkov          #+#    #+#             */
/*   Updated: 2017/12/20 18:57:20 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_clean_list(t_list *lst)
{
	t_list *prev;

	prev = lst;
	while (lst != NULL)
	{
		lst = lst->next;
		free(prev);
		prev = lst;
	}
	return (NULL);
}

static void	ft_move_next(t_list **prev_elem, t_list **first, t_list **new_elem)
{
	if (!(*prev_elem))
	{
		*prev_elem = *first;
	}
	else
	{
		(*prev_elem)->next = *new_elem;
		*prev_elem = *new_elem;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_elem;
	t_list *prev_elem;
	t_list *first;

	prev_elem = NULL;
	first = NULL;
	while (lst && f)
	{
		if (!(new_elem = ft_lstnew(lst->content, lst->content_size)))
			return (ft_clean_list(first));
		new_elem = f(new_elem);
		if (!first)
			first = new_elem;
		ft_move_next(&prev_elem, &first, &new_elem);
		lst = lst->next;
	}
	return (first);
}
