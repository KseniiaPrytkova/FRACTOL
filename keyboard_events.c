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

static void		guess_color(int keycode, t_env *e)
{
	if (keycode == 18)
	{
		e->choose_color = 0;
		next_draw(e);
	}
	if (keycode == 19)
	{
		e->choose_color = 1;
		next_draw(e);
	}
	if (keycode == 20)
	{
		e->choose_color = 2;
		next_draw(e);
	}
	if (keycode == 21)
	{
		e->choose_color = 3;
		next_draw(e);
	}
}

static int		key_move(int keycode, t_env *e)
{
	if (keycode == 125)
	{
		e->min_y += 0.1 * e->zoom;
		e->max_y += 0.1 * e->zoom;
		next_draw(e);
	}
	if (keycode == 126)
	{
		e->min_y -= 0.1 * e->zoom;
		e->max_y -= 0.1 * e->zoom;
		next_draw(e);
	}
	if (keycode == 124)
	{
		e->min_x += 0.1 * e->zoom;
		e->max_x += 0.1 * e->zoom;
		next_draw(e);
	}
	if (keycode == 123)
	{
		e->min_x -= 0.1 * e->zoom;
		e->max_x -= 0.1 * e->zoom;
		next_draw(e);
	}
	return (-1);
}

int				key_draw(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(1);
	key_move(keycode, e);
	if (keycode == 256)
	{
		e->julia_mode_on = (e->julia_mode_on + 1) % 2;
	}
	if (keycode == 13)
	{
		e->infinity += 10;
		next_draw(e);
	}
	if (keycode == 14)
	{
		e->infinity -= 10;
		next_draw(e);
	}
	if (keycode == 49)
	{
		init(e);
		next_draw(e);
	}
	guess_color(keycode, e);
	return (-1);
}
