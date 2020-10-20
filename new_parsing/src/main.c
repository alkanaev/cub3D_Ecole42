#include "../cub3d.h"

void	cast_ray(t_all *all)
{
	all->player.fov_start = all->player.dir + M_PI / 6;
	int i = 0;
	while (i < S_WIDTH)
	{
		fix_angle(&all->player.fov_start); // for each ray
		horizontal_cross(all); // for each ray
		vertical_cross(all); // for each ray
		horizontal_hit(all); // for each ray
		vertical_hit(all); // for each ray
		shortest_distance(all, i); // for each ray
        //draw_ray(all);
		calculate_wall(all, i);
		all->player.fov_start -= all->player.angle; // change the ray position
		i++;
	}
}

int     render_next_frame(t_all *all)
{
	//draw_map(all);
	//draw_player(all);
	cast_ray(all);
	draw_screen(all);
	mlx_put_image_to_window(all->data.mlx, all->data.mlx_win, all->data.img, 0, 0);
	return (1);
}

// int				**init_int_map(int ***map)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	(*map)[i] = malloc(sizeof(int) * 11);
// 	while (i != 10)
// 	{
// 		while (j != 10)
// 		{
// 			(*map)[i][j] = malloc(sizeof(int) * 11);
// 			j++;
// 		}
// 		j = 0;
// 		i++;
// 	}
// 	(*map) = {// нужно обязательно найти потом макс. кол-во элементов массива
//     { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
//     { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//     { 1, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
// 	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
// 	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
// 	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
// 	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
// 	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
// 	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
// 	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
// 	};
// }

//int             main(void)
//{
int		main(int argc, char **argv)
{
	//t_all	all;
	
	if (argc >= 2)
		check_format(argv[1]);
	else
		ft_putstr("no file given");
	parser_map(argv[1], 0, 0);
	///check//////////
	//while (*all.pars.map) printf("\n\nTHISSSSSSSSSSSSSSSSSSSSSSS\n%s\n", *all.pars.map++);
	//------------------------------------------------------------------------------------

	// all.make_map = init_int_map(&all.make_map);
    /*all.data.mlx = mlx_init();
    all.data.mlx_win = mlx_new_window(all.data.mlx, S_WIDTH, S_HEIGHT, "CUB_3D!");

	all.data.img = mlx_new_image(all.data.mlx, S_WIDTH, S_HEIGHT);
	all.data.addr = mlx_get_data_addr(all.data.img, &all.data.bits_per_pixel, &all.data.line_length,
                                  &all.data.endian);

	all.texture.relative_path = "./wall2.xpm";
	all.texture.img = mlx_xpm_file_to_image(all.data.mlx, all.texture.relative_path, &all.texture.img_width, &all.texture.img_height);
	all.texture.addr = mlx_get_data_addr(all.texture.img, &all.texture.bits_per_pixel, &all.texture.line_length, &all.texture.endian);
	
	init_player(&all);
	mlx_hook(all.data.mlx_win, 2, 1L<<0, &control_player, &all);
	mlx_loop_hook(all.data.mlx, render_next_frame, &all);
	mlx_loop(all.data.mlx);*/
}