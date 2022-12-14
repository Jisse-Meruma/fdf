/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:25:35 by jmeruma           #+#    #+#             */
/*   Updated: 2022/12/14 11:38:06 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fdf.h>

int	main(int argc, char *argv[])
{
	int			fd;
	t_map		*map;

	if (argc != 2)
		return (perror("argc"), 1);
	fd = map_validity(argv);
	if (fd == -1)
		return (perror("map invalid"), 1);
	map = ft_calloc(1, sizeof(t_map));
	map->cam = ft_calloc(1, sizeof(t_camera));
	map_creation(fd, map);
	mlx(map);
	cleanup(map);
	system("leaks fdf");
	return (EXIT_SUCCESS);
}
