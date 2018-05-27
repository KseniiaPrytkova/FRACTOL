/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 19:51:52 by kprytkov          #+#    #+#             */
/*   Updated: 2017/12/20 19:51:55 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s_helper;
	char	c_transform;

	s_helper = NULL;
	c_transform = (char)c;
	while (*s != '\0')
	{
		if (*s == c_transform)
		{
			s_helper = (char *)s;
		}
		s++;
	}
	if (c_transform == '\0')
	{
		return ((char *)s);
	}
	return (s_helper);
}
