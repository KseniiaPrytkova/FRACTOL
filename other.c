/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:15:18 by kprytkov          #+#    #+#             */
/*   Updated: 2018/06/01 16:15:19 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void  put_pixel_to_img(t_env *e, int x, int y)
{
 if ((x >= 0 || x <= WIDTH) && (y >= 0 || y <= HEIGHT))
 {
 	 e->image[(x * 4) + (y * WIDTH * 4) + 2] = e->red;
 	 e->image[(x * 4) + (y * WIDTH * 4) + 1] = e->green;
 	 e->image[(x * 4) + (y * WIDTH * 4)] = e->blue;
 }
}