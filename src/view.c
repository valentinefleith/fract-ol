/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:04:57 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/12 22:46:54 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int shiftreal(t_fractal *fractal, char direction)
{
	if (direction == '+')
		fractal->shiftx += (0.2 * fractal->zoom);
	else 
		fractal->shiftx -= (0.2 * fractal->zoom);
	fractal_refresh(fractal);
	return 0;
}

int shiftimaginary(t_fractal *fractal, char direction)
{
	if ((direction == '-' && fractal->set != 2) || (direction == '+' && fractal->set == 2))
		fractal->shifty += (0.1 * fractal->zoom);
	else 
		fractal->shifty -= (0.1 * fractal->zoom);
	fractal_refresh(fractal);
	return 0;
}

int zoom_out(t_fractal *fractal)
{
	fractal->zoom /= 0.85;
	//fractal->max_iterations--;
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
