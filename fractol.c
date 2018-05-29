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

// int 		mandelbrot(t_env *e, int x, int y)
// {
// 	float x_in_mandelbrot_space;
// 	float y_in_mandelbrot_space;

// 	return (color);
// }

double		ft_map(double variable_1, double min_1, double max_1, double min_2, double max_2)
{
	double variable_2;

	variable_2 = min_2 + (max_2 - min_2) * ((variable_1 - min_1) / (max_1 - min_1));
	return (variable_2);
}

// void		draw_mandelbrot(t_env 	*e)
// {
// 	int		row;
// 	int		col;
// 	int 	color;

// 	int 	max_iterations;
// 	int 	iteration;

// 	double 	c_re;
// 	double 	c_im;
// 	double	save_c_re;
// 	double	save_c_im;

// 	double 	x;
// 	double 	y;

// 	double	bright;

// 	row = 0;

// 	max_iterations = 100;
// 	iteration = 0;

// 	c_re = 0.0;
// 	c_im = 0.0;

// 	x = 0.0;
// 	y = 0.0;

// 	color = 0x333333;
// 	while (row < HEIGHT)
// 	{
// 		col = 0;
// 		while (col < WIDTH)
// 		{
// 			c_re = ft_map(row, 0, WIDTH, -2, 2);
// 			c_im = ft_map(col, 0, HEIGHT, -2, 2);
// 			save_c_re = c_re;
// 			save_c_im = c_im;
// 			while ( (x * x + y * y)  < 2 * 2  &&  iteration < max_iterations)
// 			{
// 				x_temp = (x * x - y * y) + c_re;
// 				y = 2 * x * y + c_im;
// 				x = x_temp;
// 				iteration ++;
// 			}
// 			bright = ft_map(iteration, 0, max_iterations, 0, 255);
// 			if (iteration == max_iterations)
// 				bright = 0;
// 			mlx_pixel_put(e->mlx_ptr, e->win_ptr, col, row, bright);
		
// 			col++;
// 		}
// 		row++;
// 	}

// }

void		draw_mandelbrot(t_env 	*e)
{
	int		row;
	int		col;
	int 	color;

	int 	max_iterations;
	int 	iteration;

	double 	x;
	double 	y;
	double	save_x;
	double	save_y;

double xx;
double yy;

	double	bright;

	row = 0;

	max_iterations = 100;
	iteration = 0;

	x = 0.0;
	y = 0.0;

	color = 0x333333;
	while (row < HEIGHT)
	{
		col = 0;
		while (col < WIDTH)
		{
			x = ft_map(row, 0, WIDTH, -2, 2);
			y = ft_map(col, 0, HEIGHT, -2, 2);
			save_x = x;
			save_y = y;
			while (iteration < max_iterations)
			{
				xx = (x * x - y * y);
				yy = 2 * x * y;

				x = xx + save_x;
				y = yy + save_y;
				if (x + y >  16)
					break ;
				iteration ++;
			}
		
			
			if (iteration == max_iterations)
				bright = 0;
			else
				bright = 16777215;
			printf("%f\n", bright );
			mlx_pixel_put(e->mlx_ptr, e->win_ptr, col, row, bright);
		
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
		draw_mandelbrot(e);
		/* --------------------------- */
		mlx_loop(e->mlx_ptr);
	}
	else 
		ft_putstr("list of available parameters:\n");
	
	return (0);
}