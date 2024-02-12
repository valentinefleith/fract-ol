/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:58:39 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/12 20:59:07 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

int check_limits(int value, int min, int max) 
{
	if (value < min)
		return min;
	if (value > max)
		return max;
	return value;
}

int adjust_brightness(int color, int brightness)
{
    int red = (color >> 16) & 0xFF;
    int green = (color >> 8) & 0xFF;
    int blue = color & 0xFF;
	
    red = check_limits(red - brightness, 0, 255);
    green = check_limits(green - brightness, 0, 255);
    blue = check_limits(blue - brightness, 0, 255);

    return (red << 16) | (green << 8) | blue;
}

int get_color(int iterations, t_fractal *fractal)
{
	int brightness;

	brightness = iterations * fractal->brightness;
	return adjust_brightness(fractal->colorset, brightness);
}

int change_brightness(t_fractal *fractal, int keycode)
{
	if (keycode == KEY_B)
		fractal->brightness--;
	if (keycode == KEY_D)
		fractal->brightness++;
	fractal_refresh(fractal);
	return 0;
}

int change_colors(t_fractal *fractal)
{

	//int colors[] = {0x0011FC92, 0x00119EFC, 0x00FCBE11, 0x00AB3434};
	//fractal->colorset = fractal->colorset * 0.7 + 5;
	//fractal->colorset = fractal->colorset * 1.5 - 560;
	//fractal->colorset = fractal->colorset * 1.01 + 5;
	if (fractal->colornb == 3)
		fractal->colornb = 0;
	else
		fractal->colornb++;
	fractal->colorset = fractal->palette[fractal->colornb];
	fractal_refresh(fractal);	
	return 0;
}
