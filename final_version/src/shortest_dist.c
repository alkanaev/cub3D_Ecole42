#include "../cub3d.h"

static int is_out_of_map(float x, float y, t_all *all) // checks if the coordinate is outside of the map
{
	
	if ((x > 0 && x < (all->map.max_rows * SCALE)) &&
			(y > 0 && y < (all->map.max_columns + 1) * SCALE))
		return (0);
	else 
		return (1);
}

static int is_wall(float x, float y, t_all *all) // checks if the coordinate hits the wall
{
	int i;
	int j;

	i = (int)x / SCALE;
	j = (int)y / SCALE;
	if (all->map.map[j][i] != '1')
		return (0);
	else
		return (1);	
}

void horizontal_hit(t_all *all) // find the horizontal coordinates when it hits the wall
{
	while (!is_out_of_map(all->cross.hx, all->cross.hy, all) 
			&& !is_wall(all->cross.hx, all->cross.hy, all))
	{
		all->cross.hx += all->cross.h_dx;
	 	all->cross.hy += all->cross.h_dy;
	}
	// calculate the distance 
	float pow_hx = pow((all->pl.x - all->cross.hx), 2);
	float pow_hy = pow((all->pl.y - all->cross.hy), 2);
	all->cross.h_distance = sqrt(pow_hx + pow_hy) - 0.001;
}

void vertical_hit(t_all *all) // find the vertical coordinates when it hits the wall
{
	while (!is_out_of_map(all->cross.vx, all->cross.vy, all) 
			&& !is_wall(all->cross.vx, all->cross.vy, all))
	{
		all->cross.vx += all->cross.v_dx;
	 	all->cross.vy += all->cross.v_dy;
	}
	// calculate the distance 
	float pow_vx = pow((all->pl.x - all->cross.vx), 2);
	float pow_vy = pow((all->pl.y - all->cross.vy), 2);
	all->cross.v_distance = sqrt(pow_vx + pow_vy);
}

void shortest_distance(t_all *all, int i) // choose the closeset wall hit coordinate (whether it's horizontal or vertical)
{
		if (all->cross.h_distance <= all->cross.v_distance)
		{
			all->cross.closest_cross = all->cross.h_distance; // remember this coordinate
			all->cross.wall_x = all->cross.hx;
			all->cross.wall_y = all->cross.hy;
			all->cross.hit = 1; // remember that we hit the wall horizontally to check the wall side after
			all->cross.offset[i] = fmod(all->cross.wall_x, SCALE); // calculate offset for drawing the wall
		}
		if (all->cross.h_distance > all->cross.v_distance)
		{
			all->cross.closest_cross = all->cross.v_distance;
			all->cross.wall_x = all->cross.vx;
			all->cross.wall_y = all->cross.vy;
			all->cross.hit = 0; // remember that we hit the wall vertically to check the wall side after
			all->cross.offset[i] = fmod(all->cross.wall_y, SCALE); // calculate offset for drawing the wall
		}
		all->cross.right_distance = all->cross.closest_cross
			* cos(all->map.dir - all->pl.fov_start); // get rid of the fisheye effect
}