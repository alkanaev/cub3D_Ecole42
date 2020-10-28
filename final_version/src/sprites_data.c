/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:33:15 by dbliss            #+#    #+#             */
/*   Updated: 2020/10/28 21:34:48 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_sprite	*init_sprites(t_all *all)
{
	int count;

	count = all->sprite_count;
	if (!(all->sp = malloc(sizeof(t_sprite) * (count + 1))))
		return (NULL);
	return (all->sp);
}

void		get_sprite_image_data(t_all *all)
{
	all->sprite_img.img = mlx_xpm_file_to_image(all->data.mlx,
			all->sprite_img.relative_path, &all->sprite_img.img_width,
			&all->sprite_img.img_height);
	all->sprite_img.addr = mlx_get_data_addr(all->sprite_img.img,
			&all->sprite_img.bits_per_pixel, &all->sprite_img.line_length,
			&all->sprite_img.endian);
}
