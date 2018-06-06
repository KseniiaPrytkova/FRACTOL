/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 17:30:09 by kprytkov          #+#    #+#             */
/*   Updated: 2018/06/06 17:30:10 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void		choose_color(t_env *e, int color)
{
	if (e->choose_color == 0)
	{
		if (color == e->infinity )
		{
			e->red = 0;
			e->blue = 0;
			e->green = 0;
		}
		else
		{
			e->red = (color * 3) % 255;
			e->blue = (color * 7) % 255;
			e->green = (color * 4) % 255;
		}
		
	}
	if (e->choose_color == 1)
	{
		e->red = 255;
	}
	if (e->choose_color == 2)
	{
		e->red = 255;
	}
}