/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:57:50 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/26 10:47:20 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void fractal_refresh(t_fractal *fractal)
{
	t_img new_img;
	mlx_destroy_image(fractal->mlx, fractal->img.img);
	new_img.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	new_img.addr = mlx_get_data_addr(new_img.img, &new_img.bits_per_pixel, &new_img.line_length, &new_img.endian);
	fractal->img = new_img;
	calculate_and_put_pixels(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, new_img.img, 0, 0);
}

int main(void)
{
	t_fractal fractal;

	fractal.mlx = mlx_init();
	if (fractal.mlx == NULL)
		return (MALLOC_ERROR);

	//Creer une fenetre
	fractal.win = mlx_new_window(fractal.mlx, WIDTH, HEIGHT, "test window");
	if (fractal.win == NULL)
	{
		mlx_destroy_display(fractal.mlx);
		free(fractal.mlx);
		return (MALLOC_ERROR);

	}
	draw_fractal(&fractal);
	
	//mlx_mouse_hook(fractal.win, mouse_hook, &vars);
	mlx_hook(fractal.win, 4, 0, manage_events, &fractal);
	mlx_key_hook(fractal.win, manage_events, &fractal);

	// Lancer la boucle d'evenements
	mlx_loop(fractal.mlx);
}
