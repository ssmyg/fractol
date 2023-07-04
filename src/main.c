

#include "mlx.h"
//#include <math.h>
#include <stdio.h>

#define WINDOW_X 700
#define WINDOW_Y 500
#define MAX_LOOP 1000
#define MAX_Z 100.0

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

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

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	hsv2rgb(int h, int s, int v)
{
	int	max;
	int	min;

	max = v;
	min = max - (s * max / 255);
	if (0 <= h && h < 60)
		return (trgb(0, max, h * (max - min) / 60 + min, min));
	else if (60 <= h && h < 120)
		return (trgb(0, (120 - h) * (max - min) / 60, max, min));
	else if (120 <= h && h < 180)
		return (trgb(0, min, max, (h - 120) * (max - min) / 60));
	else if (180 <= h && h < 240)
		return (trgb(0, min, (240 - h) * (max - min) / 60, max));
	else if (240 <= h && h < 300)
		return (trgb(0, (h - 240) * (max - min) / 60, min, max));
	else
		return (trgb(0, max, min, (360 - h) * (max - min) / 60));
}

// int	mandelbrot(double a, double b)
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
	return (hsv2rgb((200 + count * 7) % 360, 255, 255));
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
			if (0 <= i && 0 <= 360)
				my_mlx_pixel_put(img, i, j, hsv2rgb(i, 255, 255));
		}
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_X, WINDOW_Y, "Mandelbrot");
	img.img = mlx_new_image(mlx, WINDOW_X, WINDOW_Y);
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
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
