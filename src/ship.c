/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 14:37:42 by ojessi            #+#    #+#             */
/*   Updated: 2019/07/27 14:37:43 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_calc_ship(t_fractol *frac, int *x, double *b, int *y)
{
	int		i;
	double	a;
	double	t;
	double	x0;
	double	y0;

	a = -(2.5 - (*x / (frac->zoom) + frac->movex));
	i = -1;
	x0 = 0;
	y0 = 0;
	while (++i < frac->iterations)
	{
		t = x0;
		x0 = fabs((x0 * x0) - (y0 * y0) + a);
		y0 = fabs((2 * t * y0) + *b);
		if (x0 * x0 + y0 * y0 > 4)
			break;
	}
	if (i == frac->iterations)
		frac->image->img_data[*y * WIDTH + *x] = 0x000000;
	else
	{
		if (frac->choise == 1)
			frac->image->img_data[*y * WIDTH + *x] = 0xFFFFFF;
		else if (frac->choise == 2)
		{
			if (i % 2 == 0)
				frac->image->img_data[*y * WIDTH + *x] = 0xFF0000;
			else if (i % 3 == 0)
				frac->image->img_data[*y * WIDTH + *x] = 0x00FF00;
			else if (i % 4 == 0)
				frac->image->img_data[*y * WIDTH + *x] = 0x0000FF;
			else
				frac->image->img_data[*y * WIDTH + *x] = 0x9914FF;
		}
		else
			frac->image->img_data[*y * WIDTH + *x] = frac->color * i;
	}
}

void	ship(t_fractol *frac)
{
	int 	x;
	int 	y;
	double	b;

	y = -1;
	while (++y < HEIGHT)
	{
		b = -1.25 + (y / (frac->zoom) + frac->movey);
		x = -1;
		while (++x < WIDTH)
			ft_calc_ship(frac, &x, &b, &y);
	}
	mlx_put_image_to_window(frac->mlx_ptr, frac->win_ptr, frac->image->img_ptr, 0, 0);
}
