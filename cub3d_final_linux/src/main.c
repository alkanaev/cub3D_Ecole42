#include "../cub3d.h"

int		close_everything(t_all *all)
{
	mlx_destroy_window(all->data.mlx, all->data.mlx_win);
	exit(0);
	return (0);
}

void	save_bmp(t_all *all)
{
	cast_rays(all);
	make_screenshot(all);
}

int		launch_cub(t_all *all)
{
	all->data.mlx_win = mlx_new_window(all->data.mlx, all->map.s_width,
			all->map.s_height, "CUB_3D!");
	mlx_hook(all->data.mlx_win, 2, 1L << 0, &control_player, all);
	mlx_loop_hook(all->data.mlx, render_next_frame, all);
	mlx_hook(all->data.mlx_win, 17, 0, &close_everything, all);
	mlx_loop(all->data.mlx);
	return (0);
}

void	mlx_launch(t_all *all)
{
	all->data.mlx = mlx_init();
	all->data.img = mlx_new_image(all->data.mlx, all->map.s_width,
			all->map.s_height);
	all->data.addr = mlx_get_data_addr(all->data.img, &all->data.bits_per_pixel,
			&all->data.line_length, &all->data.endian);
	init_all(all);
}

int		main(int argc, char **argv)
{
	t_all all;

	main_init(&all);
	initialization_of_structures(&(all.map));
	if (argc >= 2)
	{
		check_format(argv[1], &(all.map), &all);
		if (all.map.valid == 1 && all.map.tok == 8)
			mlx_launch(&all);
	}
	if (argc == 3 && ft_strcmp(argv[2], "--save") == 0
		&& all.map.valid == 1)
		save_bmp(&all);
	else if (argc == 2 && all.map.valid == 1 && all.map.tok == 8)
		launch_cub(&all);
	else
		ft_putstr("\nError\nCub3d will not work. Check parameters\n");
	return (0);
}