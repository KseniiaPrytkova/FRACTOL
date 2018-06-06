/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_math.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 19:20:38 by kprytkov          #+#    #+#             */
/*   Updated: 2018/05/29 19:20:39 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"


int			mandelbrot_math(t_env *e, int x, int y)
{
	long double mx; // X FOR FORMULA
	long double my; // Y FOR FORMULA
	long double c_im;
	long double c_re;
	long double x_temp;
	int	iteration;

	iteration = 0;
	mx = 0;
	my = 0;
	c_re = ft_map(x, 0, WIDTH, e->min_x, e->max_x);
	c_im = ft_map(y, 0, HEIGHT, e->min_y, e->max_y);
	while (iteration < e->infinity)
	{
		x_temp = (mx * mx - my * my) + c_re;
		my = 2.0f * mx * my + c_im;
		mx = x_temp;
		if ((mx * mx + my * my) > 4.0f)
			break;
		iteration ++;
	}
	return (iteration);
}


int			julia_math(t_env *e, int x, int y)
{
	long double mx; // X FOR FORMULA
	long double my; // Y FOR FORMULA

	long double x_temp;
	int	iteration;

	iteration = 0;
	mx = ft_map((long double)x, 0, (long double)WIDTH, e->min_x, e->max_x);
	my = ft_map((long double)y, 0, (long double)HEIGHT, e->min_y, e->max_y);
	while (iteration < e->infinity)
	{
		x_temp = (mx * mx - my * my) + e->c_re;
		my = 2.0f * mx * my + e->c_im;
		mx = x_temp;
		if ((mx * mx + my * my) > 4.0f)
			break;
		iteration ++;
	}
	return (iteration);
}