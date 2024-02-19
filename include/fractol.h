/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:42:11 by vafleith          #+#    #+#             */
/*   Updated: 2024/02/19 11:10:02 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "keycodes.h"
# include "libft.h"
# include <math.h>
# include <mlx.h>
# include <stdlib.h>

# define MALLOC_ERROR 1

# define HEIGHT 960
//#define HEIGHT 720
# define WIDTH 1080
//#define WIDTH 810
# define MAX_ITERATIONS 200
# define MIN_ITERATIONS 30

# define MAX 4

# define WHITE 0x00FFFFFF
# define BLACK 0x000000

# define LINE_LENGTH 20

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_complex
{
	double		real;
	double		imaginary;
}				t_complex;

typedef struct s_fractal
{
	void		*mlx;
	void		*win;
	t_img		img;
	int			set;
	int			max_iterations;
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		zoom;
	double		shiftx;
	double		shifty;
	int			colorset;
	int			palette[11];
	int			colornb;
	t_complex	current_point;
	int			help;
	int			brightness;
	int			lock;

}				t_fractal;

typedef struct s_pixel
{
	int			x;
	int			y;
}				t_pixel;

// ====== VIEW ======
int				zoom_out(t_fractal *fractal);
int				zoom_in(t_fractal *fractal, int x, int y);
int				shiftreal(t_fractal *fractal, char direction);
int				shiftimaginary(t_fractal *fractal, char direction);

// ====== FRACTAL SETS =======
int				calculate_mandelbrot(t_pixel px, t_fractal *fractal);
int				calculate_burning_ship(t_pixel px, t_fractal *fractal);
int				calculate_julia(t_pixel px, t_fractal *fractal);
int				change_julias_shape(int x, int y, t_fractal *fractal);

// ====== DRAWING ======
int				get_color(int iterations, t_fractal *fractal);
void			calculate_and_put_pixels(t_fractal *fractal);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
int				adjust_brightness(int color, int brightness);

// ====== EVENTS =======
int				mouse_events(int button, int x, int y, t_fractal *fractal);
int				key_events(int keycode, t_fractal *fractal);
int				mouse_move(int x, int y, t_fractal *fractal);
int				change_colors(t_fractal *fractal);
int				change_precision(t_fractal *fractal, int keycode);
int				handle_shift(t_fractal *fractal, int keycode);
int				change_brightness(t_fractal *fractal, int keycode);
int				exit_program(t_fractal *fractal);

// ====== DISPLAY ======
int				display_commands(t_fractal *fractal);
void			display_standard(t_fractal *fractal);
void 			display_julias_param(t_fractal *fractal);

// ====== INIT =======
void			init_fractal(t_fractal *fractal);
void			init_struct(t_fractal *fractal, t_img img);
void			init_palette(t_fractal *fractal);
void			init_hook(t_fractal *fractal);

// ====== UTILS ======
void			fractal_refresh(t_fractal *fractal);
t_complex		convert_pixel_into_complex(t_pixel px, t_fractal *fractal);
t_complex		rescale_pixel(t_pixel px, t_fractal *fractal);
int				parse_args(int argc, char **argv, t_fractal *fractal);
int				check_limits(int value, int min, int max);
int 			free_window(t_fractal *fractal);
double ft_atod(char *str);
char *ft_dtoa(double n);

#endif
