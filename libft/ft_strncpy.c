/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:18:17 by kprytkov          #+#    #+#             */
/*   Updated: 2017/11/29 18:18:19 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	counter;
	char	*pointer_to_dest_start;
	size_t	src_len;

	pointer_to_dest_start = dst;
	src_len = ft_strlen(src);
	counter = 0;
	while (counter < len)
	{
		if (counter < src_len)
		{
			*dst = *src;
			src++;
		}
		else
			*dst = '\0';
		dst++;
		counter++;
	}
	return (pointer_to_dest_start);
}
