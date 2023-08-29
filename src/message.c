/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:22:33 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/08/29 17:23:11 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_synopsis(void)
{
	ft_putstr("\
SYNOPSIS\n\
	fractol model [parameter1] [parameter2]\n\
\n");
}

static void	print_description(void)
{
	ft_putstr("\
DESCRIPTION\n\
	model		(mandelbrot | julia | sierpinski)\n\
	parameter1	the real part of the parameter for Julia set\n\
	parameter2	the imaginary part of the parameter for Julia set \n\
\n");
}

static void	print_parameter(void)
{
	ft_putstr("\
PARAMETER\n\
	Parameters are used only if Julia is selected as the model.\n\
\n\
	length	9 characters or less\n\
	range	-2.0 <= param <= +2.0\n\
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
