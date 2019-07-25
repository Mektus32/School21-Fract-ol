/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:19:30 by ojessi            #+#    #+#             */
/*   Updated: 2019/07/25 13:38:02 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(int ac, char **av)
{
	double	cRe, cIm;
	double	newRe, newIm, oldRe, oldIm;
	double	zoom = 0.7, moveX = 0.6, moveY = 0.6;
	int		maxIterations = 100, w = 100, h = 100;

	cRe = -0.7;
	cIm = 0.27015;

	for (int y = 0;  y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			newRe = 1.5 * (x - w / 2) / (0.5 * zoom * w) + moveX;
			newIm = (y - h / 2) / (0.5 * zoom * h) + moveY;
			int		i;
			for (i = 0; i < maxIterations; i++)
			{
				oldRe = newRe;
				oldIm = newIm;

				newRe = oldRe * oldRe - oldIm * oldIm + cRe;
				newIm = 2 * oldRe * oldIm + cIm;
				if ((newRe * newRe + newIm * newIm) > 4)
					break;
			}
			if (i == maxIterations)
				printf(" .");
			else
				printf("%2d", i % 10);
		}
		printf("\n");
	}
	return (0);
}
