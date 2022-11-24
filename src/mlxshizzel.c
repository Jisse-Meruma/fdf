/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxshizzel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:55:38 by jmeruma           #+#    #+#             */
/*   Updated: 2022/11/24 16:46:08 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int	render_background(mlx_t *mlx)
{
	int x;
	int y;
	mlx_image_t* img;
	
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

int	render_grid(t_map *map, mlx_t *mlx)
{
	int x;
	int y;
	mlx_image_t* img2;
	
	x = 0;
	y = 0;
	img2 = mlx_new_image(mlx, map->row, map->collum);
	while (y < map->collum)
	{
		while(x < map->row)
		{
			mlx_put_pixel(img2, x, y, 0xFFFFFFFF);
			x++;
		}
		x = 0;
		y += 10;
	}
	if (!img2 || (mlx_image_to_window(mlx, img2, 25, 0) < 0))
		return (1);
	return (0);
}

int32_t	mlx(t_map *map)
{
	mlx_t* mlx;
	
	
	mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!mlx)
		return (1);
	render_background(mlx);
	render_grid(map, mlx);
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
