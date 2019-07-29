/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:09:23 by ojessi            #+#    #+#             */
/*   Updated: 2019/07/29 21:09:26 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_blue(int *blue, t_fractol *frac)
{
	frac->b = 1;
	if (*blue <= 10)
	{
		frac->b = 2;
		frac->g = 0;
	}
	*blue -= 1;
}

void	ft_green(int *green, t_fractol *frac)
{
	frac->g = 1;
	if (*green <= 10)
	{
		frac->g = 2;
		frac->r = 0;
	}
	*green -= 1;
}

void	ft_red(int *red, t_fractol *frac)
{
	frac->r = 1;
	if (*red <= 10)
	{
		frac->r = 2;
		frac->b = 0;
	}
	*red -= 1;
}

void	ft_end_color(int red, int green, int blue, t_fractol *frac)
{
	frac->color = (red << 16) | (green << 8) | blue;
	mlx_clear_window(frac->mlx_ptr, frac->win_ptr);
	ft_choise_frac(frac);
}

int		color(t_fractol *frac)
{
	int		red;
	int		green;
	int		blue;

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
			ft_blue(&blue, frac);
		else if (green >= 250 || frac->g == 1)
			ft_green(&green, frac);
		else if (red >= 250 || frac->r == 1)
			ft_red(&red, frac);
	}
	ft_end_color(red, green, blue, frac);
	return (0);
}
