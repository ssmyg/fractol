/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:08:16 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/07/14 15:30:26 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keyboard.h"
#include "render.h"
#include "window.h"

static void	key_zric(int keycode, t_vars *vars)
{
	if (keycode == KEY_Z)
		vars->keycode = KEY_Z;
	if (keycode == KEY_R)
		vars->keycode = KEY_R;
	if (keycode == KEY_I)
		vars->keycode = KEY_I;
	if (keycode == KEY_C)
		vars->keycode = KEY_C;
}

static void	key_arrow(int keycode, t_vars *vars)
{
	if (KEY_LEFT <= keycode && keycode <= KEY_UP)
	{
		if (keycode == KEY_LEFT)
			vars->dx += 10.0;
		if (keycode == KEY_RIGHT)
			vars->dx -= 10.0;
		if (keycode == KEY_DOWN)
			vars->dy -= 10.0;
		if (keycode == KEY_UP)
			vars->dy += 10.0;
		drow_img(vars);
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		window_close(vars);
	if (keycode == KEY_0)
	{
		vars->scale = 1.0;
		vars->dx = 0.0;
		vars->dy = 0.0;
		drow_img(vars);
	}
	key_zric(keycode, vars);
	key_arrow(keycode, vars);
	return (0);
}
