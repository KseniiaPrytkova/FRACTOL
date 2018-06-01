/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:14:59 by kprytkov          #+#    #+#             */
/*   Updated: 2018/06/01 16:14:59 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

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