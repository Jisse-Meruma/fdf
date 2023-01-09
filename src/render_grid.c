/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:58:06 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/09 17:44:26 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_grid(t_map *grid)
{
	int	index;

	index = 0;
	while (index < grid->total_points)
	{
		if (!(index % grid->row == grid->row - 1))
		{
			line_draw(grid, grid->grid[index], grid->grid[index + 1]);
		}
		if (index + grid->row < grid->total_points)
		{
			line_draw(grid, grid->grid[index],
				grid->grid[index + grid->row]);
		}
		index++;
	}
}

void	draw_reverse_grid(t_map *grid)
{
	int	index;

	index = grid->total_points - 1;
	while (0 <= index)
	{
		if (!(index % grid->row == 0))
		{
			line_draw(grid, grid->grid[index], grid->grid[index - 1]);
		}
		if (index >= grid->row)
		{
			line_draw(grid, grid->grid[index],
				grid->grid[index - grid->row]);
		}
		index--;
	}
}

void	isometric(t_map *grid, int index)
{
	grid->grid[index].x_grid = (grid->cam.r_x
			- grid->cam.r_z);
	grid->grid[index].y_grid = (grid->cam.r_x
			+ grid->cam.r_z
			- grid->cam.r_y) / 2;
	if (grid->grid[index].y_map != 0)
		grid->grid[index].y_grid += grid->cam.height_offset
			* grid->grid[index].y_map;
}

void	parallel(t_map *grid, int index)
{
	grid->grid[index].x_grid = grid->cam.r_x;
	grid->grid[index].y_grid = grid->cam.r_z;
}

void	matrix(t_map *grid)
{
	int	index;
	int temp;

	index = 0;
	while (index < grid->total_points)
	{
		rotation(&grid->grid[index], grid);
		if (grid->cam.projection == 0)
			isometric(grid, index);
		if (grid->cam.projection == 1)
			parallel(grid, index);
			grid->grid[index].x_grid += WIDTH / 2;
		if (grid->total_points < 10000)
			grid->grid[index].y_grid += HEIGHT / 2;
		grid->grid[index].x_grid += grid->cam.x_offset;
		grid->grid[index].y_grid += grid->cam.y_offset;
 		index++;
	}
}
