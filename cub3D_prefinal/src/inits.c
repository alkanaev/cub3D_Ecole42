#include "../cub3d.h"

static void init_player(t_all *all)
{
	get_player_position(all);
	get_player_direction(all);
	all->pl.angle = (M_PI / 3) / all->map.s_width; // fov / width of projection plane
	all->pl.dist_to_screen = (all->map.s_width / 2) / tan(M_PI / 6); // 1/2 screen / tan(30)

}
void init_screen_params(t_all *all)
{
	int max_s_width;
	int max_s_height;
	
	max_s_width = 240;
	max_s_height = 360;

	mlx_get_screen_size(all->data.mlx, &max_s_width, &max_s_height);
	if (all->map.s_width > max_s_width)
		all->map.s_width = max_s_width;
	if (all->map.s_height > max_s_height)
		all->map.s_height = max_s_height;
}

void init_all(t_all *all)
{
	init_player(all);
	init_textures(all);
	init_slice_height(all);
	init_offset(all);
	init_ceiling(all);
	init_sprites(all);
	init_screen_params(all);
}