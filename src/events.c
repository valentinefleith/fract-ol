/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:46:58 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/29 10:14:57 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"
#include <stdio.h>

int key_events(int keycode, t_fractal *fractal)
{
	if (keycode == 65307)
		return close_window(fractal);
	if (keycode == 0x0063) // c
		return change_colors(fractal);
	if (keycode == 0x0065) // e
		return shiftreal(fractal, '+');
	if (keycode == 0x0071) // q
		return shiftreal(fractal, '-');
	if (keycode == 0x0077) // w
		return shiftimaginary(fractal, '-');
	if (keycode == 0x0073) // s
		return shiftimaginary(fractal, '+');
	if (keycode == 0x0070) // p
		return zoom_in(fractal);
	if (keycode == 0x006d) // m
		return zoom_out(fractal);
	if (keycode == 0x006a) //j
		return change_julia(fractal);
	return 0;
}

int mouse_events(int button, t_fractal *fractal)
{
	if (button == 2 ){
		printf("clicked\n");
		//printf("%f\n", fractal->zoom);
		return zoom_out(fractal);}
}

int close_window(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(0);
	return (0);
}

int change_julia(t_fractal *fractal)
{
	fractal->current_point.real += 0.01;
	fractal->current_point.imaginary += 0.1;
	fractal_refresh(fractal);
	return 0;
}

int zoom_in(t_fractal *fractal)
{
	fractal->zoom *= 0.9;
	fractal_refresh(fractal);
	return 0;
}

int zoom_out(t_fractal *fractal)
{
	fractal->zoom /= 0.7;
	fractal_refresh(fractal);
	return 0;
}

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
	if (direction == '-')
		fractal->shifty += (0.1 * fractal->zoom);
	else 
		fractal->shifty -= (0.1 * fractal->zoom);
	fractal_refresh(fractal);
	return 0;
}

int change_colors(t_fractal *fractal)
{
	//int colors[] = {0x0011FC92, 0x00119EFC, 0x00FCBE11, 0x00AB3434};
	//fractal->colorset = fractal->colorset * 0.7 + 5;
	fractal->colorset = fractal->colorset * 1.01 + 5;
//	if (fractal->colorset == 0x00119EFC)
	//fractal->colorset = 0x00FCBE11;
//	else if (fractal->colorset == 0x00FCBE11)
//		fractal->colorset = 0x0011FC92;
//	else if (fractal->colorset == 0x0011FC92)
//		fractal->colorset = 0x00119EFC;
//
	fractal_refresh(fractal);	
	return 0;
}
