/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:31:18 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/19 11:33:33 by vafleith         ###   ########.fr       */
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
