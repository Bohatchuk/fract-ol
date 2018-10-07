/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <dbohatch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 20:27:05 by dbohatch          #+#    #+#             */
/*   Updated: 2018/09/24 22:56:31 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hooks_2(int keycode, t_fractol *fractol)
{
	if (keycode == 18)
		fractol->colour = COLOUR_FIRST;
	else if (keycode == 19)
		fractol->colour = COLOUR_SECOND;
	else if (keycode == 20)
		fractol->colour = COLOUR_THIRD;
	else if (keycode == 35)
	{
		if (fractol->mouse == MOUSE_J)
			fractol->mouse = 0;
		else
			fractol->mouse = MOUSE_J;
	}
	return (0);
}

int		key_hooks(int keycode, t_fractol *fractol)
{
	if (keycode == 53)
		exit_fractol();
	else if (keycode == 69)
		fractol->iter++;
	else if (keycode == 78)
		fractol->iter--;
	else if (keycode == 123)
		fractol->x_1 -= ZOOM / fractol->zoom;
	else if (keycode == 124)
		fractol->x_1 += ZOOM / fractol->zoom;
	else if (keycode == 125)
		fractol->y_1 += ZOOM / fractol->zoom;
	else if (keycode == 126)
		fractol->y_1 -= ZOOM / fractol->zoom;
	else if (keycode == 49)
		fractal_init(fractol);
	key_hooks_2(keycode, fractol);
	fractal_calc(fractol);
	return (0);
}

int		mouse_hooks(int mousecode, int x, int y, t_fractol *fractol)
{
	if (mousecode == 4 || mousecode == 1)
		ft_max_zoom(x, y, fractol);
	else if (mousecode == 5 || mousecode == 2)
		ft_min_zoom(fractol);
	fractal_calc(fractol);
	return (0);
}
