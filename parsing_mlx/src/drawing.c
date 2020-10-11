#include "../cub3d.h"

/*int map_int [10] [10] = { // нужно обязательно найти потом макс. кол-во элементов массива
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};*/

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void            draw_pixels_from_img(t_all *all, int width)
{
    char    *dst;
	unsigned int color;

	int y_start = all->player.ceiling[width];
	//int y = all->player.ceiling[width];
	int y;
	while (y_start < all->player.ceiling[width] + all->player.slice_height[width])
	{
    	y = (int)((y_start - all->player.ceiling[width]) / all->player.slice_height[width] * (float)all->texture.img_height);
		int x_texture = all->cross.offset[width] / SCALE * all->texture.img_width;
		dst = all->texture.addr + (y * all->texture.line_length + x_texture * (all->texture.bits_per_pixel / 8));
		color = *(unsigned int*)dst;
		my_mlx_pixel_put(&all->data, width, y_start, color);
		y_start++;
	}
}
void	draw_player(t_all *all)
{
	my_mlx_pixel_put(&all->data, all->player.x, all->player.y, 0x00FF0000);
}


void	draw_map(t_all *all)
{
	all->data.img = mlx_new_image(all->data.mlx, 1200, 800);
	all->data.addr = mlx_get_data_addr(all->data.img, &all->data.bits_per_pixel, &all->data.line_length,
                                  &all->data.endian);
	all->map.y = 0;
	while (all->map.y/SCALE < 23 ) // нужна будет переменная под размер карты
	{
		all->map.x = 0;
		while (all->map.x/SCALE < 23) // нужна будет переменная под размер карты
		{
			if (all->map.map[all->map.y / SCALE][all->map.x / SCALE] == '1')
			{
				my_mlx_pixel_put(&all->data, all->map.x, all->map.y, 0x000000FF);
			}
			// else if (map_int[all->map.y / SCALE][all->map.x / SCALE] == 0)
			else
				my_mlx_pixel_put(&all->data, all->map.x, all->map.y, 0x00000000);
			all->map.x++;

		}
		all->map.y++;
	}
}

static void draw_ceiling(t_all *all, int width)
{
	int height = 0;
	while (height < all->player.ceiling[width])
	{
		my_mlx_pixel_put(&all->data, width, height++, 0xFFB6C1);
	}
}

// static void draw_wall(t_all *all, int width)
// {
// 	int y = all->player.ceiling[width];
// 	int ceiling_y = all->player.ceiling[width];
// 	while (y < ceiling_y + all->player.slice_height[width])
// 	{
// 		unsigned int pixel = draw_pixels_from_img(all, width, y);
// 		my_mlx_pixel_put(&all->data, width, y++, pixel);
// 	}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
// }
static void draw_floor(t_all *all, int width)
{
	int height = all->player.slice_height[width] + all->player.ceiling[width]; // координата начала для отрисовки пола
	while (height < S_HEIGHT)
	{
		my_mlx_pixel_put(&all->data, width, height++, 0xFF00FF);
	}
}

void	draw_ray(t_all *all)
{
	int dx = all->cross.wall_x - all->player.x;
    int dy = all->cross.wall_y - all->player.y;
    int     steps;
    float x_increment;
    float y_increment;
    float x = all->player.x;
    float y = all->player.y;
    if (abs(dx) > abs(dy)) // abs - absolute value (library function)
        steps = abs(dx);
    else
        steps = abs(dy);
    x_increment = dx / (float)steps;
    y_increment = dy / (float)steps;
    int i = 0;
    while (i < steps)
    {
        x +=x_increment;
        y += y_increment;
        my_mlx_pixel_put(&all->data, round(x), round(y), 0xFFA500);
        i++;
	}
}

void	draw_screen(t_all *all)
{
	int width = 0;
	while (width < S_WIDTH)
	{
		draw_ceiling(all, width);
		draw_pixels_from_img(all, width);
		//draw_wall(all, width);
		draw_floor(all, width);
		width++;
	}
}