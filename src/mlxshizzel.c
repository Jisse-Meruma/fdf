/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxshizzel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:55:38 by jmeruma           #+#    #+#             */
/*   Updated: 2022/11/30 16:46:31 by jmeruma          ###   ########.fr       */
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

// int	render_grid(t_map *map, mlx_t *mlx)
// {
// 	int x;
// 	int y;
// 	int xd;
// 	int yd;
// 	int a;
// 	int b;
// 	int p;
// 	mlx_image_t* img2;
	
// 	x = 160;
// 	y = 160;
// 	xd = 300 + x;
// 	yd = 60 + y;
// 	a = 2 * yd;
// 	b = a - 2 * xd;
// 	p = a - xd;
// 	img2 = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	while (x < xd && y < yd && x > 1)
// 	{
// 		if (p < 0)
// 		{
// 			x--;
// 			mlx_put_pixel(img2, x, y, 0xFFFFFFFF);
// 			p += a;
// 		}
// 		if (p >= 0)
// 		{
// 			x--;
// 			y++;
// 			mlx_put_pixel(img2, x, y, 0xFFFFFFFF);
// 			p += b;
// 		}
// 	}
	
// 	x = 160;
// 	y = 160;
// 	mlx_put_pixel(img2, x, y, 0xFFFFFFFF);
// 	p = a - xd;
// 	while (x < xd && y < yd)
// 	{
// 		if (p < 0)
// 		{
// 			x++;
// 			mlx_put_pixel(img2, x, y, 0xFFFFFFFF);
// 			p += a;
// 		}
// 		if (p >= 0)
// 		{
// 			x++;
// 			y++;
// 			mlx_put_pixel(img2, x, y, 0xFFFFFFFF);
// 			p += b;
// 		}
// 	}
// }

int32_t	mlx(t_map *map)
{
	mlx_t *mlx;
	mlx_image_t *img;
	
	mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	map->img = mlx_new_image(mlx, WIDTH + 200, HEIGHT+200);
	render_background(mlx);
	matrix(map);
	mlx_image_to_window(mlx, map->img, 0, 0);
	//render_grid(map, mlx);
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
