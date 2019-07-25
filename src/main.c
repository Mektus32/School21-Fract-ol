/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:43:03 by ojessi            #+#    #+#             */
/*   Updated: 2019/07/25 13:43:08 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int 	ft_check_input(int ac, char **av, t_fractol *frac)
{
	int 	i;

	i = 1;
	while (i < ac)
	{
		if (!ft_strcmp("Mandelbrot", av[i]))
			return (1);
		if (!ft_strcmp("Julia", av[i]))
			return (2);
		if (!ft_strcmp("Ship", av[i]))
			return (3);
		i++;
	}
	write(1, "./fractol [Mandelbrot, Julia, Ship]\n", 36);
	free(frac);
	exit(0);
}

void	ft_init_win(t_fractol *frac)
{
	frac->mlx_ptr = mlx_init();
	if (frac->numfrac == 1)
		mlx_new_window(frac->win_ptr, WIDTH, HEIGHT, "Mandelbrot");
	else if (frac->numfrac == 2)
		mlx_new_window(frac->win_ptr, WIDTH, HEIGHT, "Julia");
	else if (frac->numfrac == 3);
		mlx_new_window(frac->win_ptr, WIDTH, HEIGHT, "Ship");
	frac->color = 0xF1FF14;
	frac->image = ft_memalloc(sizeof(t_image));
	frac->image->bpp = 32;
	frac->image->endian = 0;
	frac->image->sizeline = WIDTH * 4;
	frac->image->img_ptr = mlx_new_image(frac->mlx_ptr, WIDTH, HEIGHT);
	frac->image->img_data = mlx_get_data_addr(frac->image->img_ptr,
	&frac->image->bpp, &frac->image->sizeline, &frac->image->endian);
	frac->iterations = 10;
	frac->p = 2;
	frac->zoom = 10;
}

int 	main(int ac, char **av)
{
	t_fractol	*frac;

	if (ac != 2)
	{
		write(1, "./fractol Mandelbrot, Julia, Ship]\n", 35);
		return (0);
	}
	frac = ft_memalloc(sizeof(t_fractol));
	frac->numfrac = ft_check_input(ac, av, frac);
	ft_init_win(frac);
	printf("frac->numfrac = [%d]\n", frac->numfrac);
	return (0);
}
