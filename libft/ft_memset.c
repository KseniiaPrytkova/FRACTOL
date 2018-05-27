/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:31:54 by kprytkov          #+#    #+#             */
/*   Updated: 2017/11/23 17:31:56 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	size_t			counter;
	unsigned char	c_transform;
	unsigned char	*d;

	counter = 0;
	c_transform = (unsigned char)c;
	d = (unsigned char*)b;
	while (counter < len)
	{
		d[counter] = c_transform;
		counter++;
	}
	return (b);
}
