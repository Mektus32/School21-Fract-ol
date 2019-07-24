/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 17:00:28 by ojessi            #+#    #+#             */
/*   Updated: 2019/07/19 19:18:32 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "fractol.h"
#include <stdio.h>
#include <math.h>

double	ft_calc_fi(double cosx, double siny);
double	ft_pow_comp(double x, double y, int n, double *v);

/*int 	main(void)
{
	int		A;
	int		B;
	int		i;
	double	a, b, x, y, t, n = 15;
	printf("Mandelbrot Set\n");
	for (B = 0; B <= 4 * n; B++)
	{
		b = 2 - (B / n);
		for (A = 0; A <= 4 * n; A++)
		{
			a = -2 + (A / n);
			x = 0;
			y = 0;
			for (i = 1; i <= 100; i++)
			{
				t = x;
				x = (x * x) - (y * y) + a;
				y = (2 * t * y) + b;
				if ((x * x) + (y * y) > 4)
				{
					if (i >= 0 && i <= 1)
						printf("%d", i - 1);
					else
						printf("%d", i);
					break;
				}
			}
			if (i == 101)
				printf(".");
			else
				printf(" ");
		}
		printf("\n");
	}
	return (0);
}*/

// int		main(void)
// {
// 	int		i, n = 100, w = 101, h = 101, m = 30, p = 2;
// 	double	x0, y0, t, a, b, d;
	
	
// 	for (int y = 0; y < h; y++)//Проход по всем значениям Y
// 	{
// 		b = (- y + (h / 2.)) / (double)m;
// 		for (int x = 0; x < w; x++)//Проход по всем значениям X
// 		{
// 			a = (x - (w / 2.)) / (double)m;
// 			i = 0;//Обнуляем количество итерация для kаждой точи
// 			x0 = 0;//Ставим начальные значения для точки
// 			y0 = 0;		
// 			//printf("y = [%.20f] x = [%.20f]\n", b, a);		
// 			while (i < n)
// 			{
// 				d = y0;
// 				t = x0;//Запоминаем значения для того чтобы потом правильно посчитать Y0
// 				x0 = fabs(ft_pow_comp(t, d, p, &y0) + a);//Считаем X0n+1
// 				y0 = fabs(y0 + b);//Считаем Y0n+1
// 				// x0 = (x0 * x0 * x0) - (3 * x0 * y0 * y0) + a;
// 				// y0 = (3 * x0 * x0 * y0) - (y0 * y0 * y0) + b;
// 			//	printf("x0 = [%f] y0 = [%f]\n", x0, y0);
// 				//return (0);
// 				if ((x0 * x0) + (y0 * y0) > 4)//Сравниваем модуль числа
// 				{
// 					printf("%d", i);
// 					break;//Перестаем считать итерации для точи, которая вышла за пределы 2
// 				}
// 				i++;//Увеличиваем итерации в цикле
// 			}
// 			if (i == n)
// 				printf(".");//Иначе печатаем 0
// 		}
// 		printf("\n");//Делаем перенос строки
// 	}
// 	return (0);
// }

double	ft_calc_fi(double cosx, double siny)
{
	double	acosx;
	double	asiny;

	//printf("cosx = [%f] siny = [%f]\n", cosx, siny);
	acosx = acos(cosx);
	asiny = asin(siny);
	//printf("acos = [%f] asiny = [%f]\n", acosx, asiny);
	if (cosx >= 0 && siny >= 0)
		return (acosx);
	else if (cosx >= 0 && siny < 0)
		return (asiny);
	else if (cosx < 0 && siny >= 0)
		return (acosx);
	else //acosx < 0 && asiny < 0
	{
	//	printf("M_PI - asiny = [%f]\n", M_PI - asiny);
		return (M_PI - asiny);
	}
	return (0);
}

double	ft_pow_comp(double x, double y, int n, double *v)
{
	double	fi;
	const double r = sqrt((x * x) + (y * y));

	if (r == 0)
		return (0);
//	printf("r = [%f]\n", r);
	fi = ft_calc_fi(x / r, y / r);
//	printf("fi = [%f]\n", fi);
//	printf("r ^ 2 = [%f]\n", pow(r, n));
	*v = pow(r, n) * sin(n * fi);
	return (pow(r, n) * cos(n * fi));
}
// 89046550804 Татьяна Владимировна
int		main(void)
{
	int		i;
	double x = 0, y = 0, t, x0, y0;
	//double u = 0, v = 0, n = 2, x = 1, y = 1;

	i = 0;
	x0 = 1 / 10.;
	y0 = -1 / 10.;
	while (i < 20)
	{
		t = x;
		x = fabs((x * x) - (y * y) + x0);
		y = fabs((2 * t * y) + y0);
		printf("i = [%2d] x =[%.20f] y =[%.20f]\n", i, x, y);
		i++;
	}
	// return (0);
	//printf("double = %d, long double = %d", sizeof(double), sizeof(long double));
	//printf("arccos = [%.10f] arcsin = [%.10f]\n", acos(0), asin(0));
	//u = ft_pow_comp(x, y, n, &v);
	//printf("u = [%f] v = [%f]\n", u, v);
	return (0);
}

