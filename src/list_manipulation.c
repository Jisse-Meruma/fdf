/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:55:24 by jmeruma           #+#    #+#             */
/*   Updated: 2022/11/22 16:16:50 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fdf.h>

static t_point	*ft_lstlast(t_point *lst)
{
	if (lst == NULL)
		return (NULL);
	if (lst->next == NULL)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_point_addback(t_point **lst, t_point *new)
{
	t_point	*node;

	node = *lst;
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	node = ft_lstlast(*lst);
	node->next = new;
}
