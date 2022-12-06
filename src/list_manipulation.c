/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:55:24 by jmeruma           #+#    #+#             */
/*   Updated: 2022/12/06 15:10:16 by jmeruma          ###   ########.fr       */
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
