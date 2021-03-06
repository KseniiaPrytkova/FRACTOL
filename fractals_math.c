/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_math.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 19:12:53 by kprytkov          #+#    #+#             */
/*   Updated: 2018/06/10 19:12:54 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int		mandelbrot_math(t_env *e, int x, int y)
{
	long double mx;
	long double my;
	long double c_im;
	long double c_re;
	long double x_temp;

	e->iteration = 0;
	mx = 0.0;
	my = 0.0;
	c_re = ft_map(x, add_params(0, WIDTH, e->min_x, e->max_x));
	c_im = ft_map(y, add_params(0, HEIGHT, e->min_y, e->max_y));
	while (e->iteration < e->infinity)
	{
		x_temp = (mx * mx - my * my) + c_re;
		my = 2.0f * mx * my + c_im;
		mx = x_temp;
		if ((mx * mx + my * my) > 4.0f)
			break ;
		e->iteration++;
	}
	return (e->iteration);
}

int		julia_math(t_env *e, int x, int y)
{
	long double mx;
	long double my;
	long double x_temp;

	e->iteration = 0;
	mx = ft_map(x, add_params(0, WIDTH, e->min_x, e->max_x));
	my = ft_map(y, add_params(0, HEIGHT, e->min_y, e->max_y));
	while (e->iteration < e->infinity)
	{
		x_temp = (mx * mx - my * my) + e->c_re;
		my = 2.0f * mx * my + e->c_im;
		mx = x_temp;
		if ((mx * mx + my * my) > 4.0f)
			break ;
		e->iteration++;
	}
	return (e->iteration);
}

int		burning_ship_math(t_env *e, int x, int y)
{
	long double mx;
	long double my;
	long double c_im;
	long double c_re;
	long double x_temp;

	e->iteration = 0;
	mx = 0.0;
	my = 0.0;
	c_re = ft_map(x, add_params(0, WIDTH, e->min_x, e->max_x));
	c_im = ft_map(y, add_params(0, HEIGHT, e->min_y, e->max_y));
	while (e->iteration < e->infinity)
	{
		x_temp = (mx * mx - my * my) + c_re;
		my = fabsl(2.0 * mx * my + c_im);
		mx = fabsl(x_temp);
		if ((mx * mx + my * my) > 4.0f)
			break ;
		e->iteration++;
	}
	return (e->iteration);
}

int		sierpinski_carpet(t_env *e, int x, int y)
{
	int i;

	i = 0;
	x *= e->zoom;
	y *= e->zoom;
	while (i < e->infinity)
	{
		if ((x % 3 == 1) && (y % 3 == 1))
			return (0);
		x /= 3;
		y /= 3;
		i++;
	}
	return (20);
}

int		douady_rabbit(t_env *e, int x, int y)
{
	long double mx;
	long double my;
	long double x_temp;

	e->iteration = 0;
	mx = ft_map((long double)x, add_params(0, WIDTH, e->min_x, e->max_x));
	my = ft_map((long double)y, add_params(0, HEIGHT, e->min_y, e->max_y));
	while (e->iteration < e->infinity)
	{
		x_temp = (mx * mx - my * my) - 0.123;
		my = 2.0f * mx * my + 0.745f;
		mx = x_temp;
		if ((mx * mx + my * my) > 4.0f)
			break ;
		e->iteration++;
	}
	return (e->iteration);
}
