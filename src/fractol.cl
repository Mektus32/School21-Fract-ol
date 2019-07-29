#define WIDTH 1200
#define HEIGHT 600

double		calc_fi(double cosx, double siny)
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

double	pow_comp(double x, double y, int n, double *v)
{
	double			fi;
	const double	r = sqrt((x * x) + (y * y));

	if (r == 0)
		return (0);
	fi = calc_fi(x / r, y / r);
	*v = pow(r, n) * sin(n * fi);
	return (pow(r, n) * cos(n * fi));
	return (0);
}

__kernel void mandelbrot(__global int *img_data, __global double *zoom,
		__global double *movey, __global double *movex, __global int *iterations,
		__global int *choise, __global int *color)
{
	int 	index = get_global_id(0);
	double	b = -1.25 + ((index / WIDTH) / *zoom + *movey);
	double	a = -(2.5 - ((index % WIDTH) / *zoom + *movex));
	int		i = -1;
	double	x0 = 0.0;
	double	y0 = 0.0;
	double	t;

	while (++i < *iterations)
	{
		t = x0;
		x0 = x0 * x0 - y0 * y0 + a;
		y0 = (2 * t * y0) + b;
		if (x0 * x0 + y0 * y0 > 4)
			break;
	}
	if (i == *iterations)
		img_data[index] = 0x000000;
	else
	{
		if (*choise == 1)
			img_data[index] = 0xFFFFFF;
		else if (*choise == 2)
		{
			if (i % 3 == 2)
				img_data[index] = 0xFF0000;
			else if (i % 3 == 1)
				img_data[index] = 0x00FF00;
			else
				img_data[index] = 0x0000FF;
		}
		else
			img_data[index] = *color * i;
	}
}

__kernel void julia(__global int *img_data, __global double *zoom,
						 __global double *movey, __global double *movex, __global int *iterations,
						 __global int *choise, __global int *color, __global double *fracx0,
						 __global double *fracy0)
{
	int 	index = get_global_id(0);
	double	b = -1.25 + ((index / WIDTH) / *zoom + *movey);
	double	a = -(2.5 - ((index % WIDTH) / *zoom + *movex));
	int		i = -1;
	double	x0 = a;
	double	y0 = b;
	double	t;

	while (++i < *iterations)
	{
		t = x0;
		x0 = x0 * x0 - y0 * y0 + *fracx0 / WIDTH;
		y0 = (2 * t * y0) + *fracy0 / HEIGHT;
		if (x0 * x0 + y0 * y0 > 4)
			break;
	}
	if (i == *iterations)
		img_data[index] = 0x000000;
	else
	{
		if (*choise == 1)
			img_data[index] = 0xFFFFFF;
		else if (*choise == 2)
		{
			if (i % 3 == 2)
				img_data[index] = 0xFF0000;
			else if (i % 3 == 1)
				img_data[index] = 0x00FF00;
			else
				img_data[index] = 0x0000FF;
		}
		else
			img_data[index] = *color * i;
	}
}

__kernel void ship(__global int *img_data, __global double *zoom,
						 __global double *movey, __global double *movex, __global int *iterations,
						 __global int *choise, __global int *color)
{
	int 	index = get_global_id(0);
	double	b = -1.25 + ((index / WIDTH) / *zoom + *movey);
	double	a = -(2.5 - ((index % WIDTH) / *zoom + *movex));
	int		i = -1;
	double	x0 = 0.0;
	double	y0 = 0.0;
	double	t;

	while (++i < *iterations)
	{
		t = x0;
		x0 = fabs(x0 * x0 - y0 * y0 + a);
		y0 = fabs((2 * t * y0) + b);
		if (x0 * x0 + y0 * y0 > 4)
			break;
	}
	if (i == *iterations)
		img_data[index] = 0x000000;
	else
	{
		if (*choise == 1)
			img_data[index] = 0xFFFFFF;
		else if (*choise == 2)
		{
			if (i % 3 == 2)
				img_data[index] = 0xFF0000;
			else if (i % 3 == 1)
				img_data[index] = 0x00FF00;
			else
				img_data[index] = 0x0000FF;
		}
		else
			img_data[index] = *color * i;
	}
}

__kernel void mandelbrot_x(__global int *img_data, __global double *zoom,
						 __global double *movey, __global double *movex, __global int *iterations,
						 __global int *choise, __global int *color, __global int *p)
{
	int 	index = get_global_id(0);
	double	b = -1.25 + ((index / WIDTH) / *zoom + *movey);
	double	a = -(2.5 - ((index % WIDTH) / *zoom + *movex));
	int		i = -1;
	double	x0 = 0.0;
	double	y0 = 0.0;

	while (++i < *iterations)
	{
		x0 = pow_comp(x0, y0, *p, &y0) + a;
		y0 += b;
		if (x0 * x0 + y0 * y0 > 4)
			break;
	}
	if (i == *iterations)
		img_data[index] = 0x000000;
	else
	{
		if (*choise == 1)
			img_data[index] = 0xFFFFFF;
		else if (*choise == 2)
		{
			if (i % 3 == 2)
				img_data[index] = 0xFF0000;
			else if (i % 3 == 1)
				img_data[index] = 0x00FF00;
			else
				img_data[index] = 0x0000FF;
		}
		else
			img_data[index] = *color * i;
	}
}