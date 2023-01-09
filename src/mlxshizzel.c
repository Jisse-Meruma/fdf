/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxshizzel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:55:38 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/09 15:32:00 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int	render_background(mlx_t *mlx)
{
	int			x;
	int			y;
	mlx_image_t	*img;

	x = 0;
	y = 0;
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			mlx_put_pixel(img, x, y, 0x0000000FF);
			x++;
		}
		x = 0;
		y++;
	}
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		return (1);
	return (0);
}

int32_t	mlx(t_map *map)
{
	map->mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!map->mlx)
		cleanerror(3, map);
	map->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	if (!map->img)
		cleanerror(3, map);
	if (map->total_points < 10000)
		map->scale = STD_SCALE;
	else
		map->scale = 3;
	if (render_background(map->mlx) != 0)
		cleanerror(4, map);
	matrix(map);
	draw_grid(map);
	if (mlx_image_to_window(map->mlx, map->img, 0, 0) == -1)
		cleanerror(4, map);
	mlx_loop_hook(map->mlx, &map_key_hook, map);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
	return (0);
}
