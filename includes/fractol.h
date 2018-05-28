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
# include "../libft/libft.h"

# include <stdio.h> /* for printf */

// # define WIDTH 		1200
// # define HEIGHT		800
# define WIDTH 		360
# define HEIGHT		360

typedef struct		s_env 
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_env;
#endif