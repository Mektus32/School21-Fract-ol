/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 15:52:08 by ojessi            #+#    #+#             */
/*   Updated: 2019/07/26 15:55:25 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int 	expose(t_fractol *frac)
{
	(void)frac;
	exit(0);
	return (0);
}

int 	mouse(int button, int x, int y, t_fractol *frac)
{
	if (button == 4)
	{
		frac->movex = (x / frac->zoom + frac->movex) - (x / (frac->zoom * 1.3));
		frac->movey = (y / frac->zoom + frac->movey) - (y / (frac->zoom * 1.3));
		frac->zoom *= 1.3;
	}
	else if (button == 5 && frac->zoom > 50)
	{
		frac->movex = (x / frac->zoom + frac->movex) - (x / (frac->zoom / 1.3));
		frac->movey = (y / frac->zoom + frac->movey) - (y / (frac->zoom / 1.3));
		frac->zoom /= 1.3;
	}
	if (button == 1)
		frac->move = (frac->move + 1) % 2;
//	mlx_clear_window(frac->mlx_ptr, frac->win_ptr);
//	if (frac->numfrac == 1)
//		mandelbrot(frac);
	return (0);
}

int 	keyboard(int key, t_fractol *frac)
{
	frac = frac + 1 - 1;
	if (key == 53)
		exit(0);
	if (key == 24)
		frac->iterations++;
	else if (key == 27 && frac->iterations > 10)
		frac->iterations--;
	key == 126 ? frac->movey -= 5 / frac->zoom : 0;
	key == 125 ? frac->movey += 5 / frac->zoom : 0;
	key == 123 ? frac->movex += 5 / frac->zoom : 0;
	key == 124 ? frac->movex -= 5 / frac->zoom : 0;
//	mlx_clear_window(frac->mlx_ptr, frac->win_ptr);
//	if (frac->numfrac == 1)
//		mandelbrot(frac);
	return (0);
}

int		jul(int x, int y, t_fractol *frac)
{
	if (frac->numfrac == 1 && frac->move == 1)
	{
		frac->x0 = x / 1.2;
		frac->y0 = y / 1.2;
	}
	//mlx_clear_window(frac->mlx_ptr, frac->win_ptr);
//	if (frac->numfrac == 1)
//		mandelbrot(frac);
	return (0);
}

int 	color(t_fractol *frac)
{
	for (int i = 0; i < HEIGHT * 4; i++)
	{
		for (int j = 0; j < WIDTH; j += 4)
		{
			frac->cart[i * WIDTH + j] += frac->cart[i * WIDTH + j] + 2  > 250 ? -20 : 2;
			frac->cart[i * WIDTH + j + 1] += frac->cart[i * WIDTH + j + 1] + 2  > 250 ? -20 : 3;
			frac->cart[i * WIDTH + j + 2] += frac->cart[i * WIDTH + j + 2] + 2  > 250 ? -20 : 4;
		}
	}
	usleep(100000);
//	for (int i = 0; i < HEIGHT * 4; i++)
//	{
//		for (int j = 0; j < WIDTH; j += 4)
//		{
//			frac->cart[i * WIDTH + j] -= 10;
//			frac->cart[i * WIDTH + j + 1] -= 10;
//			frac->cart[i * WIDTH + j + 2] -= 10;
//		}
//	}
//	usleep(100000);
	mlx_clear_window(frac->mlx_ptr, frac->win_ptr);
	mlx_put_image_to_window(frac->mlx_ptr, frac->win_ptr, frac->image->img_ptr, 0, 0);
	return (0);
}

void	ft_key_hook(t_fractol *frac)
{
	mlx_hook(frac->win_ptr, 2, 0, keyboard, frac);
	mlx_hook(frac->win_ptr, 17, 0, expose, frac);
	mlx_hook(frac->win_ptr, 4, 0, mouse, frac);
	mlx_hook(frac->win_ptr, 6, 0, jul, frac);
	mlx_loop_hook(frac->mlx_ptr, color, frac);
}
