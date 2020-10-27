#include "../cub3d.h"

static int  draw_sprite_img(t_all *all, int i, int j, int y)
{
    char    *dst;
	unsigned int color;

        int y_texture = y * (all->sprite_img.img_height - 1) / (all->sp[j].size - 1);
        int x_texture = (i - all->sp[j].h_offset) * (all->sprite_img.img_width - 1) / (all->sp[j].size - 1);
		dst = all->sprite_img.addr + (y_texture * all->sprite_img.line_length + x_texture * (all->sprite_img.bits_per_pixel / 8));
		color = *(unsigned int*)dst;
        return (color);
}

static  void draw_sprite(t_all *all, int i, int j)
{
    int color;
    float start = all->map.dir + M_PI / 6;
    all->sp[j].dir = atan2(all->pl.y - all->sp[j].y, all->sp[j].x - all->pl.x);
    fix_angle(&all->sp[j].dir);
    all->sp[j].delta = compute_delta_angle(start, all->sp[j].dir);
    all->sp[j].dist = sqrt(pow(all->pl.x - all->sp[j].x, 2) + pow(all->pl.y - all->sp[j].y, 2)); // по теореме пифагора
    all->sp[j].size = ceil(((SCALE / 2) / all->sp[j].dist) * all->pl.dist_to_screen);
    if (all->sp[j].size > all->map.s_height)
        all->sp[j].size = 0;
    all->sp[j].h_offset = all->sp[j].delta / ((M_PI / 3) / all->map.s_width) - all->sp[j].size / 2; 
    all->sp[j].v_offset = (all->map.s_height / 2) - all->sp[j].size / 2;
    if (all->sp[j].h_offset < 0 && all->sp[j].h_offset > all->map.s_width - 1)
            all->sp[j].size = 0;
    if (i >= all->sp[j].h_offset && i <= all->sp[j].h_offset + all->sp[j].size)
    {
        int y = 0;
        while (y < all->sp[j].size)
        {
            color = draw_sprite_img(all, i, j, y);
            if (color != 0x000000 && all->cross.closest_cross > all->sp[j].dist)
                my_mlx_pixel_put(&all->data, i, all->sp[j].v_offset + y, color);
            y++;
        }
    }
}

void draw_all_sprites(t_all *all, int i)
{
	sort_sprites(all);
    int j = 0;
    int count = all->sprite_count;
    while (j < count)
    {
        draw_sprite(all, i, j);
        j++;
    }
}