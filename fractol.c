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

int			key_draw(int keycode)
{
	if (keycode == 53)
		exit(1);
	return (-1);
}

int 		mandelbrot(t_env *e, int x, int y)
{
	float x_in_mandelbrot_space;
	float y_in_mandelbrot_space;

	return (color);
}

void		paint_screen(t_env 	*e)
{
	int		row;
	int		col;
	// int		pix;
	int 	color;

	double 	

	row = 0;
	// pix = 0;
	color = 0x333333;
	while (row < HEIGHT)
	{
		col = 0;
		while (col < WIDTH)
		{
			// pix = (x + y * WIDTH) * 4;
			color = mandelbrot(e, x, y);


			mlx_pixel_put(e->mlx_ptr, e->win_ptr, col, row, color);
			col++;
		}
		row++;
	}

}

int			main(int argc, char *argv[])
{
	if (argc == 2)
	{
		char 	*s;
		t_env 	*e;

		s = argv[1];
		if (!(e = malloc(sizeof(t_env))))
			return (0);
		e->mlx_ptr = mlx_init();
		e->win_ptr = mlx_new_window(e->mlx_ptr, WIDTH, HEIGHT, "hello, fractol");

		/*mlx_pixel_put(e->mlx_ptr, e->win_ptr, 50, 40, 8388352);*/

		mlx_key_hook(e->win_ptr, key_draw, e);
		mlx_hook(e->win_ptr, 17, 1L << 17, exit_x, NULL);
		/* --------------------------- */
		paint_screen(e);
		/* --------------------------- */
		mlx_loop(e->mlx_ptr);
	}
	else 
		ft_putstr("list of available parameters:\n");
	
	return (0);
}