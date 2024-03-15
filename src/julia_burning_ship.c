/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_burning_ship.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:03 by vafleith          #+#    #+#             */
/*   Updated: 2024/03/16 00:06:12 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_julia_burning_ship(t_pixel px, t_fractal *fractal)
{
	t_complex	point;
	t_complex	c;
	int			i;
	double		r_square;
	double		i_square;

	point = rescale_pixel(px, fractal);
	c.real = fractal->current_point.real;
	c.imaginary = -fractal->current_point.imaginary;
	i = 0;
	r_square = point.real * point.real;
	i_square = point.imaginary * point.imaginary;
	while (i < fractal->max_iterations)
	{
		point.imaginary = fabs(2 * point.real * point.imaginary) + c.imaginary;
		point.real = r_square - i_square + c.real;
		r_square = point.real * point.real;
		i_square = point.imaginary * point.imaginary;
		if (r_square + i_square > MAX)
			return (get_color(i, fractal));
		i++;
	}
	return (BLACK);
}

