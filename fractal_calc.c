/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <dbohatch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 21:21:36 by dbohatch          #+#    #+#             */
/*   Updated: 2018/09/24 22:43:52 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_calc(t_fractol *fractol)
{
	fractol->c_r = fractol->x / fractol->zoom + fractol->x_1;
	fractol->c_i = fractol->y / fractol->zoom + fractol->y_1;
	fractol->z_r = 0;
	fractol->z_i = 0;
	fractol->it = 0;
	while (fractol->z_r * fractol->z_r + fractol->z_i * fractol->z_i < 4 &&
		fractol->it < fractol->iter)
	{
		fractol->temp = fractol->z_r;
		fractol->z_r = fractol->z_r * fractol->z_r - fractol->z_i *
			fractol->z_i + fractol->c_r;
		fractol->z_i = 2 * fractol->z_i * fractol->temp + fractol->c_i;
		fractol->it++;
	}
	if (fractol->it == fractol->iter)
		put_pxl_to_img(fractol, fractol->x, fractol->y, BLACK);
	else
		put_pxl_to_img(fractol, fractol->x, fractol->y,
			(fractol->colour * fractol->it));
}

int		julia_mouse(int x, int y, t_fractol *fractol)
{
	if (fractol->index == 1 && fractol->mouse == 1)
	{
		fractol->c_r = x * 2;
		fractol->c_i = y * 2 - SIZE;
		fractal_calc(fractol);
	}
	return (0);
}

void	julia_calc(t_fractol *fractol)
{
	fractol->z_r = fractol->x / fractol->zoom + fractol->x_1;
	fractol->z_i = fractol->y / fractol->zoom + fractol->y_1;
	fractol->it = 0;
	while (fractol->z_r * fractol->z_r + fractol->z_i * fractol->z_i < 4 &&
		fractol->it < fractol->iter)
	{
		fractol->temp = fractol->z_r;
		fractol->z_r = fractol->z_r * fractol->z_r - fractol->z_i *
			fractol->z_i - 0.8 + (fractol->c_r / SIZE);
		fractol->z_i = 2 * fractol->z_i * fractol->temp + fractol->c_i / SIZE;
		fractol->it++;
	}
	if (fractol->it == fractol->iter)
		put_pxl_to_img(fractol, fractol->x, fractol->y, BLACK);
	else
		put_pxl_to_img(fractol, fractol->x, fractol->y,
			(fractol->colour * fractol->it));
}

void	burningship_calc(t_fractol *fractol)
{
	fractol->c_r = fractol->x / fractol->zoom + fractol->x_1;
	fractol->c_i = fractol->y / fractol->zoom + fractol->y_1;
	fractol->z_r = 0;
	fractol->z_i = 0;
	fractol->it = 0;
	while (fractol->z_r * fractol->z_r + fractol->z_i * fractol->z_i < 4 &&
		fractol->it < fractol->iter)
	{
		fractol->temp = fractol->z_r * fractol->z_r - fractol->z_i *
			fractol->z_i + fractol->c_r;
		fractol->z_i = fabs(2 * fractol->z_r * fractol->z_i) + fractol->c_i;
		fractol->z_r = fractol->temp;
		fractol->it++;
	}
	if (fractol->it == fractol->iter)
		put_pxl_to_img(fractol, fractol->x, fractol->y, BLACK);
	else
		put_pxl_to_img(fractol, fractol->x, fractol->y,
			(fractol->colour * fractol->it));
}

void	fractal_calc(t_fractol *fractol)
{
	if (fractol->iter < 0)
		fractol->iter = 0;
	if (fractol->index == 0)
		burningship_pthread(fractol);
	else if (fractol->index == 1)
		julia_pthread(fractol);
	else if (fractol->index == 2)
		mandelbrot_pthread(fractol);
	info_window(fractol);
}
