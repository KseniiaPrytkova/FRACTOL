/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 23:25:12 by kprytkov          #+#    #+#             */
/*   Updated: 2017/09/26 19:24:52 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_skit_spaces(char *s)
{
	while (ft_isspace(s))
	{
		s++;
	}
	return (s);
}

static char	*ft_check_minus(char *str, int *minus)
{
	if (*str == '-')
	{
		str++;
		*minus = -(*minus);
	}
	else if (*str == '+')
		str++;
	return (str);
}

static char	*ft_check_sign(char *str, int *minus)
{
	str = ft_check_minus(str, minus);
	if (*str == '+' || *str == '-')
		*minus = 0;
	return (str);
}

int			ft_atoi(char *str)
{
	unsigned long long	sum;
	int					check_minus;

	str = ft_skit_spaces(str);
	check_minus = 1;
	sum = 0;
	str = ft_check_sign(str, &check_minus);
	while (*str != '\0' && *str != ' ')
	{
		if (*str >= '0' && *str <= '9')
		{
			sum = sum * 10 + (*str - '0');
			str++;
		}
		else
		{
			break ;
		}
	}
	if (sum >= LLONG_MAX && check_minus == 1)
		return (-1);
	if (sum > LLONG_MAX && check_minus == -1)
		return (0);
	return (sum * check_minus);
}
