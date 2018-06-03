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


int			mandelbrot_math(t_env *e, int x, int y)
{
	double mx; // X FOR FORMULA
	double my; // Y FOR FORMULA
	double c_im;
	double c_re;
	double x_temp;
	int			iteration;

	iteration = 0;
	mx = 0;
	my = 0;
	c_re = ft_map(x, 0, WIDTH, e->min_x, e->max_x);
	c_im = ft_map(y, 0, HEIGHT, e->min_y, e->max_y);
	while (iteration < MAX)
	{
		x_temp = (mx * mx - my * my) + c_re;
		my = 2 * mx * my + c_im;
		mx = x_temp;
		if ((mx * mx + my * my) > 4)
			break;
		iteration ++;
	}
	return (iteration);
}