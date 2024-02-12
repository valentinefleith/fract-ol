/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:03 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/12 22:42:12 by vafleith         ###   ########.fr       */
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
    double r_square = 0;
    double i_square = 0;
	while (i < fractal->max_iterations)
	{
		z.imaginary = fabs(2 * z.real * z.imaginary) + point.imaginary;
		z.real = r_square - i_square + point.real;
        r_square = z.real * z.real;
        i_square = z.imaginary * z.imaginary;
		if (r_square + i_square > MAX)
			return get_color(i, fractal);
		i++;
	}
	return BLACK;
}
