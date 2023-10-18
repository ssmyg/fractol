/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:20:13 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/10/18 18:48:55 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

# include "fractol.h"

# define ZOOM_RATE 1.25

// mouse
# define MOUSE_LEFT 1
# define SCROLL_UP 4
# define SCROLL_DOWN 5

int	mouse_move(int x, int y, t_vars *vars);
int	mouse_down(int key, int x, int y, t_vars *vars);
int	mouse_up(int key, int x, int y, t_vars *vars);

#endif
