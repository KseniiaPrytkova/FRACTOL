/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 19:35:46 by kprytkov          #+#    #+#             */
/*   Updated: 2017/12/20 19:35:47 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int counter;

	if (s != NULL && f != NULL)
	{
		counter = 0;
		while (*s != '\0')
		{
			f(counter, s);
			s++;
			counter++;
		}
	}
}
