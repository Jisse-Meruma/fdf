/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:17:43 by jmeruma           #+#    #+#             */
/*   Updated: 2022/12/01 11:50:05 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_bottem_left(t_map *grid, int index, int xd, int zd)
{
	int a;
	int b;
	int p;
	int x;
	int z;

	x = grid->grid[index].x_axis;
	z = grid->grid[index].z_axis;
	a = 2 * zd;
	b = a - 2 * xd;
	p = a - xd;
	while (x >= grid->grid[index + grid->row + 1].x_axis)
	{
		if (x + 400 >= 0 && x + 400 < WIDTH && z < HEIGHT )
			mlx_put_pixel(grid->img, x + 400, z, 0xFFFFFFFF);
		else 
			break;
		x--;
		if (p < 0)
			p += a;
		else
		{
			z++;
			p += b;
		}
	}
}
// void	line_upper_left(t_map grid, int index)
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
// 		grid.grid[index].x_axis--;
// 		if (p < 0)
// 			p += a;
// 		else
// 		{
// 			grid.grid[index].z_axis--;
// 			p += b;
// 		}
// 	}
// }
void	line_bottem_right(t_map *grid, int index, int xd, int zd)
{
	int a;
	int b;
	int p;
	int x;
	int z;

	x = grid->grid[index].x_axis;
	z = grid->grid[index].z_axis;
	a = 2 * zd;
	b = a - 2 * xd;
	p = a - xd;
	while (x <= grid->grid[index + 1].x_axis)
	{
		if (x + 400 >= 0 && x + 400 < WIDTH && z < HEIGHT )
			mlx_put_pixel(grid->img, x + 400, z, 0xFFFFFFFF);
		x++;
		if (p < 0)
			p += a;
		else
		{
			z++;
			p += b;
		}
	}
}
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
