#include "../cub3d.h"

float   compute_delta_angle(float fov_start, float sprite_dir)
{
    float delta;
    delta =fov_start - sprite_dir;
    if (delta <= -M_PI)
        delta = 2 * M_PI + delta;
    else if (delta >= M_PI)
        delta = delta - 2 * M_PI;
    return (delta);
}

void ft_swap(t_sprite *xp, t_sprite *yp) 
{ 
    t_sprite temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

t_sprite   **sort_sprites(t_all *all)
{
    int i;
    int j;
    int count = all->sprite_count;
    i = 0;
    while (i < count - 1)
	{
        j = 0;
        while (j < count - i - 1)
        {
            if (all->sprite[j].dist < all->sprite[j + 1].dist) 
			{
				ft_swap(&all->sprite[j], &all->sprite[j + 1]);
            }
			
            j++;
        }
	    i++;
	}
    return(&all->sprite);
}

int            draw_sprite_img(t_all *all, int i, int j, int y)
{
    char    *dst;
	unsigned int color;

        int y_texture = y * (all->sprite_img.img_height - 1) / (all->sprite[j].size - 1);
        int x_texture = (i - all->sprite[j].h_offset) * (all->sprite_img.img_width - 1) / (all->sprite[j].size - 1);
		dst = all->sprite_img.addr + (y_texture * all->sprite_img.line_length + x_texture * (all->sprite_img.bits_per_pixel / 8));
		color = *(unsigned int*)dst;
        return (color);
}

void draw_sprite(t_all *all, int i, int j)
{
    int color;
    float start = all->player.dir + M_PI / 6;
    all->sprite[j].dir = atan2(all->player.y - all->sprite[j].y, all->sprite[j].x - all->player.x);
    fix_angle(&all->sprite[j].dir);
    all->sprite[j].delta = compute_delta_angle(start, all->sprite[j].dir);
    all->sprite[j].dist = sqrt(pow(all->player.x - all->sprite[j].x, 2) + pow(all->player.y - all->sprite[j].y, 2)); // по теореме пифагора
    all->sprite[j].size = ceil(((SCALE / 2) / all->sprite[j].dist) * all->player.dist_to_screen);
    if (all->sprite[j].size > S_HEIGHT)
        all->sprite[j].size = 0;
    all->sprite[j].h_offset = all->sprite[j].delta / ((M_PI / 3) / S_WIDTH) - all->sprite[j].size / 2; 
    all->sprite[j].v_offset = SCREEN_CENTER - all->sprite[j].size / 2;
    

    if (i >= all->sprite[j].h_offset && i <= all->sprite[j].h_offset + all->sprite[j].size)
    {
        int y = 0;
        while (y < all->sprite[j].size)
        {
            color = draw_sprite_img(all, i, j, y);
            if (color != 0x000000 && all->cross.closest_cross > all->sprite[j].dist)
            {
                 my_mlx_pixel_put(&all->data, i, all->sprite[j].v_offset + y, color);
            }
            y++;
        }
    }
}


void draw_all_sprites(t_all *all, int i)
{
    // get_sprite_params(all);
    get_sprite_positions(all);
	sort_sprites(all);
    // sort_sprite(all, all->sprite_order, all->sprite_distance);
    int j = 0;
    int count = all->sprite_count;
    while (j < count)
    {
        draw_sprite(all, i, j);
        j++;
    }

}