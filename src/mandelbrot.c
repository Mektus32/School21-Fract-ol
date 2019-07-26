/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 15:10:24 by ojessi            #+#    #+#             */
/*   Updated: 2019/07/26 15:10:26 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_calc_formul(t_fractol *frac, int *x, double *b, int *y)
{
	int		i;
	double	a;
	double	t;
	double	x0;
	double	y0;

	//a = (*x - (WIDTH / 2.)) / frac->zoom;
	a = -(2.5 - (*x / (frac->zoom) + frac->movex));
	i = -1;
	x0 = a;
	y0 = *b;
	while (++i < frac->iterations)
	{
		t = x0;
		x0 = (x0 * x0) - (y0 * y0) + frac->x0 / WIDTH;
		y0 = (2 * t * y0) + frac->y0 / HEIGHT;

//		x0 = ft_pow_comp(x0, y0, frac->p, &y0) + a + frac->movex;
//		y0 += *b + frac->movey;
		if (x0 * x0 + y0 * y0 > 4)
			break;
	}
	if (i == frac->iterations)
		frac->image->img_data[*y * WIDTH + *x] = 0x000000;
	else
		frac->image->img_data[*y * WIDTH + *x] = frac->color + i * 1000;
}

void	mandelbrot(t_fractol *frac)
{
	int 	x;
	int 	y;
	double	b;

	y = -1;
	while (++y < HEIGHT)
	{
		//b = (-y + (HEIGHT / 2.)) / frac->zoom;
		b = -1.25 + (y / (frac->zoom) + frac->movey);
		x = -1;
		while (++x < WIDTH)
			ft_calc_formul(frac, &x, &b, &y);
	}
	mlx_put_image_to_window(frac->mlx_ptr, frac->win_ptr, frac->image->img_ptr, 0, 0);
}
