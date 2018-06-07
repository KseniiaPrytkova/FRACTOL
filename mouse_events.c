/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:19:34 by kprytkov          #+#    #+#             */
/*   Updated: 2018/06/06 16:19:35 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int			mouse_zoom(int keycode, int x, int y, t_env *e)
{
	long double	zoom_factor;
	long double	move_x;
	long double	move_y;

	if (keycode == 5 || keycode == 1)
	{
	
			move_x  = (long double)x * (long double)((e->max_x - e->min_x) / (long double)WIDTH) + (long double)e->min_x;
			move_y  = (long double)y * (long double)((e->max_y - e->min_y) / (long double)HEIGHT) + (long double)e->min_y;
			zoom_factor = 0.9f;
			e->zoom *= zoom_factor;
			e->max_x = e->max_x * zoom_factor + move_x * (1 - zoom_factor);
			e->min_x = e->min_x * zoom_factor + move_x * (1 - zoom_factor);
			e->max_y = e->max_y * zoom_factor + move_y * (1 - zoom_factor);
			e->min_y = e->min_y * zoom_factor + move_y * (1 - zoom_factor);
			next_draw(e);
	}
	if (keycode == 4 || keycode == 2)
	{
		if (e->zoom <= 2)
		{
			move_x  = (long double)x * (long double)((e->max_x - e->min_x) / (long double)WIDTH) + e->min_x;
			move_y  = (long double)y * ((long double)(e->max_y - e->min_y) / (long double)HEIGHT) + e->min_y;
			zoom_factor = 1.1f;
			e->zoom *= zoom_factor;
			e->max_x = e->max_x * zoom_factor + move_x * (1 - zoom_factor);
			e->min_x = e->min_x * zoom_factor + move_x * (1 - zoom_factor);
			e->max_y = e->max_y * zoom_factor + move_y * (1 - zoom_factor);
			e->min_y = e->min_y * zoom_factor + move_y * (1 - zoom_factor);
			next_draw(e);
		}
	}
	return (0);
}

int 		mouse_for_julia( int x, int y, t_env *e)
{
	long double new_x;
	long double new_y;

	if (e->julia_mode_on == 1)
	{
		new_x = ft_map(x, 0, WIDTH, -1, 1);
		new_y = ft_map(y, 0, HEIGHT, -1, 1);

		e->c_re = new_x;
		e->c_im = new_y;
		next_draw(e);
	}
	return (0);
}