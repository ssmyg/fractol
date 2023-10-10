/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:11:44 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/10/10 11:24:41 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "fractol.h"
#include "message.h"
#include "render.h"
#include "window.h"

// TODO define ERROR_ARG
// TODO 最大、最小拡大率を設定
// TODO color rangeのシフト幅を増やす
// TODO 枠外クリックを無視
// TODO 前回計算結果を保存、何ループ目かも保存する

int	main(int argc, char *argv[])
{
	t_vars	vars;

	init_vars(&vars);
	if (set_arg(argc, argv, &vars))
	{
		print_message();
		return (0);
	}
	init_window(&vars);
	drow_img(&vars);
	set_hooks(&vars);
	return (0);
}
