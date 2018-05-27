/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 19:44:45 by kprytkov          #+#    #+#             */
/*   Updated: 2017/12/20 19:44:48 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*s_final;
	size_t	counter;

	s_final = s1;
	counter = 0;
	while (*s1 != '\0')
	{
		s1++;
	}
	while (counter < n && (*s2 != '\0'))
	{
		*s1 = *s2;
		s1++;
		s2++;
		counter++;
	}
	*s1 = '\0';
	return (s_final);
}
