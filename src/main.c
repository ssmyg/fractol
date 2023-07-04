

#include "mlx.h"
//#include <math.h>
#include "fractol.h"
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_X 700
#define WINDOW_Y 500
#define MAX_LOOP 1000
#define MAX_Z 100.0

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	to_z(int w, int h, double *x, double *y)
{
	*x = (double)(w - WINDOW_X / 2) / 200.0;
	*y = -(double)(h - WINDOW_Y / 2) / 200.0;
}

int	mandelbrot(int w, int h)
{
	int		count;
	double	c[2];
	double	z[2];
	double	tmp;

	to_z(w, h, &c[0], &c[1]);
	count = 0;
	z[0] = 0;
	z[1] = 0;
	while (z[0] * z[0] + z[1] * z[1] < MAX_Z && count < MAX_LOOP)
	{
		tmp = z[0] * z[0] - z[1] * z[1] + c[0];
		z[1] = 2.0 * z[0] * z[1] + c[1];
		z[0] = tmp;
		count++;
	}
	if (count == MAX_LOOP)
		return (0);
	return (hsv2rgb(100 + count * 7, 255, 255));
}

void	drow_axis(t_data *img)
{
	double	z[2];

	for (int j = 0; j < WINDOW_Y; j++)
	{
		for (int i = 0; i < WINDOW_X; i++)
		{
			to_z(i, j, &z[0], &z[1]);
			if (z[0] == 0.0 || z[1] == 0.0)
				my_mlx_pixel_put(img, i, j, 0x00555555);
		}
	}
}

void	test_hsv(t_data *img)
{
	for (int j = 0; j < WINDOW_Y; j++)
	{
		for (int i = 0; i < WINDOW_X; i++)
		{
			//			if (0 <= i && 0 <= 360)
			my_mlx_pixel_put(img, i, j, hsv2rgb(i, 255, 255));
		}
	}
}

int	key_hook(int keycode, t_mlx *mlx)
{
	printf("--------- key_hook! [%d] ---------\n", keycode);
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return (0);
}

int	close(void)
{
	printf("--------- close ---------\n");
	// mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}

int	main(void)
{
	t_data	img;
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WINDOW_X, WINDOW_Y, "Mandelbrot");
	img.img = mlx_new_image(mlx.mlx, WINDOW_X, WINDOW_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);
	for (int j = 0; j < WINDOW_Y; j++)
	{
		for (int i = 0; i < WINDOW_X; i++)
		{
			my_mlx_pixel_put(&img, i, j, mandelbrot(i, j));
		}
	}
	// test_hsv(&img);
	// drow_axis(&img);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	// ESC
	mlx_key_hook(mlx.win, key_hook, &mlx);
	// close button
	mlx_hook(mlx.win, ON_DESTROY, 0, close, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
