/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:58:06 by jmeruma           #+#    #+#             */
/*   Updated: 2022/12/06 15:19:15 by jmeruma          ###   ########.fr       */
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
	int	temp;
	int	index;
	int	scale;

	scale = 10;
	index = 0;
	while (index <= grid->total_points)
	{
		temp = grid->grid[index].x_axis;
		grid->grid[index].x_axis = (grid->grid[index].x_axis
				- grid->grid[index].z_axis) * (scale);
		grid->grid[index].z_axis = (grid->grid[index].z_axis + temp
				- grid->grid[index].y_axis) * (scale / 2);
		index++;
	}
	draw_grid(grid);
}
