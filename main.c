/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:57:50 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/18 17:47:17 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int main(void)
{
	//void *mlx;
	t_vars vars;
	t_data img;
	//void *win;

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (MALLOC_ERROR);

	//Creer une fenetre
	vars.win = mlx_new_window(vars.mlx, 800, 800, "test window");
	if (vars.win == NULL)
	{
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
		return (MALLOC_ERROR);

	}
	
	// Creer une image
	img.img = mlx_new_image(vars.mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// Afficher l'image dans la fenetre
	
	for (int i = 20; i < 400; i++)
	{
		for (int j = 20; j < 400; j++)
		{
			my_mlx_pixel_put(&img, i, j, 0x00FF0A80);
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	
	//mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_key_hook(vars.win, close_window, &vars);
	mlx_hook(vars.win, 4, 0, close_window, &vars);

	// Lancer la boucle d'evenements
	mlx_loop(vars.mlx);
}
