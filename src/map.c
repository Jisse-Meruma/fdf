/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:35:16 by jmeruma           #+#    #+#             */
/*   Updated: 2022/11/22 16:19:23 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h> 
#include <fdf.h>

int	map_validity(char *argv[])
{
	int		fd;
	char	*check;

	check = ft_strnstr(argv[1], ".fdf", (ft_strlen(argv[1])));
	if (!check || ft_strlen(check) != 4)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (-1);
	return (fd);
}

void	list_creation(char **points, int z_axis, t_point **list)
{
	int		i;
	t_point	*point;

	i = 0;
	while (points[i] != '\0' && points[i][0] != '\n')
	{
		point = (t_point *)ft_calloc(1, sizeof(t_point));
		if (!point)
			return (perror("point"));
		ft_point_addback(list, point);
		point->z_axis = z_axis;
		point->y_axis = ft_atoi(points[i]);
		point->x_axis = i;
		i++;
	}
}

t_point	**map_creation(int fd)
{
	t_point	**list;
	int		z_axis;
	char	*line;
	char	**points;

	z_axis = 0;
	list = (t_point **)ft_calloc(1, sizeof(t_point *));
	if (!list)
		return (perror("list"), NULL);
	line = get_next_line(fd);
	while (line)
	{
		/*make sure to free split*/
		points = ft_split(line, ' ');
		list_creation(points, z_axis, list);
		line = get_next_line(fd);
		z_axis++;
	}
	return (list);
}
