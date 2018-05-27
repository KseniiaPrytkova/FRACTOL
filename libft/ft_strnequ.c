/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 19:48:31 by kprytkov          #+#    #+#             */
/*   Updated: 2017/12/20 19:48:33 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 == NULL && s2 == NULL)
		return (1);
	if (s1 != NULL && s2 != NULL)
		return (ft_strncmp(s1, s2, n) == 0);
	return (0);
}
