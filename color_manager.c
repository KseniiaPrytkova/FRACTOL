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

void		choose_color(t_env *e, int depth)
{
	if (e->choose_color == 0)
	{
		if (depth == e->infinity )
		{
			e->red = 0;
			e->blue = 0;
			e->green = 0;
		}
		else
		{
			e->red = (depth * 3) % 255;
			e->blue = (depth * 7) % 255;
			e->green = (depth * 4) % 255;
		}
		
	}
	else if (e->choose_color == 1)
	{
		e->red = (depth * 7) % 255;
		e->blue = (depth * 2) % 70;
		e->green = (depth * 3) % 4;
	}
	else if (e->choose_color == 2)
	{
		e->red = (depth * 30) % 255;
		e->blue = (depth * 80) % 255;
		e->green = (depth * 40) % 255;
	}
}