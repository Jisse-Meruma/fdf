/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisse <jisse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:29:31 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/03 21:08:09 by jisse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	free_split(char **points)
{
	int	i;

	i = 0;
	while (points[i])
	{
		free(points[i]);
		i++;
	}
	free(points);
}

void	ft_lstpointclear(t_lstpoint **lst)
{
	t_lstpoint	*node;
	t_lstpoint	*nfree;

	node = *lst;
	while (node)
	{
		nfree = node->next;
		free(node);
		node = nfree;
	}
	*lst = NULL;
}

void	cleanerror(int error_code, t_map *map)
{
	if (error_code == 1)
		ft_lstpointclear(map->list);
	if (error_code > 2)
		free(map->grid);
	if (error_code > 3)
		mlx_delete_image(map->mlx, map->img);
	free(map);
	exit(error_code);
}

void	cleanup(t_map *map)
{
	free(map->grid);
	free(map);
}

void	free_split_exit(t_map *map, char **points)
{
	free_split(points);
	cleanerror(2, map);
}
