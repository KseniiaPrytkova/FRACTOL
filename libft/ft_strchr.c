/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 19:27:43 by kprytkov          #+#    #+#             */
/*   Updated: 2017/12/20 19:27:44 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char c_transform;

	c_transform = (char)c;
	while (*s != '\0')
	{
		if (*s == c_transform)
		{
			return ((char *)s);
		}
		s++;
	}
	if (c_transform == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}
