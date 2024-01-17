/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:57:50 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/17 10:08:39 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct s_data
{
	void *img; // Pointeur vers l'image
	char *addr; // Adresse des donnees de l'image
	int bits_per_pixel; // Nombre de bits utilises pour representer un px
	int line_length; // Nombre de caracteres dans une ligne de l'image
	int endian; // Format de stockage des couleurs (BE ou LE)
}		t_data;


void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));

	*(unsigned int*)dst = color;
}


int main(void)
{
	void *mlx;
	t_data img;
	void *win;

	mlx = mlx_init();

	//Creer une fenetre
	win = mlx_new_window(mlx, 800, 800, "test window");
	
	// Creer une image
	img.img = mlx_new_image(mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// Afficher l'image dans la fenetre
	
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0A80);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);

	// Lancer la boucle d'evenements
	mlx_loop(mlx);
}
