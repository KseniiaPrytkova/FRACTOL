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
# define 	WIDTH 		1200
# define 	HEIGHT		800
# define 	MAX 		100
# define	MANDELBROT 	"mandelbrot_set"


typedef struct		s_env 
{
	void			*mlx_ptr;
	void			*win_ptr;
	double			min_2_re;
	double			max_2_re;
	double			min_2_im;
	double			max_2_im;
	int				pix_r;
	int				pix_g;
	int				pix_b;
	int 			is_first_time;


}					t_env;

int			mandelbrot_math(t_env *e, int x, int y);
double		ft_map(double variable_1, double min_1, double max_1, double min_2, double max_2);
int			key_draw(int keycode, t_env *e);
void		foreach_pixel(t_env *e);

#endif