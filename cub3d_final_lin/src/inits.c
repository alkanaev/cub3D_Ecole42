/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkanaev <alkanaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:59:15 by alkanaev          #+#    #+#             */
/*   Updated: 2020/11/04 14:59:16 by alkanaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			main_init(t_all *all)
{
	all->texture[north].relative_path = NULL;
	all->texture[south].relative_path = NULL;
	all->texture[west].relative_path = NULL;
	all->texture[east].relative_path = NULL;
	all->sprite_img.spr = NULL;
	all->map.valid = 1;
	all->map.s_width = 0;
	all->map.s_height = 0;
	all->map.tok = 0;
}

void			initialization_of_structures(t_map *map)
{
	map->start_map = -1;
	map->end_map = -1;
	map->max_str = -1;
	map->height_map = -1;
	map->dir = -1;
	map->map = NULL;
	map->c_int = 0;
	map->f_int = 0;
}

static void		init_player(t_all *all)
{
	get_player_position(all);
	get_player_direction(all);
	all->pl.angle = (M_PI / 3) / all->map.s_width;
	all->pl.dist = (all->map.s_width / 2) / tan(M_PI / 6);
}

void			init_screen_params(t_all *all)
{
	all->max_s_width = 0;
	all->max_s_height = 0;
	mlx_get_screen_size(all->data.mlx, &all->max_s_width, &all->max_s_height);
	if (all->map.s_width > all->max_s_width)
		all->map.s_width = all->max_s_width;
	if (all->map.s_height > all->max_s_height)
		all->map.s_height = all->max_s_height;
}

void			init_all(t_all *all)
{
	init_screen_params(all);
	init_player(all);
	init_textures(all);
	init_slice_height(all);
	init_offset(all);
	init_ceiling(all);
	init_sprites(all);
}
