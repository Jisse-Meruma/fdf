/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxshizzel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:55:38 by jmeruma           #+#    #+#             */
/*   Updated: 2022/12/15 17:53:32 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	reset_grid(t_map *map, t_map *oldmap)
{
	if (map->scale != oldmap->scale || ft_memcmp(&(map->cam), &(oldmap->cam), sizeof(t_camera)) != 0)
	{	
		ft_bzero(map->img->pixels, WIDTH * HEIGHT * BPP);
		matrix(map);
		draw_grid(map);
	}
}

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



void	my_key_hook(void *param)
{
	t_map	*map;
	t_map	oldmap;

	map = param;
	oldmap = *((t_map*)param);
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	if (mlx_is_key_down(map->mlx, MLX_KEY_UP))
		map->cam.y_offset -= 20;
	if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
		map->cam.y_offset += 20;
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
		map->cam.x_offset -= 20;
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
		map->cam.x_offset += 20;
	if (mlx_is_key_down(map->mlx, MLX_KEY_KP_ADD))
		map->scale++;
	if (mlx_is_key_down(map->mlx, MLX_KEY_KP_SUBTRACT))
		map->scale--;
	if (mlx_is_key_down(map->mlx, MLX_KEY_EQUAL))
		map->cam.height_offset--;
	if (mlx_is_key_down(map->mlx, MLX_KEY_MINUS))
		map->cam.height_offset++;
	reset_grid(map, &oldmap);
}

int32_t	mlx(t_map *map)
{
	map->mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!map->mlx)
		cleanerror(3, map);
	map->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	if (!map->img)
		cleanerror(3, map);
	map->scale = STD_SCALE;
	if (render_background(map->mlx) != 0)
		cleanerror(4, map);
	matrix(map);
	draw_grid(map);
	if (mlx_image_to_window(map->mlx, map->img, 0, 0) == -1)
		cleanerror(4, map);
	mlx_loop_hook(map->mlx, &my_key_hook, map);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
	return (0);
}
