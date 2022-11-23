/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:11:08 by jmeruma           #+#    #+#             */
/*   Updated: 2022/11/23 17:41:09 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>

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
	t_point	*grid;
}	t_map;

int			map_validity(char *argv[]);
t_lstpoint	**map_creation(int fd, t_map *map);
void		ft_point_addback(t_lstpoint **lst, t_lstpoint *new);

#endif