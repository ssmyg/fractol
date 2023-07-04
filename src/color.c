/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:20:52 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/07/04 15:28:44 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	hsv2rgb(int h, int s, int v)
{
	int	max;
	int	min;

	h = h % 360;
	max = v;
	min = max - (s * max / 255);
	if (0 <= h && h < 60)
		return (trgb(0, max, h * (max - min) / 60 + min, min));
	else if (60 <= h && h < 120)
		return (trgb(0, (120 - h) * (max - min) / 60, max, min));
	else if (120 <= h && h < 180)
		return (trgb(0, min, max, (h - 120) * (max - min) / 60));
	else if (180 <= h && h < 240)
		return (trgb(0, min, (240 - h) * (max - min) / 60, max));
	else if (240 <= h && h < 300)
		return (trgb(0, (h - 240) * (max - min) / 60, min, max));
	else if (300 <= h && h <= 360)
		return (trgb(0, max, min, (360 - h) * (max - min) / 60));
	else
		return (0);
}
