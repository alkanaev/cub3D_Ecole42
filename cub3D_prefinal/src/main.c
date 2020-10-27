#include "../cub3d.h"

int		ft_strcmp(char const *s1, char const *s2)
{
	unsigned int	i;

	i = 0;
	if (s1 == 0 || s2 == 0)
	{
		if (s1 == 0 && s2 == 0)
			return (0);
		if (s1 != 0)
			return (1);
		else
			return (-1);
	}
	while ((s1[i] != 0 || s2[i] != 0))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
int close_everything(t_all *all)
{
	mlx_destroy_window(all->data.mlx, all->data.mlx_win);
	exit(0);
	return(0);
}

void	save_bmp(t_all *all)
{
	cast_rays(all);
	make_screenshot(all);
}

int 	launch_cub (t_all *all)
{
	all->data.mlx_win = mlx_new_window(all->data.mlx, all->map.s_width, all->map.s_height, "CUB_3D!");
	mlx_hook(all->data.mlx_win, 2, 1L<<0, &control_player, all);
	mlx_loop_hook(all->data.mlx, render_next_frame, all);
	mlx_hook(all->data.mlx_win, 17, 0, &close_everything, all); // 17 это крестик, для закрытия программы
	mlx_loop(all->data.mlx);
	return (0);
}
void		mlx_launch(t_all *all)
{
	all->data.mlx = mlx_init();
	all->data.img = mlx_new_image(all->data.mlx, all->map.s_width, all->map.s_height);
	all->data.addr = mlx_get_data_addr(all->data.img, &all->data.bits_per_pixel, &all->data.line_length,
                                  &all->data.endian);
	init_all(all);
}

void	main_init(t_all *all)
{
	all->texture[north].relative_path = NULL;
	all->texture[south].relative_path = NULL;
	all->texture[west].relative_path = NULL;
	all->texture[east].relative_path = NULL;
	all->sprite_img.spr = NULL;
	all->map.valid = 1;
}

void	initialization_of_structures(t_map *map)
{
	map->start_map = -1;
	map->end_map = -1;
	map->max_str = -1;
	map->height_map = -1;
	map->dir = -1;
	map->map = NULL;
}

int		main(int argc, char **argv)
{
	t_all all;
	main_init(&all);
	initialization_of_structures(&(all.map));
	if (argc >= 2)
	{
		check_format(argv[1], &(all.map), &all);
		if (all.map.valid == 1)
			mlx_launch(&all);
	}
	if (argc == 3 && ft_strcmp(argv[2], "--save") == 0)
		save_bmp(&all);
	else if (argc == 2 && all.map.valid == 1)
		launch_cub(&all);
	//if (argc < 2 || argc > 3 || all.map.valid == 0)
	else
		ft_putstr("error");
	return (0);
}