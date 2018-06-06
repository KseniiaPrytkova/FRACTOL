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
# define 	WIDTH 		600
# define 	HEIGHT		400

# define MOTION_MASK (1L<<6)
# define MOTION_NOTIFY	6

# define KEY_MOUSE_CLIC_L 1
# define KEY_MOUSE_CLIC_R 2
# define KEY_MOUSE_UP 5
# define KEY_MOUSE_DOWN 4
# define KEY_MOUSE_LEFT 7
# define KEY_MOUSE_RIGHT 6

# define	MANDELBROT 	"1"
# define	JULIA 		"2"

typedef struct		s_env 
{
	int	(*function)(struct s_env *e, int x, int y);
	void			*mlx_ptr;
	void			*win_ptr;
	void			*image_ptr;
	char			*image;
	int				bpp;
	int				en;
	int				ln;
	float			infinity;
	long double			c_re;
	long double			c_im;
	long double			min_x;
	long double			max_x;
	long double			min_y;
	long double			max_y;
	int				red;
	int				green;
	int				blue;
	int				choose_color;
	int				choose_fractal;
	int				julia_mode_on;
	long double 			center_x;
	long double			center_y;

	long double			zoom;
	long double			move_x;
	long double 			move_y;
	long double			start_y;
	long double			end_y;

}					t_env;

void	init(t_env *e);
long double		ft_map(long double variable_1, long double min_1, long double max_1, long double min_2, long double max_2);
int			mandelbrot_math(t_env *e, int x, int y);
int			julia_math(t_env *e, int x, int y);


int			key_draw(int keycode, t_env *e);
void		foreach_pixel(t_env *e);
void  		put_pixel_to_img(t_env *e, int x, int y);
int			init_mlx(t_env *e);
void 		next_draw(t_env *e);
void		choose_color(t_env *e, int color);
int			mouse_zoom(int keycode, int x, int y, t_env *e);
int 		mouse_for_julia(int x, int y, t_env *e);

#endif