/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_logics.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 19:20:38 by kprytkov          #+#    #+#             */
/*   Updated: 2018/05/29 19:20:39 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int	mandelbrot_math(t_env *e, int x, int y)
{
	long double mx; // X FOR FORMULA
	long double my; // Y FOR FORMULA
	long double c_im;
	long double c_re;
	long double x_temp;
	int				iteration;

	e->min_2_re = -1.5;
	e->max_2_re = 1;
	e->min_2_im = -1;
	e->max_2_im = 1;
	iteration = 0;
	mx = 0;
	my = 0;
	c_re = ft_map(x, 0, WIDTH, e->min_2_re, e->max_2_re);
	c_im = ft_map(y, 0, HEIGHT, e->min_2_im, e->max_2_im);
	while (iteration < MAX)
	{
		x_temp = (mx * mx - my * my) + c_re;
		my = 2 * mx * my + c_im;
		mx = x_temp;
		if ((mx * mx + my * my)  > 4)
			break;
		iteration ++;
	}

	return (iteration);
}