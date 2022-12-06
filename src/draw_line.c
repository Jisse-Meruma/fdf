/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:17:43 by jmeruma           #+#    #+#             */
/*   Updated: 2022/12/06 12:53:43 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int ft_ternary(int statement, int true_out, int false_out)
{
	if (statement)
		return (true_out);
	return (false_out);
}

int ft_abs(int diff)
{
	if (diff < 0)
		return (diff *= -1);
	return (diff);
}
// void	line_bottem_left(t_map *grid, int index, int xd, int zd)
// {
// 	int a;
// 	int b;
// 	int p;
// 	int x;
// 	int z;

// 	x = grid->grid[index].x_axis;
// 	z = grid->grid[index].z_axis;
// 	a = 2 * zd;
// 	b = a - 2 * xd;
// 	p = a - xd;
// 	while (x >= grid->grid[index + grid->row + 1].x_axis)
// 	{
// 		if (x + 400 >= 0 && x + 400 < WIDTH && z < HEIGHT && z + 200 >= 0)
// 			mlx_put_pixel(grid->img, x + 400, z + 200, 0xFFFFFFFF);
// 		x--;
// 		if (p < 0)
// 			p += a;
// 		else
// 		{
// 			z++;
// 			p += b;
// 		}
// 	}
// }
t_draw	draw_init(t_point p0, t_point p1)
{  
	t_draw draw;
	
	draw.sign_x = ft_ternary(p0.x_axis < p1.x_axis, 1, -1);
	draw.sign_y = ft_ternary(p0.z_axis < p1.z_axis, 1, -1);
	draw.dx = ft_abs(p1.x_axis - p0.x_axis);
	draw.dz = ft_abs(p1.z_axis - p0.z_axis);
	draw.err = ft_ternary(draw.dx > draw.dz, draw.dx, -draw.dz) / 2;
	return (draw);
}
void line_draw(t_map *grid, t_point p0, t_point p1)
{
	int errtemp;
	t_draw draw;

	draw = draw_init(p0, p1);
	while (1)
	{
		if ((p0.x_axis + 900 < WIDTH && p0.x_axis + 900 > 0) 
			&& (p0.z_axis + 0 < HEIGHT && p0.z_axis + 0 > 0))
				mlx_put_pixel(grid->img, p0.x_axis + 900, p0.z_axis + 0, 0xFFFFFFFF);
		if (p0.x_axis == p1.x_axis && p0.z_axis == p1.z_axis)
			break ;
		errtemp = draw.err;
		if (errtemp > -draw.dx)	
		{
			draw.err -= draw.dz;
			p0.x_axis += draw.sign_x;
		}
		if (errtemp < draw.dz)	
		{
			draw.err += draw.dx;
			p0.z_axis += draw.sign_y;
		}
	}
}
// void	line_bottem_right(t_map *grid, int index, int xd, int zd)
// {
// 	int a;
// 	int b;
// 	int p;
// 	int x;
// 	int z;

// 	x = grid->grid[index].x_axis;
// 	z = grid->grid[index].z_axis;
// 	a = 2 * zd;
// 	b = a - 2 * xd;
// 	p = a - xd;
// 	while (x <= grid->grid[index + 1].x_axis)
// 	{
// 		if (x + 400 >= 0 && x + 400 < WIDTH && z < HEIGHT && z + 200 >= 0)
// 			mlx_put_pixel(grid->img, x + 400, z + 200, 0xFFFFFFFF);
// 		x++;
// 		if (p < 0)
// 			p += a;
// 		else
// 		{
// 			z++;
// 			p += b;
// 		}
// 	}	
// }
// void	line_upper_right(t_map grid, int index)
// {
// 	int a;
// 	int b;
// 	int p;

// 	a = 2 * grid.grid[index + 1].z_axis - grid.grid[index].z_axis;
// 	b = a - 2 * grid.grid[index + 1].x_axis - grid.grid[index].x_axis;
// 	p = a - grid.grid[index + 1].x_axis - grid.grid[index].x_axis;
// 	while (grid.grid[index].x_axis < grid.grid[index + 1].x_axis)
// 	{
// 		mlx_put_pixel(grid.img, grid.grid[index].x_axis, grid.grid[index].z_axis, 0xFFFFFFFF);
// 		grid.grid[index].x_axis++;
// 		if (p < 0)
// 			p += a;
// 		else
// 		{
// 			grid.grid[index].z_axis--;
// 			p += b;
// 		}
// 	}
// }
