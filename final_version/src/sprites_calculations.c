/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_calculations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:28:24 by dbliss            #+#    #+#             */
/*   Updated: 2020/10/28 21:32:59 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float				compute_delta_angle(float fov_start, float sprite_dir)
{
	float delta;

	delta = fov_start - sprite_dir;
	if (delta <= -M_PI)
		delta = 2 * M_PI + delta;
	else if (delta >= M_PI)
		delta = delta - 2 * M_PI;
	return (delta);
}

static void			ft_swap(t_sprite *xp, t_sprite *yp)
{
	t_sprite	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

t_sprite			**sort_sprites(t_all *all)
{
	int j;
	int count;
	int i;

	count = all->sprite_count;
	i = 0;
	while (i < count - 1)
	{
		j = 0;
		while (j < count - i - 1)
		{
			if (all->sp[j].dist < all->sp[j + 1].dist)
			{
				ft_swap(&all->sp[j], &all->sp[j + 1]);
			}
			j++;
		}
		i++;
	}
	return (&all->sp);
}
