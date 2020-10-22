#include "../cub3d.h"

void init_player(t_all *all)
{
	all->player.x = 187;
	all->player.y = 213;
	all->player.dir = M_PI_4;
	all->player.angle = (M_PI / 3) / S_WIDTH; // fov / width of projection plane
	all->player.dist_to_screen = (S_WIDTH / 2) / tan(M_PI / 6); // 1/2 screen / tan(30)

}