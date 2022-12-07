/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:11:14 by jmeruma           #+#    #+#             */
/*   Updated: 2022/12/07 16:49:03 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

float	percent(t_point p0, t_draw draw)
{
	return (( draw.x_axis / p0.x_axis) * 100);
}

uint32_t	color_grad(t_point p0, t_point p1, t_draw draw)
{
	int			color_sign;
	uint32_t	color_diff;

	color_sign = 0;
	if (p0.col == p1.col || p0.x_axis == 0 || p1.x_axis == 0)
		return (p0.col * 16 * 16 + 255);
	if (p0.col < p1.col)
	{
		color_sign = 1;
		color_diff = p1.col - p0.col;
	}
	else 
		color_diff = p0.col - p1.col;
	if (color_sign == 1)
	{
		p1.col = p1.col + color_diff * percent(p0, draw);
		return (p1.col * 16 * 16 + 255);
	}
	else
	{
		p0.col = p0.col + color_diff * percent(p1, draw);
		return(p0.col * 16 * 16 + 255);
	}
}	
