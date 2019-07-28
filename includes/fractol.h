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
# define FILENAME "src/fractol.cl"

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <OpenCL/OpenCL.h>

typedef	struct 		s_image
{
	void		*img_ptr;
	int 		*img_data;
	int 		bpp;
	int 		sizeline;
	int 		endian;
}					t_image;

typedef	struct		s_cl
{
	int					ret;
	size_t				source_size;
	char				*source_str;
	struct stat			stats;
	size_t				global_work_size[1];
	cl_platform_id		platform_id;
	cl_uint				ret_num_platforms;
	cl_device_id		device_id;
	cl_uint				ret_num_devices;
	cl_context			context;
	cl_command_queue	command_queue;
	cl_program			program;
	cl_kernel			mandelbrot;
	cl_kernel			julia;
	cl_kernel			ship;
	cl_kernel			mandelbrot_x;
	cl_mem				img_data;
	cl_mem				zoom;
	cl_mem				movey;
	cl_mem				movex;
	cl_mem				iterations;
	cl_mem				choise;
	cl_mem				color;
}					t_cl;

typedef	struct		s_fractol
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_cl		*cl;
	t_image		*image;
	int 		color;
	int 		numfrac;
	int 		iterations;
	int 		p;//Степень в формуле
	double		zoom;
	double		movex;
	double		movey;
	double		x0;//move julia
	double		y0;//move julia
	int			move;//движения джулии
	int			w;//Переливание цвета
	int			choise;//Переключение цвета
	int 		r;
	int 		g;
	int			b;
}					t_fractol;

int					ft_check_input(int ac, char **av, t_fractol *frac);
void				ft_init_win(t_fractol *frac);
void				mandelbrot(t_fractol *frac);
double				ft_pow_comp(double x, double y, int n, double *v);
void				ft_key_hook(t_fractol *frac);
void				julia(t_fractol *frac);
void				ship(t_fractol *frac);
void				mandelbrot_x(t_fractol *frac);
void				ft_init_cl(t_fractol *frac);
void				ft_change_params(t_fractol *frac);

#endif
