#include "../cub3d.h"

/*int map_int_1 [10] [10] = { // нужно обязательно найти потом макс. кол-во элементов массива
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};*/

void 	horizontal_cross(t_all *all) // find the coordinates of the first horizontal cub cross + the delta
{
	if (all->player.fov_start > 0 && all->player.fov_start < M_PI) // the ray looking up
	{
		all->cross.hy = (int)(all->player.y / SCALE) * SCALE - 1;
		all->cross.h_dy = -SCALE;
		all->cross.hx = all->player.x + (all->player.y - all->cross.hy) / tan(all->player.fov_start);
		all->cross.h_dx = SCALE/tan(all->player.fov_start);
	}
	else // the ray looking down
	{
		all->cross.hy = (int)(all->player.y / SCALE) * SCALE + SCALE;
		all->cross.h_dy = SCALE;
		all->cross.hx = all->player.x + (all->player.y - all->cross.hy) / tan(all->player.fov_start);
		all->cross.h_dx = -SCALE/tan(all->player.fov_start);
	}
}

void	vertical_cross(t_all *all) // find the coordinates of the first vertical cub cross + the delta
{
	if (all->player.fov_start > M_PI_2 && all->player.fov_start < 3 * M_PI_2) // the ray looking left
	{
		all->cross.vx = (int)(all->player.x / SCALE) * SCALE - 1;
		all->cross.v_dx = -SCALE;
		all->cross.vy =all->player.y + (all->player.x - all->cross.vx) * tan(all->player.fov_start);
		all->cross.v_dy = SCALE * tan(all->player.fov_start);
	}
	else // the ray looking right
	{	
		all->cross.vx = (int)(all->player.x / SCALE) * SCALE + SCALE;
		all->cross.v_dx = SCALE;
		all->cross.vy = all->player.y + (all->player.x - all->cross.vx) * tan(all->player.fov_start);
		all->cross.v_dy = -SCALE * tan(all->player.fov_start);
	}
}

static int is_out_of_map(float x, float y) // checks if the coordinate is outside of the map
{
	if ((x > 0 && x < MAX) && (y > 0 && y < MAX))
		return (0);
	else 
		return (1);
}

static int is_wall(float x, float y, t_all *all) // checks if the coordinate hits the wall
{
	if (all->map.map[(int)y / SCALE][(int)x / SCALE] != '1')
		return (0);
	else
		return (1);	
}

void horizontal_hit(t_all *all) // find the horizontal coordinates when it hits the wall
{
	while (!is_out_of_map(all->cross.hx, all->cross.hy) && !is_wall(all->cross.hx, all->cross.hy, all))
	{
		all->cross.hx += all->cross.h_dx;
	 	all->cross.hy += all->cross.h_dy;
	}
	// calculate the distance 
	float pow_hx = pow((all->player.x - all->cross.hx), 2);
	float pow_hy = pow((all->player.y - all->cross.hy), 2);
	all->cross.h_distance = sqrt(pow_hx + pow_hy);
}

void vertical_hit(t_all *all) // find the vertical coordinates when it hits the wall
{
	while (!is_out_of_map(all->cross.vx, all->cross.vy) && !is_wall(all->cross.vx, all->cross.vy, all))
	{
		all->cross.vx += all->cross.v_dx;
	 	all->cross.vy += all->cross.v_dy;
	}
	// calculate the distance 
	float pow_vx = pow((all->player.x - all->cross.vx), 2);
	float pow_vy = pow((all->player.y - all->cross.vy), 2);
	all->cross.v_distance = sqrt(pow_vx + pow_vy);
}


void shortest_distance(t_all *all, int i) // choose the closeset wall hit coordinate (whether it's horizontal or vertical)
{
		if (all->cross.h_distance < all->cross.v_distance)
		{
			all->cross.closest_cross = all->cross.h_distance; // remember this coordinate
			all->cross.wall_x = all->cross.hx;
			all->cross.wall_y = all->cross.hy;
			//all->cross.offset = fmod(all->cross.wall_y, SCALE);
		}
		if (all->cross.h_distance > all->cross.v_distance)
		{
			all->cross.closest_cross = all->cross.v_distance;
			all->cross.wall_x = all->cross.vx;
			all->cross.wall_y = all->cross.vy;
			//all->cross.offset = fmod(all->cross.wall_x, SCALE);
		}
		all->cross.right_distance = all->cross.closest_cross * cos(all->player.dir - all->player.fov_start); // for fisheye effect
		if (all->cross.h_distance < all->cross.v_distance)
		{
			all->cross.offset[i] = fmod(all->cross.wall_x, SCALE);
		}
		else if (all->cross.h_distance > all->cross.v_distance)
		{
			all->cross.offset[i] = fmod(all->cross.wall_y, SCALE);
		}
}

void fix_angle(float *angle)
{
	if (*angle < 0)
			*angle += 2 * M_PI;
	if (*angle > 2 * M_PI)
		*angle -= 2 * M_PI;
}

void calculate_wall(t_all *all, int i)
{
	// all->player.slice_height[i] = S_HEIGHT * 64 / all->cross.right_distance;
	all->player.slice_height[i] = ceil((SCALE / all->cross.right_distance) * all->player.dist_to_screen);
	all->player.ceiling[i] = SCREEN_CENTER - (all->player.slice_height[i] / 2);     

}