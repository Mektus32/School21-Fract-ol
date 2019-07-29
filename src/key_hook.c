/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 15:52:08 by ojessi            #+#    #+#             */
/*   Updated: 2019/07/29 21:03:39 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose(t_fractol *frac)
{
	(void)frac;
	exit(0);
	return (0);
}

int		mouse(int button, int x, int y, t_fractol *frac)
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
	if (button == 1 && frac->numfrac == 2)
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

int		keyboard(int key, t_fractol *frac)
{
	static int i;

	ft_next_keyboard(key, frac);
	ft_next_next_keyboard(key, frac);
	key == 13 ? frac->w = (frac->w + 1) % 2 : 0;
	key == 83 ? frac->choise = 1 : 0;
	key == 84 ? frac->choise = 2 : 0;
	key == 85 ? frac->choise = 0 : 0;
	if (key == 8)
	{
		i++;
		i == 1 ? frac->color = 0xFF5105 : 0;
		i == 2 ? frac->color = 0x0596FF : 0;
		i == 3 ? frac->color = 0x7AFF05 : 0;
		i == 4 ? frac->color = 0x9914FF : 0;
		i == 4 ? i = 0 : 0;
	}
	key == 126 ? frac->movey -= 5 / frac->zoom : 0;
	key == 125 ? frac->movey += 5 / frac->zoom : 0;
	key == 123 ? frac->movex += 5 / frac->zoom : 0;
	key == 124 ? frac->movex -= 5 / frac->zoom : 0;
	color(frac);
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
