/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:17:43 by jmeruma           #+#    #+#             */
/*   Updated: 2022/12/14 14:39:48 by jmeruma          ###   ########.fr       */
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

	draw.sign_x = ft_ternary(p0.x_grid < p1.x_grid, 1, -1);
	draw.sign_y = ft_ternary(p0.y_grid < p1.y_grid, 1, -1);
	draw.x_axis = p0.x_grid;
	draw.y_axis = p0.y_grid;
	draw.dx = ft_abs(p1.x_grid - p0.x_grid);
	draw.dz = ft_abs(p1.y_grid - p0.y_grid);
	draw.err = ft_ternary(draw.dx > draw.dz, draw.dx, -draw.dz) / 2;
	return (draw);
}

int	draw_break(t_draw draw, t_point p0, t_point p1)
{
	if ((draw.x_axis == p1.x_grid && draw.y_axis == p1.y_grid)
		|| (p0.x_grid > WIDTH && p1.x_grid > WIDTH)
		|| (p0.y_grid > HEIGHT && p1.y_grid > HEIGHT)
		|| (p0.x_grid < 0 - 900 && p1.x_grid < 0 - 900)
		|| (p0.y_grid < 0 && p1.y_grid < 0))
		return (1);
	return (0);
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
			&& (draw.y_axis + y < HEIGHT && draw.y_axis + y > 0))
			mlx_put_pixel(grid->img, draw.x_axis + x,
				draw.y_axis + y, color_grad(p0, p1, draw));
		if (draw_break(draw, p0, p1) == 1)
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
			draw.y_axis += draw.sign_y;
		}
	}
}
