/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:42:11 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/29 10:36:54 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include <mlx.h>
#include <stdlib.h>

#include "libft.h"

#define MALLOC_ERROR 1

#define HEIGHT 960
//#define HEIGHT 480
#define WIDTH 1080
//#define WIDTH 540
#define ZOOM 400
#define WHITE 0x00FFFFFF


typedef struct s_img
{
	void *img; // Pointeur vers l'image
	char *addr; // Adresse des donnees de l'image
	int bits_per_pixel; // Nombre de bits utilises pour representer un px
	int line_length; // Nombre de caracteres dans une ligne de l'image
	int endian; // Format de stockage des couleurs (BE ou LE)
}		t_img;

//typedef struct s_gui
//{
//	void *mlx;
//	void *win;
//}
//	t_gui;

typedef struct s_complex
{
	double real;
	double imaginary;
}
	t_complex;

typedef struct s_fractal
{
	void *mlx;
	void *win;
	t_img img;
	int set;
	double xmin;
	double xmax;
	double ymin;
	double ymax;
	double zoom;
	double shiftx;
	double shifty;
	int colorset;
	t_complex current_point;

}
	t_fractal;

typedef struct s_pixel
{
	int x;
	int y;
}
	t_pixel;

void calculate_and_put_pixels(t_fractal *fractal);
void draw_fractal(t_fractal *fractal);
int close_window(t_fractal *fractal);
int key_events(int keycode, t_fractal *fractal);
int mouse_events(int keycode, t_fractal *fractal);
void my_mlx_pixel_put(t_img *img, int x, int y, int color);
int calculate_pixel_color(t_pixel px, t_fractal *fractal);
int	create_trgb(int t, int r, int g, int b);
int change_colors(t_fractal *fractal);
void fractal_refresh(t_fractal *fractal);
int shiftreal(t_fractal *fractal, char direction);
int shiftimaginary(t_fractal *fractal, char direction);
int zoom_in(t_fractal *fractal);
int zoom_out(t_fractal *fractal);
int change_julia(t_fractal *fractal);
t_complex convert_pixel_into_complex(t_pixel px, t_fractal *fractal);
t_complex rescale_pixel(t_pixel px, t_fractal *fractal);
int calculate_mandelbrot(t_pixel px, t_fractal *fractal);
int calculate_julia(t_pixel px, t_fractal *fractal);

#endif
