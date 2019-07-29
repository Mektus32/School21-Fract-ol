/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_and_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 20:35:32 by ojessi            #+#    #+#             */
/*   Updated: 2019/07/29 20:35:33 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_next_choise_frac(t_fractol *frac)
{
	if (frac->numfrac == 3)
	{
		ft_set_kernel_ship(frac->cl);
		frac->cl->ret = clEnqueueNDRangeKernel(frac->cl->command_queue,
		frac->cl->ship, 1, NULL, frac->cl->global_work_size, NULL, 0,
		NULL, NULL);
	}
	else if (frac->numfrac == 4)
	{
		ft_set_kernel_mandelbrot_x(frac->cl);
		frac->cl->ret = clEnqueueNDRangeKernel(frac->cl->command_queue,
		frac->cl->mandelbrot_x, 1, NULL, frac->cl->global_work_size, NULL, 0,
		NULL, NULL);
	}
}

void	ft_next_create_kernels(t_cl *cl)
{
	cl->choise = clCreateBuffer(cl->context, CL_MEM_READ_WRITE, sizeof(cl_int),
	NULL, &cl->ret);
	cl->color = clCreateBuffer(cl->context, CL_MEM_READ_WRITE, sizeof(cl_int),
	NULL, &cl->ret);
	cl->fracx0 = clCreateBuffer(cl->context, CL_MEM_READ_WRITE,
	sizeof(cl_double),
	NULL, &cl->ret);
	cl->fracy0 = clCreateBuffer(cl->context, CL_MEM_READ_WRITE,
	sizeof(cl_double),
	NULL, &cl->ret);
	cl->p = clCreateBuffer(cl->context, CL_MEM_READ_WRITE, sizeof(cl_int),
	NULL, &cl->ret);
}

void	ft_next_keyboard(int key, t_fractol *frac)
{
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
}

void	ft_next_next_keyboard(int key, t_fractol *frac)
{
	if (key == 53)
		exit(0);
	if (key == 24)
		frac->iterations++;
	else if (key == 27 && frac->iterations > 10)
		frac->iterations--;
}
