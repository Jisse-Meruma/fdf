/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:11:08 by jmeruma           #+#    #+#             */
/*   Updated: 2022/11/21 15:39:49 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>

typedef struct s_list
{
	int 			x_axis;
	int 			y_axis;
	int 			z_axis;
	struct s_list	*next;
}	t_list;

int	map_validity(char *argv[]);

#endif