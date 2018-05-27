/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 19:50:11 by kprytkov          #+#    #+#             */
/*   Updated: 2017/12/20 19:50:12 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t smallstr_len;

	if (*needle == '\0')
		return ((char *)haystack);
	smallstr_len = ft_strlen(needle);
	while (*haystack && len >= smallstr_len)
	{
		if (ft_substrcmp(haystack, needle, smallstr_len) == 1)
		{
			return ((char *)haystack);
		}
		len--;
		haystack++;
	}
	return (NULL);
}
