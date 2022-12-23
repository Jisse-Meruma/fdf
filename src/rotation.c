/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:17:15 by jmeruma           #+#    #+#             */
/*   Updated: 2022/12/23 16:38:00 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation_x(double rotate_x, t_point *point, t_camera *cam)
{
	cam->r_y = point->y_map * cos(rotate_x) - point->z_map * sin(rotate_x);
	cam->r_z = point->y_map * sin(rotate_x) + point->z_map * cos(rotate_x);
}
void	rotation_y(double rotate_y, t_point *point, t_camera *cam)
{
	cam->r_x = point->x_map * cos(rotate_y) + point->z_map * sin(rotate_y);
	cam->r_z = point->x_map * -sin(rotate_y) + point->z_map * cos(rotate_y);
}
void	rotation_z(double rotate_z, t_point *point, t_camera *cam)
{
	cam->r_x = point->x_map * cos(rotate_z) - point->y_map * sin(rotate_z);
	cam->r_y = point->x_map * sin(rotate_z) + point->y_map * cos(rotate_z);	
}

void	rotation(t_map *map, int index)
{
	t_map	scale_map;

	scale_map = *map;
	scale_map.grid[index].x_map *= map->scale;
	scale_map.grid[index].y_map *= map->scale;
	scale_map.grid[index].z_map *= map->scale;
	rotation_x(map->cam.rotate_x, &scale_map.grid[index], &map->cam);
	rotation_y(map->cam.rotate_y, &scale_map.grid[index], &map->cam);
	rotation_z(map->cam.rotate_z, &scale_map.grid[index], &map->cam);
}	