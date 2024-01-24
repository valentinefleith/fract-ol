/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:03 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/24 15:25:58 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int calculate_mandelbrot(t_pixel px, t_fractal *fractal)
{
	t_complex point;
	point = convert_pixel_into_complex(px, fractal);
	//point.real = (((px.x + fractal->xmin)/ ZOOM - 3 * fractal->xmax - 0.2)) * fractal->zoom + (fractal->shiftx );
	//point.real = ((px.x + x1)/ zoom - 3 * x2 - 1.5) * 0.1;
	//point.real = (x / zoom + x1);
	//point.imaginary = (((px.y + fractal->ymin) / ZOOM - fractal->ymax)) * fractal -> zoom + (fractal->shifty);
	//point.imaginary = ((px.y + y1) / zoom - y2 - 7) * 0.1;
	t_complex z;
	z.real = 0;
	z.imaginary = 0;
	int max = 4;
	for (int i = 0; i < 200; i++)
	{
		double tmp = z.real;
		z.real = (z.real * z.real) - (z.imaginary * z.imaginary) + point.real;
		z.imaginary = (2 * tmp * z.imaginary) + point.imaginary;
		if (z.real * z.real + z.imaginary * z.imaginary > max)
		{
			if (i)
				return fractal->colorset * i;
			return WHITE;
		}
	}
	return 0;
}

t_complex convert_pixel_into_complex(t_pixel px, t_fractal *fractal)
{
	t_complex point;

	point.real = (((px.x + fractal->xmin)/ ZOOM - 3 * fractal->xmax - 0.2)) * fractal->zoom + (fractal->shiftx );
	point.imaginary = (((px.y + fractal->ymin) / ZOOM - fractal->ymax)) * fractal -> zoom + (fractal->shifty);
	return point;
}
