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
			mlx_pixel_put(e->mlx_ptr, e->win_ptr, x, y, color);
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
		e->mlx_ptr = mlx_init();
		e->win_ptr = mlx_new_window(e->mlx_ptr, WIDTH, HEIGHT, "hello, fractol");

		/*mlx_pixel_put(e->mlx_ptr, e->win_ptr, 50, 40, 8388352);*/

		mlx_key_hook(e->win_ptr, key_draw, e);
		mlx_hook(e->win_ptr, 17, 1L << 17, exit_x, NULL);
		/* --------------------------- */
		foreach_pixel(e);
		/* --------------------------- */
		mlx_loop(e->mlx_ptr);
	}
	else
	{
		ft_putstr("List of available parameters:\n");
		ft_putstr("1. " MANDELBROT"\n");
	}
		
	
	return (0);
}