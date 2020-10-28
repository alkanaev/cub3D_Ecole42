/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_cross.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:35:36 by dbliss            #+#    #+#             */
/*   Updated: 2020/10/28 21:37:24 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	horizontal_cross(t_all *all)
{
	if (all->pl.fov_start > 0 && all->pl.fov_start < M_PI)
	{
		all->cross.hy = (int)(all->pl.y / SCALE) * SCALE - 0.001;
		all->cross.h_dy = -SCALE;
		all->cross.hx = all->pl.x + (all->pl.y - all->cross.hy)
			/ tan(all->pl.fov_start);
		all->cross.h_dx = SCALE / tan(all->pl.fov_start);
	}
	else
	{
		all->cross.hy = (int)(all->pl.y / SCALE) * SCALE + SCALE;
		all->cross.h_dy = SCALE;
		all->cross.hx = all->pl.x + (all->pl.y - all->cross.hy) /
			tan(all->pl.fov_start);
		all->cross.h_dx = -SCALE / tan(all->pl.fov_start);
	}
}

void	vertical_cross(t_all *all)
{
	if (all->pl.fov_start > M_PI_2 && all->pl.fov_start < 3 * M_PI_2)
	{
		all->cross.vx = (int)(all->pl.x / SCALE) * SCALE - 0.001;
		all->cross.v_dx = -SCALE;
		all->cross.vy = all->pl.y + (all->pl.x - all->cross.vx)
			* tan(all->pl.fov_start);
		all->cross.v_dy = SCALE * tan(all->pl.fov_start);
	}
	else
	{
		all->cross.vx = (int)(all->pl.x / SCALE) * SCALE + SCALE;
		all->cross.v_dx = SCALE;
		all->cross.vy = all->pl.y + (all->pl.x - all->cross.vx)
			* tan(all->pl.fov_start);
		all->cross.v_dy = -SCALE * tan(all->pl.fov_start);
	}
}
