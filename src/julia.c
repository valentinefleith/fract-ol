/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:03 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/13 00:14:11 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_julia(t_pixel px, t_fractal *fractal)
{
	t_complex	point;
	t_complex	c;
	int			i;
	double		r_square;
	double		i_square;

	point = rescale_pixel(px, fractal);
	c.real = fractal->current_point.real;
	c.imaginary = fractal->current_point.imaginary;
	i = 0;
	r_square = point.real * point.real;
	i_square = point.imaginary * point.imaginary;
	while (i < fractal->max_iterations)
	{
		point.imaginary = 2 * point.real * point.imaginary + c.imaginary;
		point.real = r_square - i_square + c.real;
		r_square = point.real * point.real;
		i_square = point.imaginary * point.imaginary;
		if (r_square + i_square > MAX)
			return (get_color(i, fractal));
		i++;
	}
	return (BLACK);
}

int	change_julias_shape(int x, int y, t_fractal *fractal)
{
	t_pixel		px;
	t_complex	mouse_pos;

	px.x = x;
	px.y = y;
	mouse_pos = rescale_pixel(px, fractal);
	fractal->current_point.real = mouse_pos.real;
	fractal->current_point.imaginary = mouse_pos.imaginary;
	fractal_refresh(fractal);
	return (0);
}
