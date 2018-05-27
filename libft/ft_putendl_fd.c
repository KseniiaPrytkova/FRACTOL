/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 19:23:39 by kprytkov          #+#    #+#             */
/*   Updated: 2017/12/20 19:23:40 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	size_t len;

	if (s != NULL)
	{
		len = ft_strlen(s);
		if (len > 0)
		{
			write(fd, s, len);
		}
		write(fd, "\n", 1);
	}
}
