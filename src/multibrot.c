/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:03 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/27 21:50:05 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	calculate_multithree(t_pixel px, t_fractal *fractal)
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
		z.imaginary = (3 * r_square * z.imaginary - z.imaginary * z.imaginary
				* z.imaginary) + point.imaginary;
		z.real = r_square * z.real - 3 * z.real * i_square + point.real;
		r_square = z.real * z.real;
		i_square = z.imaginary * z.imaginary;
		if (r_square + i_square > MAX)
			return (get_color(i, fractal));
		i++;
	}
	return (BLACK);
}

static int	calculate_multifour(t_pixel px, t_fractal *fractal)
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
		z.imaginary = (4 * r_square * z.real * z.imaginary - 4 * z.real
				* z.imaginary * z.imaginary * z.imaginary) + point.imaginary;
		z.real = r_square * r_square - 6 * r_square * i_square + i_square
			* i_square + point.real;
		r_square = z.real * z.real;
		i_square = z.imaginary * z.imaginary;
		if (r_square + i_square > MAX)
			return (get_color(i, fractal));
		i++;
	}
	return (BLACK);
}

static int	calculate_multifive(t_pixel px, t_fractal *fractal)
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
	r_sq = 0;
	i_sq = 0;
	while (i < fractal->max_iterations)
	{
		z.imaginary = (5 * r_sq * r_sq * z.imaginary - 10 * r_sq * i_sq 
				* z.imaginary + i_sq * i_sq * z.imaginary) + point.imaginary;
		z.real = r_sq * r_sq * z.real - 10 * r_sq * i_sq * z.real + 5 
			* z.real * i_sq * i_sq + point.real;
		r_square = z.real * z.real;
		i_square = z.imaginary * z.imaginary;
		if (r_square + i_square > MAX)
			return (get_color(i, fractal));
		i++;
	}
	return (BLACK);
}

int	change_mandel(t_fractal *fractal)
{
	if (fractal->power == 5)
		fractal->power = 2;
	else
		fractal->power++;
	fractal_refresh(fractal);
	return (0);
}

int	calculate_multibrot(t_pixel px, t_fractal *fractal)
{
	if (fractal->power == 2)
		return (calculate_mandelbrot(px, fractal));
	if (fractal->power == 3)
		return (calculate_multithree(px, fractal));
	if (fractal->power == 4)
		return (calculate_multifour(px, fractal));
	if (fractal->power == 5)
		return (calculate_multifive(px, fractal));
	return (calculate_mandelbrot(px, fractal));
}
