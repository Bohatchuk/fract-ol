/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <dbohatch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 21:49:08 by dbohatch          #+#    #+#             */
/*   Updated: 2018/09/24 22:44:30 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_init(t_fractol *fractol)
{
	fractol->iter = ITER_START;
	fractol->zoom = ZOOM_M;
	fractol->x_1 = X_1_M;
	fractol->y_1 = Y_1_M;
	fractol->colour = COLOUR_FIRST;
}

void	julia_init(t_fractol *fractol)
{
	fractol->iter = ITER_START;
	fractol->zoom = ZOOM_J;
	fractol->x_1 = X_1_J;
	fractol->y_1 = Y_1_J;
	fractol->colour = COLOUR_FIRST;
	fractol->c_r = C_R_J;
	fractol->c_i = C_I_J;
	fractol->mouse = MOUSE_J;
}

void	burningship_init(t_fractol *fractol)
{
	fractol->iter = ITER_START;
	fractol->zoom = ZOOM_B;
	fractol->x_1 = X_1_B;
	fractol->y_1 = Y_1_B;
	fractol->colour = COLOUR_FIRST;
}

void	fractal_init(t_fractol *fractol)
{
	if (fractol->index == 0)
		burningship_init(fractol);
	else if (fractol->index == 1)
		julia_init(fractol);
	else if (fractol->index == 2)
		mandelbrot_init(fractol);
	fractal_calc(fractol);
}
