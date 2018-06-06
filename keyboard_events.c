/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:19:41 by kprytkov          #+#    #+#             */
/*   Updated: 2018/06/06 16:19:42 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int			key_draw(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 125) /* up */
	{
		e->min_y += 0.1 / e->zoom;
		e->max_y += 0.1 / e->zoom;
		next_draw(e);
	}
	if (keycode == 126) /* down */
	{
		e->min_y -= 0.1 / e->zoom;
		e->max_y -= 0.1 / e->zoom;
		next_draw(e);
	}
	if (keycode == 124) /* left */
	{
		e->min_x += 0.1 / e->zoom;
		e->max_x += 0.1 / e->zoom;
		next_draw(e);
	}
	if (keycode == 123) /* right */
	{
		e->min_x -= 0.1 / e->zoom;
		e->max_x -= 0.1 / e->zoom;
		next_draw(e);
	}
	if (keycode == 49) /* space */
	{
		e->julia_mode_on = (e->julia_mode_on + 1) % 2;
	}
	if (keycode == 13) /* W */
	{
		e->infinity += 10;
		next_draw(e);
	}
	if (keycode == 14) /* E */
	{
		e->infinity -= 10;
		next_draw(e);
	}
	return (-1);
}