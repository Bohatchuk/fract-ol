/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <dbohatch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 21:24:46 by dbohatch          #+#    #+#             */
/*   Updated: 2018/09/24 22:48:13 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <pthread.h>
# include <stdlib.h>

# define SIZE			800
# define RATIO			1.3
# define DIV			2
# define ZOOM			30
# define ITER_START		50
# define COLOUR_FIRST	265
# define COLOUR_SECOND	2050
# define COLOUR_THIRD	1677216
# define BLACK			0x000000
# define THREADS		8
# define ZOOM_M			300
# define ZOOM_J			200
# define ZOOM_B			220
# define X_1_M			-2.05
# define Y_1_M			-1.3
# define X_1_J			-2.0
# define Y_1_J			-1.9
# define X_1_B			-2.2
# define Y_1_B			-2.5
# define C_R_J			0.285
# define C_I_J			0.01
# define MOUSE_J		1

typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	int			bpp;
	int			endian;
	int			size_line;
	int			index;
	int			colour;
	int			mouse;
	double		x;
	double		y;
	double		x_1;
	double		y_1;
	double		x_2;
	double		y_2;
	double		iter;
	double		zoom;
	double		y_max;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		it;
	double		temp;
}				t_fractol;

/*
**	functions from pthread_mandelbrot.c
*/
void			*mandelbrot(void *tab);
void			mandelbrot_pthread(t_fractol *fractol);

/*
**	functions from pthread_julia.c
*/
void			*julia(void *tab);
void			julia_pthread(t_fractol *fractol);

/*
**	functions from pthread_burningship.c
*/
void			*burningship(void *tab);
void			burningship_pthread(t_fractol *fractol);

/*
**	functions from fractal_calc.c
*/
void			fractal_calc(t_fractol *fractol);
void			burningship_calc(t_fractol *fractol);
void			julia_calc(t_fractol *fractol);
int				julia_mouse(int x, int y, t_fractol *fractol);
void			mandelbrot_calc(t_fractol *fractol);

/*
**	functions from fractal_init.c
*/
void			fractal_init(t_fractol *fractol);
void			burningship_init(t_fractol *fractol);
void			julia_init(t_fractol *fractol);
void			mandelbrot_init(t_fractol *fractol);

/*
**	functions from functions.c
*/
void			ft_max_zoom(int x, int y, t_fractol *fractol);
void			ft_min_zoom(t_fractol *fractol);
void			put_pxl_to_img(t_fractol *fractol, int x, int y, int color);

/*
**	functions from tools.c
*/
int				exit_fractol(void);
void			fractol_usage(void);
void			info_window(t_fractol *fractol);

/*
**	functions from hook.c
*/
int				key_hooks(int keycode, t_fractol *fractol);
int				key_hooks_2(int keycode, t_fractol *fractol);
int				mouse_hooks(int mousecode, int x, int y, t_fractol *fractol);

/*
**	functions from main.c
*/
void			fractal_name(char **argv, t_fractol *fractol);
void			mlx_win_init(t_fractol *fractol);

#endif
