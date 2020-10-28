/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:43:44 by dbliss            #+#    #+#             */
/*   Updated: 2020/10/28 14:24:20 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fix_angle(float *angle)
{
	if (*angle < 0)
		*angle += 2 * M_PI;
	if (*angle > 2 * M_PI)
		*angle -= 2 * M_PI;
}

void	calculate_wall(t_all *all, int i)
{
	all->pl.wall_size[i] = ceil((SCALE / all->cross.right_dist)
			* all->pl.dist);
	all->pl.ceiling[i] = (all->map.s_height / 2) - (all->pl.wall_size[i] / 2);
}

void	find_wall(t_all *all)
{
	if (all->pl.fov_start >= 0 && all->pl.fov_start <= M_PI)
	{
		if (all->cross.hit == 0)
		{
			if (all->pl.fov_start >= 0 && all->pl.fov_start <= M_PI_2)
				all->cross.hit_side = east;
			else
				all->cross.hit_side = west;
		}
		else
			all->cross.hit_side = north;
	}
	else
	{
		if (all->cross.hit == 0)
		{
			if (all->pl.fov_start > M_PI && all->pl.fov_start < 3 * M_PI_2)
				all->cross.hit_side = west;
			else
				all->cross.hit_side = east;
		}
		else
			all->cross.hit_side = south;
	}
}
