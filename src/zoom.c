/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:04:57 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/08 13:14:04 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

//int zoom_in(t_fractal *fractal)
//{
//	fractal->zoom *= 0.95;
//	if (fractal->max_iterations < MAX_ITERATIONS)
//		fractal->max_iterations++;
//	fractal_refresh(fractal);
//	return 0;
//}

int zoom_out(t_fractal *fractal)
{
	fractal->zoom /= 0.85;
	fractal->max_iterations--;
	fractal_refresh(fractal);
	return 0;
}

int zoom_in(t_fractal *fractal, int x, int y)
{
	t_pixel px;
	t_complex mouse_pos_before_zoom;
	t_complex mouse_pos_after_zoom;

	px.x = x;
	px.y = y;
    mouse_pos_before_zoom = rescale_pixel(px, fractal);
	fractal->zoom *= 0.95;
	mouse_pos_after_zoom = rescale_pixel(px, fractal);
	fractal->shiftx += (mouse_pos_before_zoom.real - mouse_pos_after_zoom.real);
	fractal->shifty += (mouse_pos_before_zoom.imaginary - mouse_pos_after_zoom.imaginary);
	fractal_refresh(fractal);
	return 0;
}
