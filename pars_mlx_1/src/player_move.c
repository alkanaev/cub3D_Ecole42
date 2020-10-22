#include "../cub3d.h"

int control_player(int keycode, t_all *all)
{
	
    if (keycode == ESC)
	{
		mlx_destroy_window(all->data.mlx, all->data.mlx_win);
		exit(0); // это чтобы не сегалось, когда закрываешь окно, потому что не заканчивается программа
	}     
    else if(keycode == KA)
	{
        all->player.x -= 5 * sin(all->player.dir);
		all->player.y -= 5 * cos(all->player.dir);
	}
    else if (keycode == KS)
	{
		all->player.x -= 5 * cos(all->player.dir);
		all->player.y += 5 * sin(all->player.dir);
	}
        
    else if (keycode == KD)
        {
			all->player.x += 5 * sin(all->player.dir);
			all->player.y += 5 * cos(all->player.dir);
		}
    else if (keycode == KW)
       {
		   all->player.x += 5 * cos(all->player.dir);
			all->player.y -= 5 * sin(all->player.dir);
	   }
	else if (keycode == LEFT)
	{
		all->player.dir += 0.03;
		fix_angle(&all->player.dir);
	}
    else if (keycode == RIGHT)
	{
		all->player.dir -= 0.03;
		fix_angle(&all->player.dir);
	}
	// int x_max = all->player.x;
	// int y_max = all->player.y;
	// if (all->map.map[(int)all->player.x / SCALE][(int)all->player.y / SCALE] == '1')
	// {
	// 	all->player.x = x_max;
	// 	all->player.y = y_max;
	// }
	// printf("%f\n", all->player.x);
	// printf("%f\n", all->player.y);
	return (0);
}
