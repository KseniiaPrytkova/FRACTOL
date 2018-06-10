/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 20:19:17 by kprytkov          #+#    #+#             */
/*   Updated: 2018/06/10 20:19:18 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

t_map		add_params(long double a, long double b,
	long double c, long double d)
{
	t_map p;

	p.min_in = a;
	p.max_in = b;
	p.min_out = c;
	p.max_out = d;
	return (p);
}

long double	ft_map(long double x, t_map p)
{
	long double ret;

	ret = p.min_out + (p.max_out - p.min_out) * ((x - p.min_in)
	/ (p.max_in - p.min_in));
	return (ret);
}

void		put_pixel_to_img(t_env *e, int x, int y)
{
	if ((x >= 0 || x <= WIDTH) && (y >= 0 || y <= HEIGHT))
	{
		e->image[(x * 4) + (y * WIDTH * 4) + 2] = e->red;
		e->image[(x * 4) + (y * WIDTH * 4) + 1] = e->green;
		e->image[(x * 4) + (y * WIDTH * 4)] = e->blue;
	}
}

int			init_mlx(t_env *e)
{
	if ((e->mlx_ptr = mlx_init()) == NULL)
		return (0);
	if ((e->win_ptr = mlx_new_window(e->mlx_ptr, WIDTH, HEIGHT,
		"hello, fractal")) == NULL)
		return (0);
	if ((e->image_ptr = mlx_new_image(e->mlx_ptr, WIDTH, HEIGHT)) == NULL)
		return (0);
	if ((e->image = mlx_get_data_addr(e->image_ptr,
	&e->bpp, &e->ln, &e->en)) == NULL)
		return (0);
	e->bpp /= 8;
	return (1);
}
