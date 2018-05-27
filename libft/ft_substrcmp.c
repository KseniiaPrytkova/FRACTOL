/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substrcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 19:55:23 by kprytkov          #+#    #+#             */
/*   Updated: 2017/12/20 19:55:24 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_substrcmp(const char *s1, const char *s2, size_t n)
{
	size_t counter;

	counter = 0;
	while (counter < n && (*s1 - *s2) == 0)
	{
		s1++;
		s2++;
		counter++;
	}
	return (counter == n);
}
