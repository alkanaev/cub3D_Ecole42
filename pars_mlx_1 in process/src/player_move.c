#include "../cub3d.h"

int control_player(int keycode, t_all *all)
{
	int i;
	int j;

	int x_max = all->player.x;
	int y_max = all->player.y;
	
    if (keycode == ESC)
	{
		mlx_destroy_window(all->data.mlx, all->data.mlx_win);
		exit(0); // это чтобы не сегалось, когда закрываешь окно, потому что не заканчивается программа
	}     
    else if(keycode == KA)
	{
        all->player.x -= 8.23 * sin(all->player.dir); // если вдруг сегается, то изменить шаг на 0.11 или такой параметр, на который не делится без остатка
		all->player.y -= 8.23 * cos(all->player.dir);
	}
    else if (keycode == KS)
	{
		all->player.x -= 8.23 * cos(all->player.dir);
		all->player.y += 8.23 * sin(all->player.dir);
	}
        
    else if (keycode == KD)
        {
			all->player.x += 8.23 * sin(all->player.dir);
			all->player.y += 8.23 * cos(all->player.dir);
		}
    else if (keycode == KW)
       {
		   all->player.x += 8.23 * cos(all->player.dir);
			all->player.y -= 8.23 * sin(all->player.dir);
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
	i = (int)all->player.x / SCALE;
	j = (int)all->player.y / SCALE;
	if (all->map.map[j][i] == '1')
	{
		all->player.x = x_max;
		all->player.y = y_max;
	}
	// printf("%f\n", all->player.x);
	// printf("%f\n", all->player.y);
	return (0);
}
