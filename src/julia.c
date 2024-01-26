/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:03 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/26 14:34:28 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int calculate_julia(t_pixel px, t_fractal *fractal)
{
	t_complex point;
	point = convert_pixel_into_complex(px, fractal);
	t_complex c;
	//c.real = 0.285;
	c.real = -0.8;
	//c.imaginary = 0.01;
	c.imaginary = 0.156;
	int max = 4;
	for (int i = 0; i < 200; i++)
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

