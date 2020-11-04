#include "../cub3d.h"

void	cast_rays(t_all *all)
{
	int i;

	all->pl.fov_start = all->map.dir + M_PI / 6;
	get_sprite_positions(all);
	i = 0;
	while (i < all->map.s_width)
	{
		fix_angle(&all->pl.fov_start);
		horizontal_cross(all);
		vertical_cross(all);
		horizontal_hit(all);
		vertical_hit(all);
		shortest_distance(all, i);
		calculate_wall(all, i);
		find_wall(all);
		draw_ceiling(all, i);
		draw_wall(all, i);
		draw_floor(all, i);
		draw_all_sprites(all, i);
		all->pl.fov_start -= all->pl.angle;
		i++;
	}
}

int		render_next_frame(t_all *all)
{
	cast_rays(all);
	mlx_put_image_to_window(all->data.mlx, all->data.mlx_win,
			all->data.img, 0, 0);
	mlx_do_sync(all->data.mlx);
	return (1);
}
