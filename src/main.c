/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:57:50 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/08 14:34:38 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
void fractal_refresh(t_fractal *fractal)
{
	t_img new_img;
	mlx_destroy_image(fractal->mlx, fractal->img.img);
	new_img.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	new_img.addr = mlx_get_data_addr(new_img.img, &new_img.bits_per_pixel, &new_img.line_length, &new_img.endian);
	fractal->img = new_img;
	calculate_and_put_pixels(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, new_img.img, 0, 0);
	display_help(fractal);
}

void parse_args(int argc, char **argv, t_fractal *fractal)
{
	if (!ft_strncmp(argv[1], "mandelbrot", ft_strlen("mandelbrot")))
		fractal->set = 0;
	if (!ft_strncmp(argv[1], "julia", ft_strlen("julia")))
		fractal->set = 1;
	//if (argc > 2)
}

int main(int argc, char **argv)
{
	t_fractal fractal;
	
	if (argc < 2)
	{
		ft_printf("Usage : ./fract-ol fractal-name\n");
		return 1;
	}
	fractal.mlx = mlx_init();
	if (fractal.mlx == NULL)
		return (1);

	parse_args(argc, argv, &fractal);
	//Creer une fenetre
	fractal.win = mlx_new_window(fractal.mlx, WIDTH, HEIGHT, "test window");
	if (fractal.win == NULL)
	{
		mlx_destroy_display(fractal.mlx);
		free(fractal.mlx);
		return (1);

	}
	draw_fractal(&fractal);
	
	//mlx_mouse_hook(fractal.win, mouse_hook, &vars);
	//mlx_hook(fractal.win, 4, 0, key_events, &fractal);
	//mlx_hook(fractal.win, 4, 0, mouse_events, &fractal);
	mlx_mouse_hook(fractal.win, mouse_events, &fractal);
	mlx_key_hook(fractal.win, key_events, &fractal);
	//mlx_hook(fractal.win, 1, 0, mouse_events, &fractal);

	// Lancer la boucle d'evenements
	mlx_loop(fractal.mlx);
}
