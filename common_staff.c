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
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->image_ptr, 0, 0);
}

int			mouse_draw(int keycode, int x, int y, t_env *e)
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
	return (0);
}

int 		j_mouse( int x, int y, t_env *e)
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

int			key_draw(int keycode, t_env *e)
{
	

	if (keycode == 53)
		exit(1);
	if (keycode == 125) /* up */
	{
		e->min_y += 0.1 / e->zoom;
		e->max_y += 0.1 / e->zoom;
		next_draw(e);
	}
	if (keycode == 126) /* down */
	{
		e->min_y -= 0.1 / e->zoom;
		e->max_y -= 0.1 / e->zoom;
		next_draw(e);
	}

	if (keycode == 124) /* left */
	{
		e->min_x += 0.1 / e->zoom;
		e->max_x += 0.1 / e->zoom;
		next_draw(e);
	}
	if (keycode == 123) /* right */
	{
		e->min_x -= 0.1 / e->zoom;
		e->max_x -= 0.1 / e->zoom;
		next_draw(e);
	}
	if (keycode == 49)
	{
		e->julia_mode_on = (e->julia_mode_on + 1) % 2;
	}
	return (-1);
}

long double		ft_map(long double variable_1, long double min_1, long double max_1, long double min_2, long double max_2)
{
	long double variable_2;

	variable_2 = min_2 + (max_2 - min_2) * ((variable_1 - min_1) / (max_1 - min_1));
	return (variable_2);
}