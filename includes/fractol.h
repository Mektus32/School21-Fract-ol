/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 17:02:15 by ojessi            #+#    #+#             */
/*   Updated: 2019/07/18 17:03:02 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 1200
# define HEIGHT 600

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>

typedef	struct 		s_image
{
	void		*img_ptr;
	int 		*img_data;
	int 		bpp;
	int 		sizeline;
	int 		endian;
}					t_image;

typedef	struct		s_fractol
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		*image;
	int 		color;
	int 		numfrac;
	int 		iterations;
	int 		p;//Степень в формуле
	double		zoom;
	double		movex;
	double		movey;
	double		x0;
	double		y0;
	int			move;
	char		*cart;
}					t_fractol;

int					ft_check_input(int ac, char **av, t_fractol *frac);
void				ft_init_win(t_fractol *frac);
void				mandelbrot(t_fractol *frac);
double				ft_pow_comp(double x, double y, int n, double *v);
void				ft_key_hook(t_fractol *frac);

#endif
