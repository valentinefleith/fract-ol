/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:09:18 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/29 16:09:41 by vafleith         ###   ########.fr       */
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
	if (direction == '-')
		fractal->shifty += (0.1 * fractal->zoom);
	else 
		fractal->shifty -= (0.1 * fractal->zoom);
	fractal_refresh(fractal);
	return 0;
}
