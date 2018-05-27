/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 20:09:58 by kprytkov          #+#    #+#             */
/*   Updated: 2017/12/08 20:10:00 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			counter;
	unsigned char	*pointer;

	pointer = (unsigned char *)s;
	counter = 0;
	while (counter < n)
	{
		if (*pointer == (unsigned char)c)
			return (pointer);
		pointer++;
		counter++;
	}
	return (NULL);
}
