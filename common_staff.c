/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_staff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 19:29:17 by kprytkov          #+#    #+#             */
/*   Updated: 2018/05/29 19:29:18 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"



long double		ft_map(long double variable_1, long double min_1, long double max_1, long double min_2, long double max_2)
{
	long double variable_2;

	variable_2 = min_2 + (max_2 - min_2) * ((variable_1 - min_1) / (max_1 - min_1));
	return (variable_2);
}

