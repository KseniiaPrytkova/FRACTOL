/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:41:22 by kprytkov          #+#    #+#             */
/*   Updated: 2018/06/06 16:41:23 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void	put_pixel_to_img(t_env *e, int x, int y)
{
 	if ((x >= 0 || x <= WIDTH) && (y >= 0 || y <= HEIGHT))
 	{
		e->image[(x * 4) + (y * WIDTH * 4) + 2] = e->red;
		e->image[(x * 4) + (y * WIDTH * 4) + 1] = e->green;
		e->image[(x * 4) + (y * WIDTH * 4)] = e->blue;
 	}
}

int		init_mlx(t_env *e)
{
	if ((e->mlx_ptr = mlx_init()) == NULL)
		return (0);
	if ((e->win_ptr = mlx_new_window(e->mlx_ptr, WIDTH, HEIGHT, "hello, fractol")) == NULL)
		return (0);
	if ((e->image_ptr = mlx_new_image(e->mlx_ptr, WIDTH, HEIGHT)) == NULL)
  		return (0);
 	if ((e->image = mlx_get_data_addr(e->image_ptr,
 	&e->bpp, &e->ln, &e->en)) == NULL)
 		return (0);
 	e->bpp /= 8;
	return (1);
}

