/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:58:06 by jmeruma           #+#    #+#             */
/*   Updated: 2022/12/01 11:50:56 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	render_grid(t_map *grid)
// {
// 	int i;

// 	i = 0;
// 	while (index <= grid->total_points)
// 	{
// 		grid->offset_x = grid->grid[i + 1].x_axis - grid->grid[i].x_axis;
// 		grid->offset_z = grid->grid[i + 1].z_axis - grid->grid[i].z_axis;
// 		grid->offset_z -= grid->grid[i + 1].y_axis; - grid->grid[i].y_axis;
// 		if (grid->offset_x > grid->offset_z)
// 			line_bottem_right(*grid, i);
// 		else	
// 	}
// }

void	draw_grid(t_map *grid)
{
	int xd;
	int zd;
	int index;

	index = 0;
	while(index < grid->total_points)
	{
		if (index % grid->row != 0)
		{
			xd = grid->grid[index + 1].x_axis - grid->grid[index].x_axis;
			zd = grid->grid[index + 1].z_axis - grid->grid[index].z_axis;
		}
		line_bottem_right(grid, index, xd, zd);
		if (index + grid->row < grid->total_points)
		{
			
			xd = grid->grid[index].x_axis - grid->grid[index + grid->row + 1].x_axis; 
			zd = grid->grid[index + grid->row + 1].z_axis - grid->grid[index].z_axis;
			line_bottem_left(grid, index, xd, zd);
		}
		index++;
	}
}

void	matrix(t_map *grid)
{
	int temp;
	int index;
	int scale;

	
	scale = 40;
	index = 0;
	while (index <= grid->total_points)
	{
		temp = grid->grid[index].x_axis;
		grid->grid[index].x_axis = (grid->grid[index].x_axis - grid->grid[index].z_axis) * (scale);
		grid->grid[index].z_axis = (grid->grid[index].z_axis + temp) * (scale / 2);
		index++;
	}
	draw_grid(grid);
}
