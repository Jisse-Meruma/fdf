/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:11:08 by jmeruma           #+#    #+#             */
/*   Updated: 2022/12/01 12:01:10 by jmeruma          ###   ########.fr       */
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

# define WIDTH 1024
# define HEIGHT 1024
# define BPP sizeof(int32_t)

typedef struct s_point
{
	int				x_axis;
	int				y_axis;
	int				z_axis;
}	t_point;
typedef struct s_link
{
	int				x_axis;
	int				y_axis;
	int				z_axis;
	struct s_link	*next;
}	t_lstpoint;

typedef struct s_map
{
	int			offset_x;
	int			offset_z;
	int			row;
	int			collum;
	int			total_points;
	mlx_image_t *img;
	mlx_t 		*mlx;
	t_point		*grid;
}	t_map;

int			map_validity(char *argv[]);
void		map_creation(int fd, t_map *map);
void		ft_point_addback(t_lstpoint **lst, t_lstpoint *new);

void		line_bottem_left(t_map *grid, int index, int xd, int zd);
void		line_upper_left(t_map grid, int index);
void		line_bottem_right(t_map *grid, int index, int xd, int zd);
void		line_upper_right(t_map grid, int index);

int32_t		mlx(t_map *map);
void		matrix(t_map *grid);

#endif
