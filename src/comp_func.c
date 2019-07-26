/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 15:13:06 by ojessi            #+#    #+#             */
/*   Updated: 2019/07/26 15:13:07 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		ft_calc_fi(double cosx, double siny)
{
	double	acosx;
	double	asiny;

	acosx = acos(cosx);
	asiny = asin(siny);
	if (cosx >= 0 && siny >= 0)
		return (acosx);
	else if (cosx >= 0 && siny < 0)
		return (asiny);
	else if (cosx < 0 && siny >= 0)
		return (acosx);
	else
		return (M_PI - asiny);
	return (0);
}

double	ft_pow_comp(double x, double y, int n, double *v)
{
	double			fi;
	const double	r = sqrt((x * x) + (y * y));

	if (r == 0)
		return (0);
	fi = ft_calc_fi(x / r, y / r);
	*v = pow(r, n) * sin(n * fi);
	return (pow(r, n) * cos(n * fi));
}
