/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:42:35 by ojessi            #+#    #+#             */
/*   Updated: 2019/07/29 16:42:36 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_set_kernel_mandelbrot(t_cl *cl)
{
	cl->ret = clSetKernelArg(cl->mandelbrot, 0, sizeof(cl_mem),
	(void*)&cl->img_data);
	cl->ret = clSetKernelArg(cl->mandelbrot, 1, sizeof(cl_mem),
	(void*)&cl->zoom);
	cl->ret = clSetKernelArg(cl->mandelbrot, 2, sizeof(cl_mem),
	(void*)&cl->movey);
	cl->ret = clSetKernelArg(cl->mandelbrot, 3, sizeof(cl_mem),
	(void*)&cl->movex);
	cl->ret = clSetKernelArg(cl->mandelbrot, 4, sizeof(cl_mem),
	(void*)&cl->iterations);
	cl->ret = clSetKernelArg(cl->mandelbrot, 5, sizeof(cl_mem),
	(void*)&cl->choise);
	cl->ret = clSetKernelArg(cl->mandelbrot, 6, sizeof(cl_mem),
	(void*)&cl->color);
}

void	ft_set_kernel_julia(t_cl *cl)
{
	cl->ret = clSetKernelArg(cl->julia, 0, sizeof(cl_mem),
	(void*)&cl->img_data);
	cl->ret = clSetKernelArg(cl->julia, 1, sizeof(cl_mem),
	(void*)&cl->zoom);
	cl->ret = clSetKernelArg(cl->julia, 2, sizeof(cl_mem),
	(void*)&cl->movey);
	cl->ret = clSetKernelArg(cl->julia, 3, sizeof(cl_mem),
	(void*)&cl->movex);
	cl->ret = clSetKernelArg(cl->julia, 4, sizeof(cl_mem),
	(void*)&cl->iterations);
	cl->ret = clSetKernelArg(cl->julia, 5, sizeof(cl_mem),
	(void*)&cl->choise);
	cl->ret = clSetKernelArg(cl->julia, 6, sizeof(cl_mem),
	(void*)&cl->color);
	cl->ret = clSetKernelArg(cl->julia, 7, sizeof(cl_mem),
	(void*)&cl->fracx0);
	cl->ret = clSetKernelArg(cl->julia, 8, sizeof(cl_mem),
	(void*)&cl->fracy0);
}

void	ft_set_kernel_ship(t_cl *cl)
{
	cl->ret = clSetKernelArg(cl->ship, 0, sizeof(cl_mem),
	(void*)&cl->img_data);
	cl->ret = clSetKernelArg(cl->ship, 1, sizeof(cl_mem),
	(void*)&cl->zoom);
	cl->ret = clSetKernelArg(cl->ship, 2, sizeof(cl_mem),
	(void*)&cl->movey);
	cl->ret = clSetKernelArg(cl->ship, 3, sizeof(cl_mem),
	(void*)&cl->movex);
	cl->ret = clSetKernelArg(cl->ship, 4, sizeof(cl_mem),
	(void*)&cl->iterations);
	cl->ret = clSetKernelArg(cl->ship, 5, sizeof(cl_mem),
	(void*)&cl->choise);
	cl->ret = clSetKernelArg(cl->ship, 6, sizeof(cl_mem),
	(void*)&cl->color);
}

void	ft_set_kernel_mandelbrot_x(t_cl *cl)
{
	cl->ret = clSetKernelArg(cl->mandelbrot_x, 0, sizeof(cl_mem),
	(void*)&cl->img_data);
	cl->ret = clSetKernelArg(cl->mandelbrot_x, 1, sizeof(cl_mem),
	(void*)&cl->zoom);
	cl->ret = clSetKernelArg(cl->mandelbrot_x, 2, sizeof(cl_mem),
	(void*)&cl->movey);
	cl->ret = clSetKernelArg(cl->mandelbrot_x, 3, sizeof(cl_mem),
	(void*)&cl->movex);
	cl->ret = clSetKernelArg(cl->mandelbrot_x, 4, sizeof(cl_mem),
	(void*)&cl->iterations);
	cl->ret = clSetKernelArg(cl->mandelbrot_x, 5, sizeof(cl_mem),
	(void*)&cl->choise);
	cl->ret = clSetKernelArg(cl->mandelbrot_x, 6, sizeof(cl_mem),
	(void*)&cl->color);
	cl->ret = clSetKernelArg(cl->mandelbrot_x, 7, sizeof(cl_mem),
	(void*)&cl->p);
}
