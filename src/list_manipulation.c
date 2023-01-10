/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:55:24 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/10 12:02:59 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fdf.h>

t_lstpoint	*ft_point_addback(t_lstpoint **lst,
	t_lstpoint *new, t_lstpoint *old_node)
{
	if (*lst == NULL)
		*lst = new;
	if (lst == NULL || new == NULL)
		return (NULL);
	if (old_node != NULL)
		old_node->next = new;
	return (new);
}

int	out_of_bounds(t_point p0, t_point p1)
{
	if ((p0.y_grid > HEIGHT && p1.y_grid < HEIGHT)
		|| (p0.y_grid < 0 && p1.y_grid > 0))
		return (1);
	else
		return (0);
}
