/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 19:46:17 by kprytkov          #+#    #+#             */
/*   Updated: 2017/12/20 19:46:20 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*new_area;
	unsigned int	counter;

	new_area = NULL;
	len = 0;
	counter = 0;
	if (s != NULL && f != NULL)
	{
		len = ft_strlen(s);
		if (len == 0 || !(new_area = malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (*s != '\0')
		{
			*new_area = f(counter, *s);
			s++;
			new_area++;
			counter++;
		}
		*new_area = '\0';
	}
	return (new_area - len);
}
