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
# define 	WIDTH 		800
# define 	HEIGHT		600
# define 	MAX 		500

# define MOTION_MASK (1L<<6)
# define MOTION_NOTIFY	6

# define KEY_MOUSE_CLIC_L 1
# define KEY_MOUSE_CLIC_R 2
# define KEY_MOUSE_UP 5
# define KEY_MOUSE_DOWN 4
# define KEY_MOUSE_LEFT 7
# define KEY_MOUSE_RIGHT 6

# define	MANDELBROT 	"mandelbrot_set"

typedef struct		s_env 
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*image_ptr;
	char			*image;
	int				bpp;
	int				en;
	int				ln;
	double			min_x;
	double			max_x;
	double			min_y;
	double			max_y;
	int				red;
	int				green;
	int				blue;
	int				choose_color;
}					t_env;

int			mandelbrot_math(t_env *e, int x, int y);
float		ft_map(float variable_1, float min_1, float max_1, float min_2, float max_2);
int			key_draw(int keycode, t_env *e);
void		foreach_pixel(t_env *e);
void  put_pixel_to_img(t_env *e, int x, int y);
int		init_mlx(t_env *e);
void 		next_draw(t_env *e);
int			mouse_draw(int keycode, int x, int y, t_env *e);

#endif