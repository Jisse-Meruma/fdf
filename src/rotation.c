/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:17:15 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/09 15:14:08 by jmeruma          ###   ########.fr       */
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

void	rotation(t_point *point, t_map *map)
{
	t_point	scale_point;
                 
	scale_point = *point;
	scale_point.x_map = (scale_point.x_map - (map->collum / 2)) * map->scale;
	scale_point.y_map = (scale_point.y_map - (map->collum / 2)) * map->scale;
	scale_point.z_map = (scale_point.z_map - (map->collum / 2)) * map->scale;
	rotation_x(map->cam.rotate_x, &scale_point, &map->cam);
	rotation_y(map->cam.rotate_y, &scale_point, &map->cam);
}
