/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:25:51 by kprytkov          #+#    #+#             */
/*   Updated: 2017/12/20 18:25:52 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *saved;
	t_list *temp;

	if (alst != NULL && *alst != NULL && del)
	{
		saved = *alst;
		while (saved != NULL)
		{
			temp = saved;
			saved = saved->next;
			temp->next = NULL;
			ft_lstdelone(&temp, del);
		}
		*alst = NULL;
	}
}
