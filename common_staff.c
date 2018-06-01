/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_staff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 19:29:17 by kprytkov          #+#    #+#             */
/*   Updated: 2018/05/29 19:29:18 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void 		next_draw(t_env *e)
{
	mlx_clear_window(e->mlx_ptr, e->win_ptr);
	foreach_pixel(e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->image_ptr, 0, 0);
}

int			mouse_draw(int keycode, int x, int y, t_env *e)
{
	x = 1;
	y = 1;
	if (keycode == KEY_MOUSE_CLIC_L)
	{
		e->min_x *= 0.8;
		e->max_x *= 0.8;
		e->min_y *= 0.8;
		e->max_y *= 0.8;
		next_draw(e);
	}
	return (0);
}

int			key_draw(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 126) /* up */
	{
		e->min_y += 0.1;
		e->max_y += 0.1;
		next_draw(e);
	}
	if (keycode == 125) /* down */
	{
		e->min_y -= 0.1;
		e->max_y -= 0.1;
		next_draw(e);
	}
	if (keycode == 123) /* left */
	{
		e->min_x += 0.1;
		e->max_x += 0.1;
		next_draw(e);
	}
	if (keycode == 124) /* right */
	{
		e->min_x -= 0.1;
		e->max_x -= 0.1;
		next_draw(e);
	}
	if (keycode == 78) /* - */
	{
		e->min_x *= 0.8;
		e->max_x *= 0.8;
		e->min_y *= 0.8;
		e->max_y *= 0.8;
		next_draw(e);
	}
	if (keycode == 69) /* + */
	{
		e->min_x *= 0.8;
		e->max_x *= 0.8;
		e->min_y *= 0.8;
		e->max_y *= 0.8;
		next_draw(e);
	}
	return (-1);
}

float		ft_map(float variable_1, float min_1, float max_1, float min_2, float max_2)
{
	float variable_2;

	variable_2 = min_2 + (max_2 - min_2) * ((variable_1 - min_1) / (max_1 - min_1));
	return (variable_2);
}