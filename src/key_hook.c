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
	if (frac->numfrac == 2 && frac->move == 1)
	{
		frac->x0 = x / 1.2;
		frac->y0 = y / 1.2;
	}
	color(frac);
	return (0);
}

int 	keyboard(int key, t_fractol *frac)
{
	static	int 	i;
	if (key == 53)
		exit(0);
	if (key == 24)
		frac->iterations++;
	else if (key == 27 && frac->iterations > 10)
		frac->iterations--;
	if (frac->numfrac == 4)
	{
		key == 69 ? frac->p++ : 0;
		key == 78 ? frac->p-- : 0;
	}
	if (key == 18)
	{
		frac->numfrac = 1;
		ft_init_win(frac);
	}
	else if (key == 19)
	{
		frac->numfrac = 2;
		ft_init_win(frac);
	}
	else if (key == 20)
	{
		frac->numfrac = 3;
		ft_init_win(frac);
	}
	else if (key == 21)
	{
		frac->numfrac = 4;
		ft_init_win(frac);
	}
	key == 13 ? frac->w	= (frac->w + 1) % 2 : 0;
	key == 83 ? frac->choise = 1: 0;
	key == 84 ? frac->choise = 2: 0;
	key == 85 ? frac->choise = 0: 0;
	if (key == 8)
	{
		i++;
		i == 1 ? frac->color = 0x9914FF : 0;
		i == 2 ? frac->color = 0xFF5105 : 0;
		i == 3 ? frac->color = 0x0596FF : 0;
		if (i == 3)
			i = 0;
	}
	key == 126 ? frac->movey -= 5 / frac->zoom : 0;
	key == 125 ? frac->movey += 5 / frac->zoom : 0;
	key == 123 ? frac->movex += 5 / frac->zoom : 0;
	key == 124 ? frac->movex -= 5 / frac->zoom : 0;
	color(frac);
	return (0);
}

int 	color(t_fractol *frac)
{
	int 	red;
	int 	green;
	int 	blue;

	red = (frac->color >> 16) & 0xFF;
	green = (frac->color >> 8) & 0xFF;
	blue = frac->color & 0xFF;
	if (frac->w == 1)
	{
		if (red <= 250 && frac->r == 0)
			red += 1;
		else if (green <= 250 && frac->g == 0)
			green += 1;
		else if (blue <= 250 && frac->b == 0)
			blue += 1;
		else if (blue >= 250 || frac->b == 1)
		{
			frac->b = 1;
			if (blue <= 10)
			{
				frac->b = 2;
				frac->g = 0;
			}
			blue -= 1;
		} else if (green >= 250 || frac->g == 1)
		{
			frac->g = 1;
			if (green <= 10) {
				frac->g = 2;
				frac->r = 0;
			}
			green -= 1;
		} else if (red >= 250 || frac->r == 1)
		{
			frac->r = 1;
			if (red <= 10)
			{
				frac->r = 2;
				frac->b = 0;
			}
			red -= 1;
		}
	}
	frac->color = (red << 16) | (green << 8) | blue;
	mlx_clear_window(frac->mlx_ptr, frac->win_ptr);
	if (frac->numfrac == 1)
		mandelbrot(frac);
	else if (frac->numfrac == 2)
		julia(frac);
	else if (frac->numfrac == 3)
		ship(frac);
	else if (frac->numfrac == 4)
		mandelbrot_x(frac);
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
