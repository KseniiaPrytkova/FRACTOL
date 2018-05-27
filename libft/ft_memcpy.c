/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 22:13:16 by kprytkov          #+#    #+#             */
/*   Updated: 2017/11/24 22:13:17 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				counter;
	unsigned	char	*source;
	unsigned	char	*destination;

	source = (unsigned char *)src;
	destination = (unsigned char *)dst;
	counter = 0;
	while (counter < n)
	{
		*destination = *source;
		destination++;
		source++;
		counter++;
	}
	return (dst);
}
