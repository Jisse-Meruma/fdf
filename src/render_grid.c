/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:58:06 by jmeruma           #+#    #+#             */
/*   Updated: 2022/12/15 17:54:19 by jmeruma          ###   ########.fr       */
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

void	matrix(t_map *grid)
{
	int	index;

	index = 0;
	while (index <= grid->total_points)
	{
		grid->grid[index].x_grid = (grid->grid[index].x_map
				- grid->grid[index].z_map) * (grid->scale);
		grid->grid[index].y_grid = (grid->grid[index].z_map 
				+ grid->grid[index].x_map
				- grid->grid[index].y_map) * (grid->scale / 2);
		grid->grid[index].x_grid += grid->cam.x_offset;
		grid->grid[index].y_grid += grid->cam.y_offset;
		if (grid->grid[index].y_map != 0)
			grid->grid[index].y_grid += grid->cam.height_offset * grid->grid[index].y_map;
		index++;
	}
}
