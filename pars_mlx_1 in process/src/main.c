#include "../cub3d.h"

int close_everything(t_all *all)
{
	mlx_destroy_window(all->data.mlx, all->data.mlx_win);
	exit(0);
	return(0);
}

int		mlx_launch(t_all *all)
{
	all->data.mlx = mlx_init();
    all->data.mlx_win = mlx_new_window(all->data.mlx, all->map.s_width, all->map.s_height, "CUB_3D!");

	all->data.img = mlx_new_image(all->data.mlx, all->map.s_width, all->map.s_height);
	all->data.addr = mlx_get_data_addr(all->data.img, &all->data.bits_per_pixel, &all->data.line_length,
                                  &all->data.endian);

	init_all(all);
	mlx_hook(all->data.mlx_win, 2, 1L<<0, &control_player, all);
	mlx_loop_hook(all->data.mlx, render_next_frame, all);
	mlx_hook(all->data.mlx_win, 17, 0, &close_everything, all); // 17 это крестик, для закрытия программы
	mlx_loop(all->data.mlx);
	return(0);
}

void	main_init(t_all *all)
{
	all->check = 0;
	all->texture[north].relative_path = NULL;
	all->texture[south].relative_path = NULL;
	all->texture[west].relative_path = NULL;
	all->texture[east].relative_path = NULL;
	all->sprite_img.spr = NULL;
}

int		main(int argc, char **argv)
{
	t_all all;
	main_init(&all);
	initialization_of_structures(&(all.map));
	if (argc >= 2)
	{
		check_format(argv[1], &(all.map), &all);
	}
	else
		ft_putstr("no file given");
	mlx_launch(&all);
}