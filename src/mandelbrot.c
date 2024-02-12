/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:03 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/12 14:22:04 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_mandelbrot(t_pixel px, t_fractal *fractal)
{
	t_complex	point;
	t_complex	z;
	int			i;
	double		tmp;

	point = rescale_pixel(px, fractal);
	z.real = 0;
	z.imaginary = 0;
	i = 0;
	while (i < fractal->max_iterations)
	{
		tmp = z.real;
		z.real = (z.real * z.real) - (z.imaginary * z.imaginary) + point.real;
		z.imaginary = (2 * tmp * z.imaginary) + point.imaginary;
		if (z.real * z.real + z.imaginary * z.imaginary > MAX)
		{
			if (i)
				return (fractal->colorset * i);
			return (WHITE);
		}
		i++;
	}
	return (0);
}
