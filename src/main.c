

#include "fractol.h"
#include "mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	to_z(int w, int h, double *x, double *y, t_vars *vars)
{
	*x = ((double)(w - WINDOW_W / 2 + vars->dx)) / vars->scale * 0.005;
	*y = -((double)(h - WINDOW_H / 2 + vars->dy)) / vars->scale * 0.005;
}

int	mandelbrot(int w, int h, t_vars *vars)
{
	int		count;
	double	c[2];
	double	z[2];
	double	tmp;

	to_z(w, h, &c[0], &c[1], vars);
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
	return (hsv2rgb(130 + count * 7, 255, 255));
}
/*
void	drow_axis(t_data *img, t_vars *vars)
{
	double	z[2];

	for (int j = 0; j < WINDOW_H; j++)
	{
		for (int i = 0; i < WINDOW_W; i++)
		{
			to_z(i, j, &z[0], &z[1], vars);
			if (z[0] == 0.0 || z[1] == 0.0)
				my_mlx_pixel_put(img, i, j, 0x00555555);
		}
	}
}
*/
/*
void	test_hsv(t_data *img)
{
	for (int j = 0; j < WINDOW_H; j++)
	{
		for (int i = 0; i < WINDOW_W; i++)
		{
			// my_mlx_pixel_put(img, i, j, hsv2rgb(i, 255, 255));
		}
	}
}
*/
int	key_hook(int keycode, t_vars *vars)
{
	printf("--------- key_hook! [%d] ---------\n", keycode);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == KEY_0)
	{
		vars->scale = 1;
		vars->dx = 0;
		vars->dy = 0;
		drow_mandelbrot(vars);
	}
	if ((KEY_LEFT <= keycode && keycode <= KEY_UP) || keycode == KEY_Z
		|| keycode == KEY_X)
	{
		if (keycode == KEY_LEFT)
			vars->dx += 10;
		if (keycode == KEY_RIGHT)
			vars->dx -= 10;
		if (keycode == KEY_DOWN)
			vars->dy -= 10;
		if (keycode == KEY_UP)
			vars->dy += 10;
		if (keycode == KEY_Z)
			vars->scale /= 1.5;
		if (keycode == KEY_X)
			vars->scale *= 1.5;
		drow_mandelbrot(vars);
	}
	return (0);
}

int	close(t_vars *vars)
{
	printf("--------- close ---------  %p\n", vars);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	mouse_move(int x, int y, t_vars *vars)
{
	printf("--------- move [%d, %d] (%d, %d) %p %d\n", x, y, vars->dx, vars->dy,
		vars, vars->down_x);
	if (vars->is_down)
	{
		vars->dx = vars->down_x - x;
		vars->dy = vars->down_y - y;
		drow_mandelbrot(vars);
	}
	return (0);
}

int	mouse_down(int key, int x, int y, t_vars *vars)
{
	int	x2;
	int	y2;

	x2 = x - WINDOW_W / 2;
	y2 = y - WINDOW_H / 2;
	printf("--------- down [%d, %d, %d] %p\n", key, x, y, vars);
	if (key == SCROLL_UP)
	{
		// 拡大
		vars->scale *= ZOOM_RATE;
		vars->dx = (vars->dx + x2) * ZOOM_RATE - x2;
		vars->dy = (vars->dy + y2) * ZOOM_RATE - y2;
		drow_mandelbrot(vars);
	}
	else if (key == SCROLL_DOWN)
	{
		// 縮小
		vars->scale /= ZOOM_RATE;
		vars->dx = (vars->dx + x2) / ZOOM_RATE - x2;
		vars->dy = (vars->dy + y2) / ZOOM_RATE - y2;
		drow_mandelbrot(vars);
	}
	else if (key == MOUSE_LEFT)
	{
		vars->is_down = 1;
		vars->down_x = x + vars->dx;
		vars->down_y = y + vars->dy;
	}
	return (0);
}

int	mouse_up(int key, int x, int y, t_vars *vars)
{
	printf("--------- up [%d, %d, %d] %p\n", key, x, y, vars);
	if (key == MOUSE_LEFT)
	{
		vars->is_down = 0;
	}
	return (0);
}

void	drow_mandelbrot(t_vars *vars)
{
	t_data	img;

	img.img = mlx_new_image(vars->mlx, WINDOW_W, WINDOW_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);
	for (int j = 0; j < WINDOW_H; j++)
	{
		for (int i = 0; i < WINDOW_W; i++)
		{
			my_mlx_pixel_put(&img, i, j, mandelbrot(i, j, vars));
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WINDOW_W, WINDOW_H, "Mandelbrot");
	vars.scale = 1;
	vars.dx = 0;
	vars.dy = 0;
	vars.is_down = 0;
	vars.down_x = -1;
	vars.down_y = -1;
	drow_mandelbrot(&vars);
	// mouse
	mlx_hook(vars.win, ON_MOUSEMOVE, 0, mouse_move, &vars);
	mlx_hook(vars.win, ON_MOUSEDOWN, 0, mouse_down, &vars);
	mlx_hook(vars.win, ON_MOUSEUP, 0, mouse_up, &vars);
	// key
	mlx_key_hook(vars.win, key_hook, &vars);
	// mlx_do_key_autorepeaton(vars.mlx);
	// close button
	mlx_hook(vars.win, ON_DESTROY, 0, close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
