/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:28:41 by vafleith          #+#    #+#             */
/*   Updated: 2024/03/16 00:17:15 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	display_command_list(t_fractal *fractal, int *y)
{
	display_string_centered(fractal, y, "==== GENERAL ====");
	display_string_centered(fractal, y, "arrows : move");
	display_string_centered(fractal, y, "mouse wheel : zoom");
	display_string_centered(fractal, y, "f : change fractal set");
	display_string_centered(fractal, y, "<space> : reset");
	display_string_centered(fractal, y, "p : add precision");
	display_string_centered(fractal, y, "m : decrease precision");
	*y += LINE_LENGTH;
	display_string_centered(fractal, y, "==== COLORS ====");
	display_string_centered(fractal, y, "c : change colorset");
	display_string_centered(fractal, y, "1 / 2 : add darkness / brightness");
	display_string_centered(fractal, y, "r / g / b : add red / green / blue");
	*y += LINE_LENGTH;
	if (fractal->set == 1 || fractal->set == 4)
	{
		display_string_centered(fractal, y, "==== SPECIFIC TO JULIA ====");
		display_string_centered(fractal, y, "l : lock/unlock mouse moving");
		display_string_centered(fractal, y,
			"click : change julia's current point");
	}
	if (fractal->set == 3)
	{
		display_string_centered(fractal, y, "==== SPECIFIC TO MULTIBROT ====");
		display_string_centered(fractal, y, "t : next power");
	}
}

static void	display_precision(t_fractal *fractal)
{
	char	*precision;
	char	*formatted_precision;

	precision = ft_itoa(fractal->max_iterations);
	if (precision == NULL)
		return ;
	formatted_precision = ft_strjoin("Precision : ", precision);
	if (formatted_precision == NULL)
	{
		free(precision);
		return ;
	}
	mlx_string_put(fractal->mlx, fractal->win, WIDTH - 130, 50, BLACK,
		formatted_precision);
	free(formatted_precision);
	free(precision);
}

void	display_standard(t_fractal *fractal)
{
	if (fractal->set == 0)
		mlx_string_put(fractal->mlx, fractal->win, 40, 20, BLACK,
			"------- MANDELBROT SET -------");
	else if (fractal->set == 1)
		mlx_string_put(fractal->mlx, fractal->win, 40, 20, BLACK,
			"------- JULIA SET -------");
	else if (fractal->set == 2)
		mlx_string_put(fractal->mlx, fractal->win, 40, 20, BLACK,
			"------- BURNING SHIP FRACTAL -------");
	else if (fractal->set == 3)
		mlx_string_put(fractal->mlx, fractal->win, 40, 20, BLACK,
			"------- MULTIBROT SET -------");
	else if (fractal->set == 4)
		mlx_string_put(fractal->mlx, fractal->win, 40, 20, BLACK,
			"------- JULIA BURNING SHIP -------");
	mlx_string_put(fractal->mlx, fractal->win, 40, 40, BLACK,
		"Press h to display help");
	display_precision(fractal);
	if (fractal->set == 1 || fractal->set == 4)
		display_julias_param(fractal);
}

static void	display_black_window(t_fractal *fractal)
{
	t_img	background;

	mlx_destroy_image(fractal->mlx, fractal->img.img);
	background.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (background.img == NULL)
	{
		free_window(fractal);
		exit(1);
	}
	background.addr = mlx_get_data_addr(background.img,
			&background.bits_per_pixel, &background.line_length,
			&background.endian);
	fractal->img = background;
	mlx_put_image_to_window(fractal->mlx, fractal->win, background.img, 0, 0);
}

int	display_commands(t_fractal *fractal)
{
	int	y;

	y = 30;
	display_black_window(fractal);
	if (fractal->set == 0)
		display_string_centered(fractal, &y, "------- MANDELBROT SET -------");
	else if (fractal->set == 1)
		display_string_centered(fractal, &y, "------- JULIA SET -------");
	else if (fractal->set == 2)
		display_string_centered(fractal, &y,
			"------- BURNING SHIP FRACTAL -------");
	else if (fractal->set == 3)
		display_string_centered(fractal, &y, "------- MULTIBROT SET -------");
	else if (fractal->set == 4)
		display_string_centered(fractal, &y, "------- JULIA BURNING SHIP -------");
	y += LINE_LENGTH;
	display_command_list(fractal, &y);
	return (0);
}
