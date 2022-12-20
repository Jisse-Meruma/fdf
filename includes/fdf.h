/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:11:08 by jmeruma           #+#    #+#             */
/*   Updated: 2022/12/20 14:09:18 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <string.h>
# include <errno.h> 
# include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1080
# define BPP sizeof(int32_t)
# define STD_SCALE 30

typedef struct s_point
{
	int				x_map;
	int				y_map;
	int				z_map;
	int				x_grid;
	int				y_grid;
	uint32_t		col;
}	t_point;

typedef struct s_draw
{
	int x_axis;
	int y_axis;
	int sign_x;
	int sign_y;
	int dx;
	int dz;
	int err;
}	t_draw;

typedef struct s_link
{
	int				x_axis;
	int				y_axis;
	int				z_axis;
	uint32_t		col;
	struct s_link	*next;
}	t_lstpoint;

typedef struct s_camera
{
	int		x_offset;
	int		y_offset;
	int		height_offset;
}	t_camera;

typedef struct s_map
{
	int			row;
	int			collum;
	int			total_points;
	int			scale;
	mlx_image_t *img;
	mlx_t 		*mlx;
	t_point		*grid;
	t_lstpoint	**list;
	t_camera	cam;
}	t_map;

int			map_validity(char *argv[]);
void		map_creation(int fd, t_map *map);
t_lstpoint	*ft_point_addback(t_lstpoint **lst, t_lstpoint *new, t_lstpoint *old_node);

void 		cleanerror(int	error_code, t_map *map);
void		cleanup(t_map *map);
void		free_split(char **points);
void		free_split_exit(t_map *map, char **points);

void		line_draw(t_map *grid, t_point p0, t_point p1);
void		draw_grid(t_map *grid);
uint32_t	color_grad(t_point p0, t_point p1, t_draw draw);

int32_t		mlx(t_map *map);
void		map_key_hook(void *param);
void		matrix(t_map *grid);

#endif
