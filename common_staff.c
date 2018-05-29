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

int			key_draw(int keycode)
{
	if (keycode == 53)
		exit(1);
	return (-1);
}

double		ft_map(double variable_1, double min_1, double max_1, double min_2, double max_2)
{
	double variable_2;

	variable_2 = min_2 + (max_2 - min_2) * ((variable_1 - min_1) / (max_1 - min_1));
	return (variable_2);
}