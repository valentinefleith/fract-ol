/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:28:41 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/01 12:33:00 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void print_string(t_fractal *fractal)
{
	int color = 0x00FFFFFF;
	mlx_string_put(fractal->img.img, fractal->win, 15, 10, color, "Test string display");
}
