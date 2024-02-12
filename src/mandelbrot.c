/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:03 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/12 23:01:10 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_mandelbrot(t_pixel px, t_fractal *fractal)
{
	t_complex	point;
	t_complex	z;
	int			i;
	double		r_square;
	double		i_square;

	point = rescale_pixel(px, fractal);
	z.real = 0;
	z.imaginary = 0;
	i = 0;
	r_square = 0;
	i_square = 0;
	while (i < fractal->max_iterations)
	{
		z.imaginary = (2 * z.real * z.imaginary) + point.imaginary;
		z.real = r_square - i_square + point.real;
		r_square = z.real * z.real;
		i_square = z.imaginary * z.imaginary;
		if (r_square + i_square > MAX)
			return (get_color(i, fractal));
		i++;
	}
	return (BLACK);
}
