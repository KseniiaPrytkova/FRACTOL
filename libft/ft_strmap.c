/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 19:38:41 by kprytkov          #+#    #+#             */
/*   Updated: 2017/12/20 19:38:46 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*new_area;

	new_area = NULL;
	len = 0;
	if (s != NULL && f != NULL)
	{
		len = ft_strlen(s);
		if (!(new_area = malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (*s != '\0')
		{
			*new_area = f(*s);
			s++;
			new_area++;
		}
		*new_area = '\0';
	}
	return (new_area - len);
}
