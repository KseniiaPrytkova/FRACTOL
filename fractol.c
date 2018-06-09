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

static int 	arguments_handler(char *str)
{
	if (ft_strcmp(str, MANDELBROT) == 0)
		return (1);
	else if (ft_strcmp(str, JULIA) == 0)
		return (2);
	else if (ft_strcmp(str, BURNING_SHIP) == 0)
		return (3);
	else if (ft_strcmp(str, SIERPINSKI_CARPET) == 0)
		return (4);
		else if (ft_strcmp(str, DOUADY_RABBIT) == 0)
		return (5);
	else
		return (0);
}

static void param_list(void)
{
	ft_putstr("List of available parameters:\n");
	ft_putstr("1: "MANDELBROT"\n");
	ft_putstr("2: "JULIA"\n");
	ft_putstr("2: "BURNING_SHIP"\n");
	ft_putstr("2: "SIERPINSKI_CARPET"\n");
	ft_putstr("2: "DOUADY_RABBIT"\n");

}	

static void	tips(t_env *e)
{
	if (e->choose_fractal == 1)
	{
		ft_putstr("MANDELBROT'S LEGEND:\n");
		ft_putstr("MOVE: up || down || left || right\n");
		ft_putstr("ZOOM: mouse wheel || mouse click (left + && right -)\n");
		ft_putstr("CHANGE THE COLOR DEPTH: W || E\n");
	}
	else if (e->choose_fractal == 2)
	{
		ft_putstr("JULIA'S LEGEND:\n");
		ft_putstr("MOVE: up || down || left || right\n");
		ft_putstr("MOVING MODE ON/OFF: space\n");
		ft_putstr("MOVE JULIA: mouse click || mouse cursor\n");
	}
	
}
		



int			main(int argc, char *argv[])
{
	if (argc == 2 && (arguments_handler(argv[1]) != 0))
	{
		t_env 	*e;

		if (!(e = malloc(sizeof(t_env))))
			return (0);
		if (init_mlx(e) == 0)
			return (0);
		e->choose_fractal = arguments_handler(argv[1]);
		tips(e);	
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
		param_list();
	return (0);
}