/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <dbohatch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 20:27:05 by dbohatch          #+#    #+#             */
/*   Updated: 2018/09/24 22:49:55 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pxl_to_img(t_fractol *fractol, int x, int y, int color)
{
	if (fractol->x < SIZE && fractol->y < SIZE)
	{
		color = mlx_get_color_value(fractol->mlx, color);
		ft_memcpy(fractol->img_ptr + 4 * SIZE * y + x * 4, &color, sizeof(int));
	}
}

void	ft_max_zoom(int x, int y, t_fractol *fractol)
{
	fractol->x_2 = x;
	fractol->y_2 = y;
	fractol->x_1 = (x / fractol->zoom + fractol->x_1) - ((fractol->zoom *
		RATIO) / DIV);
	fractol->x_1 += ((fractol->zoom * RATIO) / DIV) - (x / (fractol->zoom *
		RATIO));
	fractol->y_1 = (y / fractol->zoom + fractol->y_1) - ((fractol->zoom *
		RATIO) / DIV);
	fractol->y_1 += ((fractol->zoom * RATIO) / DIV) - (y / (fractol->zoom *
		RATIO));
	fractol->zoom *= RATIO;
	fractol->iter++;
}

void	ft_min_zoom(t_fractol *fractol)
{
	fractol->x_1 = (fractol->x_2 / fractol->zoom + fractol->x_1) -
		((fractol->zoom / RATIO) / DIV);
	fractol->x_1 += ((fractol->zoom / RATIO) / DIV) - (fractol->x_2 /
		(fractol->zoom / RATIO));
	fractol->y_1 = (fractol->y_2 / fractol->zoom + fractol->y_1) -
		((fractol->zoom / RATIO) / DIV);
	fractol->y_1 += ((fractol->zoom / RATIO) / DIV) - (fractol->y_2 /
		(fractol->zoom / RATIO));
	fractol->zoom /= RATIO;
	fractol->iter--;
}
