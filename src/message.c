/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:22:33 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/07/14 15:31:09 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_synopsis(void)
{
	ft_putstr("\
SYNOPSIS\n\
	fractol model [param1] [param2]\n\
\n");
}

static void	print_description(void)
{
	ft_putstr("\
DESCRIPTION\n\
	model	(mandelbrot | julia | sierpinski)\n\
	param1	parameter1 for Julia set (real part)\n\
	param2	parameter2 for Julia set (imaginary part)\n\
\n");
}

static void	print_parameter(void)
{
	ft_putstr("\
PARAMETER\n\
	Parameters are used only if Julia is selected as the model.\n\
\n\
	format	\"(+|-)d.dddd\" (e.g. +1.2345)\n\
	range	-2.0000 <= param <= +2.0000)\n\
\n");
}

static void	print_usage(void)
{
	ft_putstr("\
USAGE\n\
	arrow	move the view\n\
	ESC	close window\n\
	0	Restore the view to its initial state\n\
	z + scroll	zoom in / out \n\
	c + scroll	shift color range\n\
	r + scroll	shift real parameter\n\
	i + scroll	shift imaginary parameter\n\
\n");
}

void	print_message(void)
{
	print_synopsis();
	print_description();
	print_parameter();
	print_usage();
}
