/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:20:13 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/07/14 15:54:23 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

typedef struct s_data {
  void* img;
  char* addr;
  int bits_per_pixel;
  int line_length;
  int endian;
} t_data;

typedef struct s_vars t_vars;

struct s_vars {
  void* mlx;
  void* win;

  double scale;
  double dx;
  double dy;

  int is_down;
  double down_x;
  double down_y;
  int keycode;

  t_data img;

  int progress;
  int loop;

  int win_w;
  int win_h;

  int color;
  int (*model)(int, int, t_vars*);
  double c[2];
};

#endif
