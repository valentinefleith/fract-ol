/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:42:11 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/19 11:12:03 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>

#define MALLOC_ERROR 1

#define HEIGHT 960
//#define HEIGHT 480
#define WIDTH 1080
//#define WIDTH 540


typedef struct s_data
{
	void *img; // Pointeur vers l'image
	char *addr; // Adresse des donnees de l'image
	int bits_per_pixel; // Nombre de bits utilises pour representer un px
	int line_length; // Nombre de caracteres dans une ligne de l'image
	int endian; // Format de stockage des couleurs (BE ou LE)
}		t_data;

typedef struct s_vars
{
	void *mlx;
	void *win;
}
	t_vars;

typedef struct s_complex
{
	double real;
	double imaginary;
}
	t_complex;

void calculate_and_put_pixels(t_data *img);
void draw_fractal(t_vars vars);
int close_window(int keycode, t_vars *vars);
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
int calculate_pixel_color(int x, int y);
int	create_trgb(int t, int r, int g, int b);