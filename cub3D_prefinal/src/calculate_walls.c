#include "../cub3d.h"

void fix_angle(float *angle)
{
	if (*angle < 0)
			*angle += 2 * M_PI;
	if (*angle > 2 * M_PI)
		*angle -= 2 * M_PI;
}

void calculate_wall(t_all *all, int i)
{
	all->pl.slice_height[i] = ceil((SCALE / all->cross.right_distance) 
			* all->pl.dist_to_screen);
	all->pl.ceiling[i] = (all->map.s_height / 2)
		- (all->pl.slice_height[i] / 2);     
}

void find_wall(t_all *all)
{
	if (all->pl.fov_start >= 0 && all->pl.fov_start <= M_PI)
	{
		if (all->cross.hit == 0)
		{
			if (all->pl.fov_start >= 0 && all->pl.fov_start <= M_PI_2)
				all->cross.hit_side = east;
			else if (all->pl.fov_start > M_PI_2 
					&& all->pl.fov_start < M_PI)
				all->cross.hit_side = west;
		}
		else
			all->cross.hit_side = north;
	}
	else // if (all->player.fov_start > M_PI && all->player.fov_start < 2 * M_PI)
	{ 
		if (all->cross.hit == 0)
		{
			if (all->pl.fov_start > M_PI && all->pl.fov_start < 3 * M_PI_2)
				all->cross.hit_side = west;
			else if (all->pl.fov_start > 3 * M_PI_2 && all->pl.fov_start < 2 * M_PI)
				all->cross.hit_side = east;
			}
		else
			all->cross.hit_side = south;	
	}
}
