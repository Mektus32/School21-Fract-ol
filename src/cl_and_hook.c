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