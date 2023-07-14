/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:20:13 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/07/14 16:02:28 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL_H
# define MODEL_H

# include "fractol.h"

# define INIT_LOOP 50
# define MAX_Z 6.0

void	to_z(int w, int h, double z[], t_vars *vars);
void	init_loop(t_vars *vars, int loop);

int		mandelbrot(int w, int h, t_vars *vars);
int		julia(int w, int h, t_vars *vars);
int		sierpinski(int w, int h, t_vars *vars);

#endif
