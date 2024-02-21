/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:31:18 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/21 15:33:37 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_string_centered(t_fractal *fractal, int *y, char *str)
{
	int	x;

	x = (WIDTH - ft_strlen(str) * 6) / 2;
	mlx_string_put(fractal->mlx, fractal->win, x, *y, WHITE, str);
	*y += LINE_LENGTH;
}

t_complex	rescale_pixel(t_pixel px, t_fractal *fractal)
{
	t_complex	point;

	point.real = (px.x * (fractal->xmax - fractal->xmin) / WIDTH)
		+ fractal->xmin;
	point.real = point.real * fractal->zoom + fractal->shiftx;
	point.imaginary = (px.y * (fractal->ymax - fractal->ymin) / HEIGHT)
		+ fractal->ymin;
	if (fractal->set == 2 || fractal->set == 1) // maybe only 2 ?
		point.imaginary = point.imaginary * fractal->zoom + fractal->shifty;
	else
		point.imaginary = -point.imaginary * fractal->zoom + fractal->shifty;
	return (point);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
