#include "../cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_wall(t_all *all, int width)
{
	char			*dst;
	unsigned int	color;
	t_texture_data	texture;
	int				y_start;
	int				y;

	texture = all->texture[all->cross.hit_side];
	y_start = all->pl.ceiling[width];
	while (y_start < all->pl.ceiling[width] + all->pl.wall_size[width])
	{
		if (y_start < all->map.s_height && y_start > 0)
		{
			y = (int)((y_start - all->pl.ceiling[width])
					/ all->pl.wall_size[width] * (float)texture.img_height);
			dst = texture.addr + (y * texture.line_length +
					((int)(all->cross.offset[width] / SCALE * texture.img_width)
					* (texture.bits_per_pixel / 8)));
			color = *(unsigned int*)dst;
			my_mlx_pixel_put(&all->data, width, y_start, color);
		}
		y_start++;
	}
}

void	draw_ceiling(t_all *all, int width)
{
	int height;

	height = 0;
	while (height < all->pl.ceiling[width])
	{
		my_mlx_pixel_put(&all->data, width, height++, all->map.c_int);
	}
}

void	draw_floor(t_all *all, int width)
{
	int height;

	height = all->pl.wall_size[width] + all->pl.ceiling[width];
	while (height < all->map.s_height)
	{
		my_mlx_pixel_put(&all->data, width, height++, all->map.f_int);
	}
}
