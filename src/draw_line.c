/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisse <jisse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:17:43 by jmeruma           #+#    #+#             */
/*   Updated: 2022/12/08 17:57:02 by jisse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int	ft_ternary(int statement, int true_out, int false_out)
{
	if (statement)
		return (true_out);
	return (false_out);
}

int	ft_abs(int diff)
{
	if (diff < 0)
		return (diff *= -1);
	return (diff);
}

t_draw	draw_init(t_point p0, t_point p1)
{
	t_draw	draw;

	draw.sign_x = ft_ternary(p0.x_axis < p1.x_axis, 1, -1);
	draw.sign_y = ft_ternary(p0.z_axis < p1.z_axis, 1, -1);
	draw.x_axis = p0.x_axis;
	draw.z_axis = p0.z_axis;
	draw.dx = ft_abs(p1.x_axis - p0.x_axis);
	draw.dz = ft_abs(p1.z_axis - p0.z_axis);
	draw.err = ft_ternary(draw.dx > draw.dz, draw.dx, -draw.dz) / 2;
	return (draw);
}

void	line_draw(t_map *grid, t_point p0, t_point p1)
{
	int		errtemp;
	t_draw	draw;
	int x;
	int y;

	x = 900;
	y = 0;
	draw = draw_init(p0, p1);
	while (1)
	{
		if ((draw.x_axis + x < WIDTH && draw.x_axis + x > 0)
			&& (draw.z_axis + y < HEIGHT && draw.z_axis + y > 0))
			mlx_put_pixel(grid->img, draw.x_axis + x,
				draw.z_axis + y, color_grad(p0, p1, draw));
		if (draw.x_axis == p1.x_axis && draw.z_axis == p1.z_axis)
			break ;
		errtemp = draw.err;
		if (errtemp > -draw.dx)
		{
			draw.err -= draw.dz;
			draw.x_axis += draw.sign_x;
		}
		if (errtemp < draw.dz)
		{
			draw.err += draw.dx;
			draw.z_axis += draw.sign_y;
		}
	}
}
