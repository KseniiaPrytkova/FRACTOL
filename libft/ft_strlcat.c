/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 19:39:48 by kprytkov          #+#    #+#             */
/*   Updated: 2017/12/20 19:39:49 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_len;
	size_t src_len;
	size_t diff;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	diff = size - dst_len;
	dst = dst + dst_len;
	if (dst_len < size)
	{
		while (diff > 1)
		{
			*dst = *src;
			src++;
			dst++;
			diff--;
		}
		*dst = '\0';
	}
	else
		dst_len = size;
	return (dst_len + src_len);
}
