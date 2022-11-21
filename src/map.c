/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:35:16 by jmeruma           #+#    #+#             */
/*   Updated: 2022/11/21 17:02:10 by jmeruma          ###   ########.fr       */
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

char *map_creation(int fd)
{
	int		z_axis;
	char	*line;
	char	**points;

	line = get_next_line(fd);
	while (line)
	{
		points = ft_split(line, ' ');
		
		line = get_next_line(fd);
		z_axis++;
	}
		
}

char *list_creation(char *points, int z_axis)
{
	t_list *head;

	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->z_axis = z_axis;

}

