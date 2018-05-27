/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 19:53:53 by kprytkov          #+#    #+#             */
/*   Updated: 2017/12/20 19:53:55 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	untouched_length;
	size_t	string_len;

	substring = NULL;
	untouched_length = 0;
	if (s)
		string_len = ft_strlen(s);
	if (s && start < string_len + 1 && len < string_len + 1)
	{
		untouched_length = len;
		if ((substring = malloc(sizeof(char) * len + 1)) == NULL)
			return (NULL);
		s = s + start;
		while (len-- > 0)
		{
			*substring = *s;
			substring++;
			s++;
		}
		*substring = '\0';
	}
	return (substring - untouched_length);
}
