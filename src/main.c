/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 19:04:49 by ojessi            #+#    #+#             */
/*   Updated: 2019/07/28 19:04:51 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int 	ft_check_input(int ac, char **av, t_fractol *frac)
{
	if (!ft_strcmp("Mandelbrot", av[1]))
		return (1);
	else if (!ft_strcmp("Julia", av[1]))
		return (2);
	else if (!ft_strcmp("Ship", av[1]))
		return (3);
	else if (!ft_strcmp("Mandelbrot_X", av[1]))
		return (4);
	write(1, "./fractol [Mandelbrot, Julia, Ship, Mandelbrot_X]\n", 49);
	free(frac);
	exit(0);
}

void	ft_init_win(t_fractol *frac)
{
	!frac->mlx_ptr ? frac->mlx_ptr = mlx_init() : 0;
	!frac->win_ptr ? frac->win_ptr = mlx_new_window(frac->mlx_ptr,
			WIDTH, HEIGHT, "Fractol") : 0;
	!frac->cl ? frac->cl = ft_memalloc(sizeof(t_cl)) : 0;
	frac->color = 0x9914FF;
	!frac->image ? frac->image = ft_memalloc(sizeof(t_image)) : 0;
	frac->image->bpp = 32;
	frac->image->endian = 0;
	frac->image->sizeline = WIDTH;
	!frac->image->img_ptr ? frac->image->img_ptr = mlx_new_image(frac->mlx_ptr,
			WIDTH, HEIGHT) : 0;
	!frac->image->img_data ? frac->image->img_data = (int*)mlx_get_data_addr
	(frac->image->img_ptr, &frac->image->bpp, &frac->image->sizeline,
			&frac->image->endian) : 0;
	frac->iterations = 10;
	frac->p = 3;
	frac->zoom = 250;
	frac->iterations = 10;
	frac->move = 1;
	frac->choise = 0;
	frac->w = 0;
	frac->movey = 0;
	frac->movex = 0;
}

int		main(int ac, char **av)
{
	t_fractol	*frac;

	if (ac != 2)
	{
		write(1, "./fractol Mandelbrot, Julia, Ship, Mandelbrot_X]\n", 49);
		return (0);
	}
	frac = ft_memalloc(sizeof(t_fractol));
	frac->numfrac = ft_check_input(ac, av, frac);
	ft_init_win(frac);
	ft_init_cl(frac);
	return (0);
}
