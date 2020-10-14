#include "../cub3d.h"

int control_player(int keycode, t_all *all)
{
     if(keycode == ESC)
         mlx_destroy_window(all->data.mlx, all->data.mlx_win);
    else if(keycode == KA)
	{
        all->player.x -= 5 * sin(all->player.dir);
		all->player.y -= 5 * cos(all->player.dir);
	}
    else if(keycode == KS)
	{
		all->player.x -= 5 * cos(all->player.dir);
		all->player.y += 5 * sin(all->player.dir);
	}
        
    else if(keycode == KD)
        {
			all->player.x += 5 * sin(all->player.dir);
			all->player.y += 5 * cos(all->player.dir);
		}
    else if(keycode == KW)
       {
		   all->player.x += 5 * cos(all->player.dir);
			all->player.y -= 5 * sin(all->player.dir);
	   }
	else if(keycode == LEFT)
	{
		all->player.dir += 0.03;
		fix_angle(&all->player.dir);
	}
    else if(keycode == RIGHT)
	{
		all->player.dir -= 0.03;
		fix_angle(&all->player.dir);
	}
	// printf("%f\n", all->player.x);
	// printf("%f\n", all->player.y);
	// printf("%f\n", all->player.dir);
	return (0);
}