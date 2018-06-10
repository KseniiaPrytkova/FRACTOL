/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 17:50:59 by kprytkov          #+#    #+#             */
/*   Updated: 2018/06/06 17:51:01 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

static void		which_fractal(t_env *e)
{
	if (e->choose_fractal == 1)
	{
		e->function = mandelbrot_math;
	}
	else if (e->choose_fractal == 2)
	{
		e->function = julia_math;
		e->c_re = -0.70176f;
		e->c_im = -0.3842f;
	}
	else if (e->choose_fractal == 3)
		e->function = burning_ship_math;
	else if (e->choose_fractal == 4)
		e->function = sierpinski_carpet;
	else if (e->choose_fractal == 5)
		e->function = douady_rabbit;
}

void			init(t_env *e)
{
	e->function = mandelbrot_math;
	e->choose_color = 0;
	e->julia_mode_on = 0;
	e->min_x = -1.5f;
	e->max_x = 1.0f;
	e->min_y = -1.0f;
	e->max_y = 1.0f;
	e->move_x = 0.0f;
	e->move_y = 0.0f;
	e->zoom = 1.0f;
	e->infinity = 100;
	which_fractal(e);
}

void			foreach_pixel(t_env *e)
{
	int x;
	int y;
	int color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = e->function(e, x, y);
			choose_color(e, color);
			put_pixel_to_img(e, x, y);
			x++;
		}
		y++;
	}
}

void			next_draw(t_env *e)
{
	mlx_clear_window(e->mlx_ptr, e->win_ptr);
	foreach_pixel(e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->image_ptr, 0, 0);
}
