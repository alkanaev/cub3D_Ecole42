/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:07:20 by dbliss            #+#    #+#             */
/*   Updated: 2020/10/28 21:09:02 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
