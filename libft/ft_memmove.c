/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:58:06 by kprytkov          #+#    #+#             */
/*   Updated: 2017/11/28 15:58:07 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned	char	*source;
	unsigned	char	*destination;
	int					counter;

	counter = (int)len - 1;
	source = (unsigned char*)src;
	destination = (unsigned char*)dst;
	if (source < destination)
		while (counter >= 0)
		{
			*(destination + counter) = *(source + counter);
			counter--;
		}
	else if (source > destination)
		while (counter >= 0)
		{
			*destination = *source;
			destination++;
			source++;
			counter--;
		}
	return (dst);
}
