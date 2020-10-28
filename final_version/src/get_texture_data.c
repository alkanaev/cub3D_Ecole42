/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:39:13 by dbliss            #+#    #+#             */
/*   Updated: 2020/10/28 20:41:37 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		get_texture_data_north(t_all *all)
{
	all->texture[north].img = mlx_xpm_file_to_image(all->data.mlx,
			all->texture[north].relative_path, &all->texture[north].img_width,
			&all->texture[north].img_height);
	all->texture[north].addr = mlx_get_data_addr(all->texture[north].img,
			&all->texture[north].bits_per_pixel,
			&all->texture[north].line_length, &all->texture[north].endian);
}

static void		get_texture_data_south(t_all *all)
{
	all->texture[south].img = mlx_xpm_file_to_image(all->data.mlx,
			all->texture[south].relative_path, &all->texture[south].img_width,
			&all->texture[south].img_height);
	all->texture[south].addr = mlx_get_data_addr(all->texture[south].img,
			&all->texture[south].bits_per_pixel,
			&all->texture[south].line_length, &all->texture[south].endian);
}

static void		get_texture_data_east(t_all *all)
{
	all->texture[east].img = mlx_xpm_file_to_image(all->data.mlx,
			all->texture[east].relative_path, &all->texture[east].img_width,
			&all->texture[east].img_height);
	all->texture[east].addr = mlx_get_data_addr(all->texture[east].img,
			&all->texture[east].bits_per_pixel, &all->texture[east].line_length,
			&all->texture[east].endian);
}

static void		get_texture_data_west(t_all *all)
{
	all->texture[west].img = mlx_xpm_file_to_image(all->data.mlx,
			all->texture[west].relative_path, &all->texture[west].img_width,
			&all->texture[west].img_height);
	all->texture[west].addr = mlx_get_data_addr(all->texture[west].img,
			&all->texture[west].bits_per_pixel, &all->texture[west].line_length,
			&all->texture[west].endian);
}

void			init_textures(t_all *all)
{
	get_texture_data_north(all);
	get_texture_data_south(all);
	get_texture_data_east(all);
	get_texture_data_west(all);
	get_sprite_image_data(all);
}
