/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 19:04:49 by ojessi            #+#    #+#             */
/*   Updated: 2019/07/29 20:32:36 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_print_menu(t_fractol *frac)
{
	char		*iter;
	char		*pow;

	iter = ft_free_join(ft_free_strjoin_rev("Iter[",
	ft_itoa(frac->iterations)), "]   -> '_' & '='");
	pow = ft_free_join(ft_free_strjoin_rev("Pow[",
	ft_itoa(frac->p)), "]    -> '-' & '+'");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 0, 0, frac->color, "Menu");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 0, 25, frac->color,
	"Fractol    -> [!,@,#,$]");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 0, 50, frac->color,
	"Color      -> 'c'");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 0, 75, frac->color, iter);
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 0, 100, frac->color,
	frac->w ? "Wave[On]  -> 'w'" : "Wave[Off]  -> 'w'");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 0, 125, frac->color,
	"Gamma      -> [1,2,3]");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 0, 150, frac->color, pow);
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 0, 175, frac->color,
	frac->move ? "Julia[move]-> LMB" : "Julia[stop]-> LMB");
	free(iter);
	free(pow);
}

int		ft_check_input(int ac, char **av, t_fractol *frac)
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
	!frac->image->img_data ? frac->image->img_data =
	(int*)mlx_get_data_addr(frac->image->img_ptr,
	&frac->image->bpp, &frac->image->sizeline, &frac->image->endian) : 0;
	frac->iterations = 10;
	frac->p = 2;
	frac->zoom = 150;
	frac->iterations = 50;
	frac->move = 0;
	frac->choise = 0;
	frac->w = 0;
	frac->movey = -0.70;
	frac->movex = -1;
	frac->x0 = 1.25;
	frac->y0 = 0.75;
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
	ft_key_hook(frac);
	mlx_loop(frac->mlx_ptr);
	return (0);
}
