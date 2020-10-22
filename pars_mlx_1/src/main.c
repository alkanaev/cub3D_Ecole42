#include "../cub3d.h"

int close_everything(t_all *all)
{
	mlx_destroy_window(all->data.mlx, all->data.mlx_win);
	exit(0);
	return(0);
}

int		main(int argc, char **argv)
{
	t_all all;
	initialization_of_structures(&all.map);
	if (argc >= 2)
	{
		check_format(argv[1], &(all.map));	
		// printf("%c\n", all.map.map[0][13]);
	//printf("%c\n", all.map.map[2][1]);
	//printf("%c\n", all.map.map[2][2]);
	//printf("%c\n", all.map.map[2][3]);
	//printf("%c\n", all.map.map[2][4]);
	//get_positions(&all.map);
	}
	else
		ft_putstr("no file given");
	//parser_map(argv[1]);
	///check//////////
	//while (*all.map.map) printf("\n\nTHISSSSSSSSSSSSSSSSSSSSSSS\n%s\n", *all.map.map++);
	//------------------------------------------------------------------------------------
	// all.make_map = init_int_map(&all.make_map);
	// printf("%c\n", &(all.map.map[0][13]));
    all.data.mlx = mlx_init();
    all.data.mlx_win = mlx_new_window(all.data.mlx, S_WIDTH, S_HEIGHT, "CUB_3D!");

	all.data.img = mlx_new_image(all.data.mlx, S_WIDTH, S_HEIGHT);
	all.data.addr = mlx_get_data_addr(all.data.img, &all.data.bits_per_pixel, &all.data.line_length,
                                  &all.data.endian);

	init_all(&all);
	mlx_hook(all.data.mlx_win, 2, 1L<<0, &control_player, &all);
	mlx_loop_hook(all.data.mlx, render_next_frame, &all);
	mlx_hook(all.data.mlx_win, 17, 0, &close_everything, &all); // 17 это крестик, для закрытия программы
	mlx_loop(all.data.mlx);
}