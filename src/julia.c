/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:03 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/19 11:10:02 by vafleith         ###   ########.fr       */
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

static char *format_julias_coord(char *x, char *y)
{
	char *real_part;
	char *imaginary_part;
	char *coord;

	real_part = ft_strjoin(x, " + ");
	if (real_part == NULL)
		return NULL;
	imaginary_part = ft_strjoin(y, "i");
	if (imaginary_part == NULL)
	{
		free(real_part);
		return NULL;
	}
	coord = ft_strjoin(real_part, imaginary_part);
	free(real_part);
	free(imaginary_part);
	return coord;
}

void display_julias_param(t_fractal *fractal)
{
	mlx_string_put(fractal->mlx, fractal->win, WIDTH - 140, HEIGHT - 70, BLACK, "Current julia point : ");
	char *julia_x;
	char *julia_y;
	char *coord;

	julia_x = ft_dtoa(fractal->current_point.real);
	if (julia_x == NULL)
		return;
	julia_y = ft_dtoa(fractal->current_point.imaginary);
	if (julia_y == NULL)
	{
		free(julia_x);
		return;
	}
	coord = format_julias_coord(julia_x, julia_y);
	if (coord == NULL)
	{
		free(julia_x);
		free(julia_y);
		return;
	}
	mlx_string_put(fractal->mlx, fractal->win, WIDTH - 140, HEIGHT - 40, BLACK, coord);
	free(julia_x);
	free(julia_y);
	free(coord);
}
