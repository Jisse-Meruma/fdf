/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxshizzel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:55:38 by jmeruma           #+#    #+#             */
/*   Updated: 2022/12/06 15:19:37 by jmeruma          ###   ########.fr       */
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
	mlx_t		*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	map->img = mlx_new_image(mlx, WIDTH + 200, HEIGHT + 200);
	render_background(mlx);
	matrix(map);
	mlx_image_to_window(mlx, map->img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
