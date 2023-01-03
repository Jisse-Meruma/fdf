/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisse <jisse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:35:16 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/03 21:05:39 by jisse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h> 
#include <fdf.h>

uint32_t	color_create(char **points, int i)
{
	int			red;
	int			green;
	int			blue;
	char		*str_color;
	uint32_t	color;

	str_color = ft_strchr(points[i], ',');
	if (str_color)
	{
		color = ft_atohex(str_color + 3);
		red = ((color >> 16) & 0xFF);
		green = ((color >> 8) & 0xFF);
		blue = (color & 0xFF);
		color = rgb_combine(red, green, blue) | 0xFF;
		return (color);
	}	
	else
		return (0xFFFFFFFF);
}

void	struct_array_creation(t_lstpoint *lst, t_map *map)
{
	int			index;
	t_lstpoint	*cur;

	index = 0;
	map->collum++;
	map->row++;
	map->grid = ft_calloc(map->collum * map->row, sizeof(t_point));
	if (!map->grid)
		cleanerror(2, map);
	while (lst)
	{
		map->grid[index].x_map = lst->x_axis;
		map->grid[index].y_map = lst->y_axis;
		map->grid[index].z_map = lst->z_axis;
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
	t_map *map, t_lstpoint *old_point)
{
	int			i;
	t_lstpoint	*point;

	i = 0;
	while (points[i] && points[i][0] != '\n')
	{
		point = (t_lstpoint *)ft_calloc(1, sizeof(t_lstpoint));
		if (!point)
			free_split_exit(map, points);
		old_point = ft_point_addback(map->list, point, old_point);
		point->z_axis = z_axis;
		point->y_axis = ft_atoi(points[i]);
		point->x_axis = i;
		point->col = color_create(points, i);
		if (map->row < i)
			map->row = i;
		if (map->collum < z_axis)
			map->collum = z_axis;
		if (point->col == 0)
			cleanerror(2, map);
		if (map->collum < z_axis)
			map->collum = z_axis;
		if (map->row < i)
			map->row = i;
		i++;
	}
	return (old_point);
}

void	map_creation(int fd, t_map *map)
{
	int			z_axis;
	char		*line;
	char		**points;
	t_lstpoint	*old_point;

	z_axis = 0;
	old_point = NULL;
	map->list = (t_lstpoint **)ft_calloc(1, sizeof(t_lstpoint *));
	if (!map->list)
		cleanerror(1, map);
	line = get_next_line(fd);
	while (line)
	{
		points = ft_split(line, ' ');
		free(line);
		if (!points)
			cleanerror(1, map);
		old_point = linked_list_creation(points, z_axis, map, old_point);
		free_split(points);
		line = get_next_line(fd);
		z_axis++;
	}
	struct_array_creation(*map->list, map);
	free(map->list);
}
