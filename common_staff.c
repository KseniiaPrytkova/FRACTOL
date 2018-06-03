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
	y  = 1;
	if (keycode == KEY_MOUSE_CLIC_L)
	{
		delta.x = (e->max_x - e->min_x) * e->zoom;
		delta.y = (e->max_y - e->min_y) * e->zoom;
		p.y = ((y - (HEIGHT / 2)) * (delta.y / 2)) / (HEIGHT / 2);
		p.x = ((x - (WIDTH / 2)) * (delta.x / 2)) / (WIDTH / 2);
		e->mouse_x = x - (WIDTH / 2);
		e->mouse_y = y - (HEIGHT / 2);
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
		e->min_y += 0.1 / e->zoom;
		e->max_y += 0.1 / e->zoom;
		next_draw(e);
	}
	if (keycode == 125) /* down */
	{
		e->min_y -= 0.1 / e->zoom;
		e->max_y -= 0.1 / e->zoom;
		next_draw(e);
	}

	if (keycode == 123) /* left */
	{
		e->min_x += 0.8;
		e->max_x += 0.8;
		next_draw(e);
	}
	if (keycode == 124) /* right */
	{
		e->min_x -= 0.8;
		e->max_x -= 0.8;
		next_draw(e);
	}


	if (keycode == 78) /* - */
	{
		e->zoom *= 0.9;
		e->min_x *=  e->zoom;
		e->max_x *=  e->zoom;
		e->min_y *=  e->zoom;
		e->max_y *=  e->zoom;
		next_draw(e);
	}
	if (keycode == 69) /* + */
	{
		e->zoom *= 1.1;
		e->min_x *=  e->zoom;
		e->max_x *=  e->zoom;
		e->min_y *=  e->zoom;
		e->max_y *=  e->zoom;

		next_draw(e);
	}
	printf("move %f min %f max %f\n", e->move_y, e->min_y, e->max_y);
	return (-1);
}

float		ft_map(float variable_1, float min_1, float max_1, float min_2, float max_2)
{
	float variable_2;

	variable_2 = min_2 + (max_2 - min_2) * ((variable_1 - min_1) / (max_1 - min_1));
	return (variable_2);
}