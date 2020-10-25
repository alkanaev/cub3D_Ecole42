#include "../cub3d.h"

static void init_player(t_all *all)
{
	get_player_position(all);
	all->player.dir = M_PI_4;
	all->player.angle = (M_PI / 3) / S_WIDTH; // fov / width of projection plane
	all->player.dist_to_screen = (S_WIDTH / 2) / tan(M_PI / 6); // 1/2 screen / tan(30)

}

static void get_sprite_image_data(t_all *all)
{
	all->sprite_img.img = mlx_xpm_file_to_image(all->data.mlx, all->sprite_img.relative_path, &all->sprite_img.img_width, &all->sprite_img.img_height);
	all->sprite_img.addr = mlx_get_data_addr(all->sprite_img.img, &all->sprite_img.bits_per_pixel, &all->sprite_img.line_length, &all->sprite_img.endian);
}
static void get_texture_data_north(t_all *all)
{
	all->texture[north].img = mlx_xpm_file_to_image(all->data.mlx, all->texture[north].relative_path, &all->texture[north].img_width, &all->texture[north].img_height);
	all->texture[north].addr = mlx_get_data_addr(all->texture[north].img, &all->texture[north].bits_per_pixel, &all->texture[north].line_length, &all->texture[north].endian);
}

static void get_texture_data_south(t_all *all)
{
	all->texture[south].img = mlx_xpm_file_to_image(all->data.mlx, all->texture[south].relative_path, &all->texture[south].img_width, &all->texture[south].img_height);
	all->texture[south].addr = mlx_get_data_addr(all->texture[south].img, &all->texture[south].bits_per_pixel, &all->texture[south].line_length, &all->texture[south].endian);
}

static void get_texture_data_east(t_all *all)
{
	all->texture[east].img = mlx_xpm_file_to_image(all->data.mlx, all->texture[east].relative_path, &all->texture[east].img_width, &all->texture[east].img_height);
	all->texture[east].addr = mlx_get_data_addr(all->texture[east].img, &all->texture[east].bits_per_pixel, &all->texture[east].line_length, &all->texture[east].endian);
}

static void get_texture_data_west(t_all *all)
{
	all->texture[west].img = mlx_xpm_file_to_image(all->data.mlx, all->texture[west].relative_path, &all->texture[west].img_width, &all->texture[west].img_height);
	all->texture[west].addr = mlx_get_data_addr(all->texture[west].img, &all->texture[west].bits_per_pixel, &all->texture[west].line_length, &all->texture[west].endian);
}

t_sprite *init_sprites(t_all *all)
{
    int count = all->sprite_count;
  
    if (!(all->sprite = malloc(sizeof(t_sprite) * (count + 1))))
        return (NULL);
    // all->sprite[count] = NULL;
    return(all->sprite);
}

// void *init_slice_height(t_all *all)
// {
// 	if (!(all->player.slice_height = malloc(sizeof(char) * (all->map.s_width + 1))))
//         return (NULL);
//     return(all->player.slice_height);
// }

// void *init_ceiling(t_all *all)
// {
// 	if (!(all->player.ceiling = malloc(sizeof(char) * (all->map.s_width + 1))))
//         return (NULL);
//     return(all->player.ceiling);
// }

// void *init_offset(t_all *all)
// {
// 	if (!(all->cross.offset = malloc(sizeof(char) * (all->map.s_width + 1))))
//         return (NULL);
//     return(all->cross.offset);
// }

void init_textures(t_all *all)
{
	get_texture_data_north(all);
	get_texture_data_south(all);
	get_texture_data_east(all);
	get_texture_data_west(all);
	get_sprite_image_data(all);
}

void init_all(t_all *all)
{
	init_player(all);
	//init_slice_height(all);
	//init_offset(all);
	//init_ceiling(all);
	init_textures(all);
	init_sprites(all);
}