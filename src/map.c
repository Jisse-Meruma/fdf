/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:35:16 by jmeruma           #+#    #+#             */
/*   Updated: 2022/11/30 12:23:54 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h> 
#include <fdf.h>

void	struct_array_creation(t_lstpoint *lst, t_map *map)
{
	int			index;
	t_lstpoint	*cur;

	index = 0;
	cur = lst;
	while (cur->next)
		cur = cur->next;
	map->grid = malloc((cur->x_axis + 1) *(cur->z_axis + 1) * sizeof(t_point));
	map->collum = cur->z_axis;
	map->row = cur->x_axis;
	while (lst->next)
	{
		map->grid[index].x_axis = lst->x_axis;
		map->grid[index].y_axis = lst->y_axis;
		map->grid[index].z_axis = lst->z_axis;
		cur = lst;
		lst = lst->next;
		free(cur);
		index++;
	}
	map->grid[index].x_axis = lst->x_axis;
	map->grid[index].y_axis = lst->y_axis;
	map->grid[index].z_axis = lst->z_axis;
	map->total_points = (((lst->x_axis + 1) *(lst->z_axis + 1)) - 1);
}

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

void	linked_list_creation(char **points, int z_axis, t_lstpoint **list)
{
	int			i;
	t_lstpoint	*point;

	i = 0;
	while (points[i] != '\0' && points[i][0] != '\n')
	{
		point = (t_lstpoint *)ft_calloc(1, sizeof(t_lstpoint));
		if (!point)
			return (perror("point"));
		ft_point_addback(list, point);
		point->z_axis = z_axis;
		point->y_axis = ft_atoi(points[i]);
		point->x_axis = i;
		i++;
	}
}

void	map_creation(int fd, t_map *map)
{
	t_lstpoint	**list;
	int			z_axis;
	char		*line;
	char		**points;

	z_axis = 0;
	list = (t_lstpoint **)ft_calloc(1, sizeof(t_lstpoint *));
	// if (!list)
	// 	//return (perror("list"), NULL);
	line = get_next_line(fd);
	while (line)
	{
		//make sure to free split 
		points = ft_split(line, ' ');
		linked_list_creation(points, z_axis, list);
		line = get_next_line(fd);
		z_axis++;
	}
	struct_array_creation(*list, map);
	free(list);
}
