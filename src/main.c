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
		frac->win_ptr = mlx_new_window(frac->mlx_ptr, WIDTH, HEIGHT, "Mandelbrot");
	else if (frac->numfrac == 2)
		frac->win_ptr = mlx_new_window(frac->mlx_ptr, WIDTH, HEIGHT, "Julia");
	else if (frac->numfrac == 3)
		frac->win_ptr = mlx_new_window(frac->mlx_ptr, WIDTH, HEIGHT, "Ship");
	frac->color = 0xF1FF14;
	frac->image = ft_memalloc(sizeof(t_image));
	frac->image->bpp = 32;
	frac->image->endian = 0;
	frac->image->sizeline = WIDTH;
	frac->image->img_ptr = mlx_new_image(frac->mlx_ptr, WIDTH, HEIGHT);
	frac->cart = mlx_get_data_addr(frac->image->img_ptr,
	&frac->image->bpp, &frac->image->sizeline, &frac->image->endian);
	frac->iterations = 10;
	frac->p = 3;
	frac->zoom = 250;
	frac->iterations = 10;
	frac->movex = 0;
	frac->movey = 0;
	frac->x0 = 0;
	frac->y0 = 0;
	frac->move = 1;
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
	printf("numfrac->[%d]\n", frac->numfrac);
	ft_init_win(frac);
//	if (frac->numfrac == 1)
//		mandelbrot(frac);
//	for (int i = 0; i < HEIGHT * 4; i++)
//	{
//		for (int j = 0; j < WIDTH; j += 4)
//		{
//			frac->cart[i * WIDTH + j] += i;
//			frac->cart[i * WIDTH + j + 1] += 0;
//			frac->cart[i * WIDTH + j + 2] += i;
//		}
//	}
	mlx_put_image_to_window(frac->mlx_ptr, frac->win_ptr, frac->image->img_ptr, 0, 0);
	ft_key_hook(frac);
	mlx_loop(frac->mlx_ptr);
	return (0);
}
