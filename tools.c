/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <dbohatch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 21:11:16 by dbohatch          #+#    #+#             */
/*   Updated: 2018/09/24 22:53:49 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	info_window(t_fractol *fractol)
{
	char	*numb;
	char	*info;

	numb = ft_itoa(fractol->iter);
	info = ft_strjoin("iterations: ", numb);
	mlx_string_put(fractol->mlx, fractol->win, 5, 10, 0xFF0000, info);
	mlx_string_put(fractol->mlx, fractol->win, 5, 30, 0xFFA500,
		"+ to max iterations");
	mlx_string_put(fractol->mlx, fractol->win, 5, 50, 0xFFFF00,
		"- to min iterations");
	mlx_string_put(fractol->mlx, fractol->win, 5, 70, 0x008000,
		"arrows to move img");
	mlx_string_put(fractol->mlx, fractol->win, 5, 90, 0x0000FF,
		"space to reset");
	mlx_string_put(fractol->mlx, fractol->win, 5, 110, 0x000080,
		"1, 2, 3 to change colour");
	mlx_string_put(fractol->mlx, fractol->win, 5, 130, 0x800080,
		"p to freeze");
	ft_strdel(&numb);
	ft_strdel(&info);
}

void	fractol_usage(void)
{
	ft_putendl("Usage:		./fractol name_of_the_fractal");
	ft_putendl("Fractals:	[ burningship ]	[ julia ] [ mandelbrot ]");
}

int		exit_fractol(void)
{
	exit(1);
	return (0);
}
