/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:03 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/12 19:30:03 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int calculate_burning_ship(t_pixel px, t_fractal *fractal)
{
	t_complex point;
	point = rescale_pixel(px, fractal);
	t_complex z;
	int i;
	z.real = 0;
	z.imaginary = 0;
	i = 0;
	while (i < fractal->max_iterations)
	{
		double tmp = z.real;
		z.real = (z.real * z.real) - (z.imaginary * z.imaginary) + point.real;
		z.imaginary = fabs(2 * tmp * z.imaginary) + point.imaginary;
		if (z.real * z.real + z.imaginary * z.imaginary > MAX)
			return get_color(i, fractal);
		i++;
	}
	return BLACK;
}
