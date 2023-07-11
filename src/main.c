

#include "fractol.h"
#include "mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void	init_loop(t_vars *vars, int loop)
{
	vars->progress = 0;
	vars->loop = loop;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	to_z(int w, int h, double *x, double *y, t_vars *vars)
{
	*x = ((double)(w - vars->win_w / 2 + vars->dx)) / vars->scale * 0.005;
	*y = -((double)(h - vars->win_h / 2 + vars->dy)) / vars->scale * 0.005;
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
	while (z[0] * z[0] + z[1] * z[1] < MAX_Z && count < vars->loop)
	{
		tmp = z[0] * z[0] - z[1] * z[1] + c[0];
		z[1] = 2.0 * z[0] * z[1] + c[1];
		z[0] = tmp;
		count++;
	}
	if (count == vars->loop)
		return (0);
	if (count < 50)
		return (hsv2rgb(130 + count * 7, 255, 255));
	else
		return (hsv2rgb(130 + count, 255, 255));
}

int	key_hook(int keycode, t_vars *vars)
{
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
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	mouse_move(int x, int y, t_vars *vars)
{
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

	x2 = x - vars->win_w / 2;
	y2 = y - vars->win_h / 2;
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
	if (key == MOUSE_LEFT)
		vars->is_down = 0;
	return (0);
}

void	drow_mandelbrot(t_vars *vars)
{
	t_data	*img;

	init_loop(vars, INIT_LOOP);
	img = &vars->img;
	img->img = mlx_new_image(vars->mlx, vars->win_w, vars->win_h);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
		&img->line_length, &img->endian);
	for (int j = 0; j < vars->win_h; j++)
	{
		for (int i = 0; i < vars->win_w; i++)
		{
			my_mlx_pixel_put(img, i, j, mandelbrot(i, j, vars));
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
	vars->loop += 20;
}

char	*get_pixel(int x, int y, t_data *img)
{
	return (img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8)));
}

int	is_complete(t_vars *vars)
{
	return (vars->progress >= vars->win_h * vars->win_w - 1);
}

int	render_next_frame(t_vars *vars)
{
	t_data	*img;
	char	*dst;
	int		start;
	int		i;
	int		j;

	start = vars->progress;
	img = &vars->img;
	for (int n = vars->progress; n < vars->win_h * vars->win_w; n++)
	{
		i = n % vars->win_w;
		j = n / vars->win_w;
		if (is_complete(vars))
		{
			mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
			printf("comp %Lf, %d\n", vars->scale, vars->loop);
			if (vars->loop < 10000000)
				init_loop(vars, vars->loop * 1.5);
			return (0);
		}
		if (vars->progress > start + 5000000 / vars->loop)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
			return (0);
		}
		dst = get_pixel(i, j, img);
		if (*dst == 0)
			*(unsigned int *)dst = mandelbrot(i, j, vars);
		vars->progress = n;
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.scale = 1.0;
	vars.dx = 0.0;
	vars.dy = 0.0;
	vars.is_down = 0;
	vars.down_x = 0.0;
	vars.down_y = 0.0;
	vars.win_w = WINDOW_W;
	vars.win_h = WINDOW_H;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.win_w, vars.win_h, "Mandelbrot");
	init_loop(&vars, INIT_LOOP);
	drow_mandelbrot(&vars);
	// mouse
	mlx_hook(vars.win, ON_MOUSEMOVE, 0, mouse_move, &vars);
	mlx_hook(vars.win, ON_MOUSEDOWN, 0, mouse_down, &vars);
	mlx_hook(vars.win, ON_MOUSEUP, 0, mouse_up, &vars);
	// key
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_do_key_autorepeaton(vars.mlx);
	// close button
	mlx_hook(vars.win, ON_DESTROY, 0, close, &vars);
	// loop
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

// 画像が荒くなる
//--------- move [427, 537] (-9804279408184684.000000,
//	-49169586665984112.000000) 0x16b205f00 -46299400465567.914062
// zoom: -268228477880337312.000000 -13233340686353.125000 671787610756710.12
