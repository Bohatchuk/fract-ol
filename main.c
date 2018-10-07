/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <dbohatch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 20:27:05 by dbohatch          #+#    #+#             */
/*   Updated: 2018/09/24 22:51:42 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_win_init(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, SIZE, SIZE,
		"Dbohatch's Fractol");
	fractol->img = mlx_new_image(fractol->mlx, SIZE, SIZE);
	fractol->img_ptr = mlx_get_data_addr(fractol->img, &fractol->bpp,
		&fractol->size_line, &fractol->endian);
}

void	fractal_name(char **argv, t_fractol *fractol)
{
	if (!ft_strcmp(argv[1], "burningship"))
		fractol->index = 0;
	else if (!ft_strcmp(argv[1], "julia"))
		fractol->index = 1;
	else if (!ft_strcmp(argv[1], "mandelbrot"))
		fractol->index = 2;
	else
	{
		fractol_usage();
		exit_fractol();
	}
}

int		main(int argc, char **argv)
{
	t_fractol	*fractol;

	if (!(fractol = (t_fractol *)malloc(sizeof(t_fractol))))
		ft_error("Malloc error");
	if (argc == 2)
	{
		fractal_name(argv, fractol);
		mlx_win_init(fractol);
		fractal_init(fractol);
		mlx_hook(fractol->win, 6, 1L << 6, julia_mouse, fractol);
		mlx_hook(fractol->win, 17, 1L << 17, exit_fractol, fractol);
		mlx_hook(fractol->win, 2, 1L << 1, key_hooks, fractol);
		mlx_mouse_hook(fractol->win, mouse_hooks, fractol);
		mlx_loop(fractol->mlx);
	}
	else
		fractol_usage();
	return (0);
}
