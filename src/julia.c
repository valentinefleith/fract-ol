/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:03 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/08 19:08:04 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int calculate_julia(t_pixel px, t_fractal *fractal)
{
	t_complex point;
	point = rescale_pixel(px, fractal);
	t_complex c;
	c.real = fractal->current_point.real;
	c.imaginary = fractal->current_point.imaginary;
	int max = 4;
	for (int i = 0; i < fractal->max_iterations; i++)
	{
		double tmp = point.real;
		point.real = (point.real * point.real) - (point.imaginary * point.imaginary) + c.real;
		point.imaginary = (2 * tmp * point.imaginary) + c.imaginary;
		if (point.real * point.real + point.imaginary * point.imaginary > max)
		{
			if (i)
				return fractal->colorset * i;
			return WHITE;
		}
	}
	return 0;
}

int change_julias_shape(t_fractal *fractal, int x, int y)
{
	t_pixel px;
	t_complex mouse_pos;

	px.x = x;
	px.y = y;
	mouse_pos = rescale_pixel(px, fractal);
	fractal->current_point.real = mouse_pos.real;
	fractal->current_point.imaginary = mouse_pos.imaginary;
	fractal_refresh(fractal);
	return (0);
}

