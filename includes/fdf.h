/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:11:08 by jmeruma           #+#    #+#             */
/*   Updated: 2022/11/24 16:37:20 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"

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
	int		row;
	int		collum;
	int		total_points;
	t_point	*grid;
}	t_map;

int			map_validity(char *argv[]);
void		map_creation(int fd, t_map *map);
void		ft_point_addback(t_lstpoint **lst, t_lstpoint *new);

int32_t		mlx(t_map *map);

#endif