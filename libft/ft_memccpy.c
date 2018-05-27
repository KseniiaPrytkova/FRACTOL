/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 20:04:40 by kprytkov          #+#    #+#             */
/*   Updated: 2017/12/08 20:04:41 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				counter;
	unsigned	char	*source;
	unsigned	char	*destination;
	unsigned	char	c_transform;

	source = (unsigned char *)src;
	destination = (unsigned char *)dst;
	c_transform = (unsigned char)c;
	counter = 0;
	while (counter < n)
	{
		*destination = *source;
		destination++;
		source++;
		counter++;
		if (*(source - 1) == c_transform)
		{
			return (destination);
		}
	}
	return (NULL);
}
