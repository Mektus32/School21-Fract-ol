/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 19:11:48 by ojessi            #+#    #+#             */
/*   Updated: 2019/07/28 19:11:49 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_set_kernel_mandelbrot(t_cl *cl)
{
	cl->ret = clSetKernelArg(cl->mandelbrot, 0, sizeof(cl_mem),
			(void*)&cl->img_data);
}

void	ft_change_params(t_fractol *frac)
{
	frac->cl->ret = clEnqueueWriteBuffer(frac->cl->command_queue,
	frac->cl->zoom, CL_TRUE, 0, sizeof(cl_double), &frac->zoom, 0, NULL, NULL);
	frac->cl->ret = clEnqueueWriteBuffer(frac->cl->command_queue,
	frac->cl->movey, CL_TRUE, 0, sizeof(cl_double), &frac->movey, 0, NULL,
	NULL);
	frac->cl->ret = clEnqueueWriteBuffer(frac->cl->command_queue,
	frac->cl->movex, CL_TRUE, 0, sizeof(cl_double), &frac->movex, 0, NULL,
	NULL);
	frac->cl->ret = clEnqueueWriteBuffer(frac->cl->command_queue,
	frac->cl->iterations, CL_TRUE, 0, sizeof(cl_int), &frac->iterations, 0,
	NULL, NULL);
	frac->cl->ret = clEnqueueWriteBuffer(frac->cl->command_queue,
	frac->cl->choise, CL_TRUE, 0, sizeof(cl_int), &frac->choise, 0, NULL, NULL);
	frac->cl->ret = clEnqueueWriteBuffer(frac->cl->command_queue,
	frac->cl->color, CL_TRUE, 0, sizeof(cl_int), &frac->color, 0, NULL, NULL);
}

void	ft_create_kernels(t_cl *cl)
{
	cl->mandelbrot = clCreateKernel(cl->program, "mandelbrot", &cl->ret);
	cl->julia = clCreateKernel(cl->program, "julia", &cl->ret);
	cl->ship = clCreateKernel(cl->program, "ship", &cl->ret);
	cl->mandelbrot_x = clCreateKernel(cl->program, "mandelbrot_x", &cl->ret);
	cl->img_data = clCreateBuffer(cl->context, CL_MEM_READ_WRITE, WIDTH * HEIGHT
	* sizeof(cl_int), NULL, &cl->ret);
	cl->zoom = clCreateBuffer(cl->context, CL_MEM_READ_WRITE, sizeof(cl_double),
	NULL, &cl->ret);
	cl->movey = clCreateBuffer(cl->context, CL_MEM_READ_WRITE,
	sizeof(cl_double), NULL, &cl->ret);
	cl->movex = clCreateBuffer(cl->context, CL_MEM_READ_WRITE,
	sizeof(cl_double), NULL, &cl->ret);
	cl->iterations = clCreateBuffer(cl->context, CL_MEM_READ_WRITE,
	sizeof(cl_int), NULL, &cl->ret);
	cl->choise = clCreateBuffer(cl->context, CL_MEM_READ_WRITE, sizeof(cl_int),
	NULL, &cl->ret);
	cl->color = clCreateBuffer(cl->context, CL_MEM_READ_WRITE, sizeof(cl_int),
	NULL, &cl->ret);
}

void	ft_get_cl(t_cl *cl)
{
	int		fd;

	cl->ret = clGetPlatformIDs(1, &cl->platform_id, &cl->ret_num_platforms);
	cl->ret = clGetDeviceIDs(cl->platform_id, CL_DEVICE_TYPE_GPU, 1,
			&cl->device_id, &cl->ret_num_devices);
	cl->context = clCreateContext(NULL, 1, &cl->device_id, NULL, NULL,
			&cl->ret);
	cl->command_queue = clCreateCommandQueue(cl->context, cl->device_id, 0,
			&cl->ret);
	if ((fd = open(FILENAME, O_RDONLY)) < 0)
	{
		write(1, "File Error\n", 11);
		exit(0);
	}
	lstat(FILENAME, &cl->stats);
	cl->source_size = cl->stats.st_size;
	cl->source_str = (char*)malloc(sizeof(char) * (cl->source_size + 1));
	cl->source_str[cl->source_size] = '\0';
	read(fd, cl->source_str, cl->source_size);
	close(fd);
	cl->program = clCreateProgramWithSource(cl->context, 1,
	(const char**)&cl->source_str, (const size_t*)&cl->source_size, &cl->ret);
	cl->ret = clBuildProgram(cl->program, 1, &cl->device_id, NULL, NULL, NULL);
}

void	ft_init_cl(t_fractol *frac)
{
	ft_get_cl(frac->cl);
	ft_create_kernels(frac->cl);
	ft_change_params(frac);
	ft_set_kernel_mandelbrot(frac->cl);
	printf("%d\n", frac->cl->ret);
}
