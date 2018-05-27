/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 17:04:39 by kprytkov          #+#    #+#             */
/*   Updated: 2018/05/27 17:04:40 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "../includes/libft.h"

# include <stdio.h> /* for printf */

# define WIDTH 		1200
# define HEIGHT		800

typedef struct		s_env 
{
	void		*mlx;
	void		*win;
}					t_env;
#endif