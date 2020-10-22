#include "../cub3d.h"

/* make necessary calculations for each ray
and draw ceiling, wall and floor by slice
*/
static void	cast_rays(t_all *all)
{
	all->player.fov_start = all->player.dir + M_PI / 6;
	int i = 0;
	while (i < S_WIDTH)
	{
		fix_angle(&all->player.fov_start); 
		horizontal_cross(all);
		vertical_cross(all);
		horizontal_hit(all);
		vertical_hit(all);
		shortest_distance(all, i);
		calculate_wall(all, i);
		find_wall(all);
		//draw_ray(all);
		draw_ceiling(all, i);
		draw_wall(all, i);
		draw_floor(all, i);
		draw_all_sprites(all, i);
		all->player.fov_start -= all->player.angle; // change the ray position
		i++;
	}
}

/* update the screen when anything changes (e.g. the player moves)
*/
int     render_next_frame(t_all *all)
{
	// draw_map(all);
	// draw_player(all);
	cast_rays(all);
	mlx_put_image_to_window(all->data.mlx, all->data.mlx_win, all->data.img, 0, 0);
	mlx_do_sync(all->data.mlx); // это чтоб не было мусора на изображении
	return (1);
}