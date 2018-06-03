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
	e->choose_color = 0;
	e->min_x = -1.5;
	e->max_x = 1;
	e->min_y = -1;
	e->max_y = 1;
	e->move_x = 0;
	e->move_y = 0;
	e->zoom = 1;
}

void		choose_color(t_env *e, int color)
{
	if (e->choose_color == 0)
	{
			e->red = (color * 5) % 30;
			e->blue = (color * 5) % 255;
			e->green = (color * 5) % 30;
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
			color = mandelbrot_math(e, x, y);
			//color = julia_math(e, x, y);
			//color = ship_math(e, x, y);
			choose_color(e, color);
			// TODO fill px
			put_pixel_to_img(e, x, y);
			x++;
		}
		y++;
	}

}

int			main(int argc, char *argv[])
{
	if (argc == 2 && (ft_strcmp(argv[1], MANDELBROT) == 0))
	{
		t_env 	*e;

		if (!(e = malloc(sizeof(t_env))))
			return (0);
		if (init_mlx(e) == 0)
			return (0);
		init(e);
		foreach_pixel(e);
		next_draw(e);
	
		mlx_hook(e->win_ptr, 2, 5, key_draw, e);
		mlx_hook(e->win_ptr, 17, 1L << 17, exit_x, NULL);
		mlx_mouse_hook(e->win_ptr, mouse_draw, e);
		//mlx_hook(e->win, MOTION_NOTIFY, MOTION_MASK, ftl_motion_hook, e);
		mlx_loop(e->mlx_ptr);
	}
	else
	{
		ft_putstr("List of available parameters:\n");
		ft_putstr("1. " MANDELBROT"\n");
	}
		
	
	return (0);
}