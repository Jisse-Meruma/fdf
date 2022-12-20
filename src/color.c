/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:11:14 by jmeruma           #+#    #+#             */
/*   Updated: 2022/12/20 14:10:05 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int	gradiant(int point_col0, int point_col1, float percentage)
{
	return ((int)((1 - percentage) * point_col0 + (percentage * point_col1)));
}

float	percent(int point_0, int point_1, int current)
{
	float	current_diff;
	float	diff;

	current_diff = current - point_0;
	diff = point_1 - point_0;
	return (current_diff / diff);
}

int rgb_combine(int r, int g, int b)
{
	return	(r << 24 | g << 16 | b << 8);
}

uint32_t	color_grad(t_point p0, t_point p1, t_draw draw)
{
	int			red;
	int			green;
	int			blue;
	int			color;
	float		percentage;

	if (p0.col == p1.col)
		return (p0.col | 0xFF);
	if (draw.dx < draw.dz)
		percentage = percent(p0.y_grid, p1.y_grid, draw.y_axis);
	else
		percentage = percent(p0.x_grid, p1.x_grid, draw.x_axis);
	red = gradiant(((p0.col >> 24) & 0xFF),
			((p1.col >> 24) & 0xFF), percentage);
	green = gradiant(((p0.col >> 16) & 0xFF),
			((p1.col >> 16) & 0xFF), percentage);
	blue = gradiant(((p0.col >> 8) & 0xFF),
			((p1.col >> 8) & 0xFF), percentage);
	color = rgb_combine(red, green, blue) | 0xFF;
	return(color);
}	
