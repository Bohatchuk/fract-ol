/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <dbohatch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 20:27:05 by dbohatch          #+#    #+#             */
/*   Updated: 2018/09/24 22:52:45 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*julia(void *tab)
{
	double		tmp;
	t_fractol	*fractol;

	fractol = (t_fractol *)tab;
	fractol->x = 0;
	tmp = fractol->y;
	while (fractol->x < SIZE)
	{
		fractol->y = tmp;
		while (fractol->y < fractol->y_max)
		{
			julia_calc(fractol);
			fractol->y++;
		}
		fractol->x++;
	}
	return (tab);
}

void	julia_pthread(t_fractol *fractol)
{
	t_fractol	tab[THREADS];
	pthread_t	t[THREADS];
	int			i;

	i = -1;
	while (++i < THREADS)
	{
		ft_memcpy((void*)&tab[i], (void*)fractol, sizeof(t_fractol));
		tab[i].y = 100 * i;
		tab[i].y_max = 100 * (i + 1);
	}
	i = 0;
	while (++i <= THREADS)
		pthread_create(&t[i - 1], NULL, julia, &tab[i - 1]);
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}
