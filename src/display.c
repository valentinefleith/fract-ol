/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:28:41 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/13 17:12:01 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	display_string_centered(t_fractal *fractal, int *y, char *str)
{
	int	x;

	x = (WIDTH - ft_strlen(str) * 6) / 2;
	mlx_string_put(fractal->mlx, fractal->win, x, *y, WHITE, str);
	*y += LINE_LENGTH;
}

static void	display_command_list(t_fractal *fractal, int *y)
{
	display_string_centered(fractal, y, "arrows : Move");
	display_string_centered(fractal, y, "mouse wheel : Zoom");
	display_string_centered(fractal, y, "p : Add precision");
	display_string_centered(fractal, y, "m : Decrease precision");
	display_string_centered(fractal, y, "c : Change colorset");
	display_string_centered(fractal, y, "d : Add darkness");
	display_string_centered(fractal, y, "b : Add brightness");
	display_string_centered(fractal, y, "r : Reset");
	if (fractal->set == 1)
		display_string_centered(fractal, y, "l : lock/unlock mouse moving");
}

void	display_standard(t_fractal *fractal)
{
	char	*scale;
	char	*final_scale;

	if (fractal->set == 0)
		mlx_string_put(fractal->mlx, fractal->win, 40, 20, BLACK,
			"------- MANDELBROT SET -------");
	else if (fractal->set == 1)
		mlx_string_put(fractal->mlx, fractal->win, 40, 20, BLACK,
			"------- JULIA SET -------");
	else if (fractal->set == 2)
		mlx_string_put(fractal->mlx, fractal->win, 40, 20, BLACK,
			"------- BURNING SHIP FRACTAL -------");
	mlx_string_put(fractal->mlx, fractal->win, 40, 40, BLACK,
		"Press h to display help");
	scale = ft_itoa(1 / fractal->zoom);
	final_scale = ft_strjoin("Scale : 1/", scale);
	mlx_string_put(fractal->mlx, fractal->win, WIDTH - 130, 30, BLACK,
		final_scale);
	free(final_scale);
	free(scale);
}

// void display_julias_param(t_fractal *fractal)
//{
//	mlx_string_put(fractal->mlx, fractal->win, WIDTH - 20, 30, BLACK, "Current julia point : ");
//}

int	display_commands(t_fractal *fractal)
{
	int		y;
	t_img	background;

	y = 30;
	fractal->help = 1;
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
	if (fractal->set == 0)
		display_string_centered(fractal, &y, "------- MANDELBROT SET -------");
	else if (fractal->set == 1)
		display_string_centered(fractal, &y, "------- JULIA SET -------");
	else if (fractal->set == 2)
		display_string_centered(fractal, &y,
			"------- BURNING SHIP FRACTAL -------");
	y += LINE_LENGTH;
	display_command_list(fractal, &y);
	return (0);
}
