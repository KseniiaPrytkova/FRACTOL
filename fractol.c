/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 16:37:40 by kprytkov          #+#    #+#             */
/*   Updated: 2018/05/27 16:37:41 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

static int	exit_x(void)
{
	exit(1);
	return (0);
}

void	init(t_env *e)
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
	if (e->choose_fractal == 1)
	{
		e->function = julia_math;
		e->c_re = 0.016f;
		e->c_im = 0.84f;
	}
}

void		choose_color(t_env *e, int color)
{
	if (e->choose_color == 0)
	{
		if (color == e->infinity )
		{
			e->red = 0;
			e->blue = 0;
			e->green = 0;
		}
		else
		{
			e->red = (color * 3) % 255;
			e->blue = (color * 7) % 255;
			e->green = (color * 4) % 255;
		}
		
	}
	if (e->choose_color == 1)
	{
		e->red = 255;
	}
	if (e->choose_color == 2)
	{
		e->red = 255;
	}
}

void		foreach_pixel(t_env *e)
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

int			main(int argc, char *argv[])
{
	if (argc == 2 && (ft_strcmp(argv[1], JULIA) == 0))
	{
		t_env 	*e;

		if (!(e = malloc(sizeof(t_env))))
			return (0);
		if (init_mlx(e) == 0)
			return (0);
		e->choose_fractal = 0;
		init(e);
		foreach_pixel(e);
		next_draw(e);
	
		mlx_hook(e->win_ptr, 2, 5, key_draw, e);
		mlx_hook(e->win_ptr, 17, 1L << 17, exit_x, NULL);
		mlx_mouse_hook(e->win_ptr, mouse_zoom, e);
		mlx_hook(e->win_ptr, MOTION_NOTIFY, MOTION_MASK, mouse_for_julia, e);
		mlx_loop(e->mlx_ptr);
	}
	else
	{
		ft_putstr("List of available parameters:\n");
		ft_putstr("1. " MANDELBROT"\n");
	}
		
	
	return (0);
}