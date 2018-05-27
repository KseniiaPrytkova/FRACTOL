/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 19:47:41 by kprytkov          #+#    #+#             */
/*   Updated: 2017/12/20 19:47:44 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t counter;

	counter = 0;
	while (counter < n && (*s1 - *s2) == 0 && *s1 && *s2)
	{
		s1++;
		s2++;
		counter++;
	}
	if (counter == n && (*s1 || *s2))
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
