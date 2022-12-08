/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisse <jisse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:35:16 by jmeruma           #+#    #+#             */
/*   Updated: 2022/12/08 17:54:40 by jisse            ###   ########.fr       */
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
	map->collum = cur->z_axis + 1;
	map->row = cur->x_axis + 1;
	map->grid = malloc(map->collum * map->row * sizeof(t_point));
	while (lst)
	{
		map->grid[index].x_axis = lst->x_axis;
		map->grid[index].y_axis = lst->y_axis;
		map->grid[index].z_axis = lst->z_axis;
		map->grid[index].col = lst->col;
		cur = lst;
		lst = lst->next;
		free(cur);
		index++;
	}
	map->total_points = (map->collum * map->row);
}

int	map_validity(char *argv[])
{
	int		fd;
	int		check;

	check = ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".fdf", 5);
	if (check)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (-1);
	return (fd);
}

t_lstpoint	*linked_list_creation(char **points, int z_axis,
	t_lstpoint **list, t_lstpoint *old_point)
{
	int			i;
	char		*color;
	t_lstpoint	*point;

	i = 0;
	while (points[i] && points[i][0] != '\n')
	{
		point = (t_lstpoint *)ft_calloc(1, sizeof(t_lstpoint));
		if (!point)
			return (perror("point"), NULL);
		old_point = ft_point_addback(list, point, old_point);
		point->z_axis = z_axis;
		point->y_axis = ft_atoi(points[i]);
		point->x_axis = i;
		color = ft_strchr(points[i], ',');
		if (color)
			point->col = ft_atohex(ft_strjoin(color, "00") + 3);
		else 
			point->col = 0xFFFFFF00;
		i++;
	}
	return (old_point);
}

/*make sure to free split */
void	map_creation(int fd, t_map *map)
{
	int			z_axis;
	char		*line;
	char		**points;
	t_lstpoint	**list;
	t_lstpoint	*old_point;

	z_axis = 0;
	old_point = NULL;
	list = (t_lstpoint **)ft_calloc(1, sizeof(t_lstpoint *));
	if (!list)
		return (perror("list"));
	line = get_next_line(fd);
	while (line)
	{
		points = ft_split(line, ' ');
		old_point = linked_list_creation(points, z_axis, list, old_point);
		line = get_next_line(fd);
		z_axis++;
	}
	struct_array_creation(*list, map);
	free(list);
}
