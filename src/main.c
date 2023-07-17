/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:11:44 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/07/17 11:43:05 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "fractol.h"
#include "message.h"
#include "render.h"
#include "window.h"

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
