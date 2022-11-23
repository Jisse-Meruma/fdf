/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:25:35 by jmeruma           #+#    #+#             */
/*   Updated: 2022/11/23 17:31:31 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fdf.h>

int	main(int argc, char *argv[])
{
	int			fd;
	t_map		*map;
	t_lstpoint	**list;

	if (argc != 2)
		return (perror("argc"), 1);
	fd = map_validity(argv);
	if (fd == -1)
		return (perror("map invalid"), 1);
	map = ft_calloc(1, sizeof(t_map));
	list = map_creation(fd, map);
}
