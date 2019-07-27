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

int 	color(t_fractol *frac);

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
	color(frac);
	return (0);
}

int		jul(int x, int y, t_fractol *frac)
{
	if (frac->numfrac == 1 && frac->move == 1)
	{
		frac->x0 = x / 1.2;
		frac->y0 = y / 1.2;
	}
	color(frac);
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
//	if (key == 18)
//		frac->choise = 1;
//	else if (key == 19)
//		frac->choise = 2;
//	else if (key == 13)
//		frac->w = (frac->w + 1) % 2;
//	if (key == 69 && frac->speed < 10)
//		frac->speed++;
//	else if (key == 78 && frac->speed > 2)
//		frac->speed--;

	color(frac);
	return (0);
}

int 	color(t_fractol *frac)
{
//	int 	red;
//	int 	green;
//	int 	blue;
//
//	printf("red->[%d] green->[%d] blue->[%d]\n", (frac->color >> 16) & 0xFF, (frac->color >> 8) & 0xFF, (frac->color & 0xFF));
//	red = (frac->color >> 16) & 0xFF;
//	green = (frac->color >> 8) & 0xFF;
//	blue = frac->color & 0xFF;
//	if (frac->w == 1)
//	{
//		if (red <= 250 - frac->speed - 10 && frac->r == 0)
//			red += frac->speed;
//		else if (green <= 250 - frac->speed - 10 && frac->g == 0)
//			green += frac->speed;
//		else if (blue <= 250 - frac->speed - 10 && frac->b == 0)
//			blue += frac->speed;
//		else if (blue >= 250 - frac->speed - 10 || frac->b == 1) {
//			frac->b = 1;
//			if (blue <= frac->speed + 10) {
//				frac->b = 2;
//				frac->g = 0;
//			}
//			blue -= frac->speed;
//		} else if (green >= 250 - frac->speed - 10 || frac->g == 1) {
//			frac->g = 1;
//			if (green <= frac->speed + 10) {
//				frac->g = 2;
//				frac->r = 0;
//			}
//			green -= frac->speed;
//		} else if (red >= 250 - frac->speed - 10 || frac->r == 1) {
//			frac->r = 1;
//			if (red <= frac->speed + 1) {
//				frac->r = 2;
//				frac->b = 0;
//			}
//			red -= frac->speed;
//		}
//	}
//	frac->color = (red << 16) | (green << 8) | blue;
	mlx_clear_window(frac->mlx_ptr, frac->win_ptr);
	if (frac->numfrac == 1)
		mandelbrot(frac);
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
