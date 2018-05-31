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

void 		next_draw(t_env *e)
{
	mlx_clear_window(e->mlx_ptr, e->win_ptr);
	foreach_pixel(e);
}

int			key_draw(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 126) /* up */
	{
		e->min_2_im += 0.01;
		e->max_2_im += 0.01;
		next_draw(e);
	}
	if (keycode == 125) /* down */
	{
		e->min_2_im -= 0.01;
		e->max_2_im -= 0.01;
		next_draw(e);
	}
	if (keycode == 123) /* left */
	{
		e->min_2_re += 0.01;
		e->max_2_re += 0.01;
		next_draw(e);
	}
	if (keycode == 124) /* right */
	{
		e->min_2_re -= 0.01;
		e->max_2_re -= 0.01;
		next_draw(e);
	}
	return (-1);
}

double		ft_map(double variable_1, double min_1, double max_1, double min_2, double max_2)
{
	double variable_2;

	variable_2 = min_2 + (max_2 - min_2) * ((variable_1 - min_1) / (max_1 - min_1));
	return (variable_2);
}