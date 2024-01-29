/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:03 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/29 11:20:12 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int calculate_mandelbrot(t_pixel px, t_fractal *fractal)
{
	t_complex point;
	point = rescale_pixel(px, fractal);
	t_complex z;
	z.real = 0;
	z.imaginary = 0;
	int max = 4;
	for (int i = 0; i < MAX_ITERATIONS; i++)
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
