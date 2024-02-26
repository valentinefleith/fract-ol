/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:03 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/26 23:50:23 by vafleith         ###   ########.fr       */
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
	c.imaginary = -fractal->current_point.imaginary;
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

static char	*format_julias_coord(char *x, char *y)
{
	char	*real_part;
	char	*imaginary_part;
	char	*coord;

	real_part = ft_strjoin(x, " + ");
	if (real_part == NULL)
		return (NULL);
	imaginary_part = ft_strjoin(y, "i");
	if (imaginary_part == NULL)
	{
		free(real_part);
		return (NULL);
	}
	coord = ft_strjoin(real_part, imaginary_part);
	free(real_part);
	free(imaginary_part);
	return (coord);
}

static void	display_coord_on_window(t_fractal *fractal, char *x, char *y)
{
	char	*coord;

	coord = format_julias_coord(x, y);
	if (coord == NULL)
		return ;
	mlx_string_put(fractal->mlx, fractal->win, WIDTH - 140, HEIGHT - 40, BLACK,
		coord);
	free(coord);
}

void	display_julias_param(t_fractal *fractal)
{
	char	*julia_x;
	char	*julia_y;

	mlx_string_put(fractal->mlx, fractal->win, WIDTH - 140, HEIGHT - 70, BLACK,
		"Current julia point : ");
	julia_x = ft_dtoa(fractal->current_point.real);
	if (julia_x == NULL)
		return ;
	julia_y = ft_dtoa(fractal->current_point.imaginary);
	if (julia_y == NULL)
	{
		free(julia_x);
		return ;
	}
	display_coord_on_window(fractal, julia_x, julia_y);
	free(julia_x);
	free(julia_y);
}
