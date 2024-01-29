/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:04:57 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/29 16:05:31 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int zoom_in(t_fractal *fractal)
{
	fractal->zoom *= 0.9;
	//fractal->max_iterations++;
	fractal_refresh(fractal);
	return 0;
}

int zoom_out(t_fractal *fractal)
{
	fractal->zoom /= 0.7;
	//fractal->max_iterations--;
	fractal_refresh(fractal);
	return 0;
}
