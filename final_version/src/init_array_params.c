/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_array_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:05:25 by dbliss            #+#    #+#             */
/*   Updated: 2020/10/28 21:06:54 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	*init_slice_height(t_all *all)
{
	if (!(all->pl.wall_size = (float *)malloc(sizeof(float) *
					(all->map.s_width))))
		return (NULL);
	return (all->pl.wall_size);
}

float	*init_ceiling(t_all *all)
{
	if (!(all->pl.ceiling = (float *)malloc(sizeof(float) *
					(all->map.s_width))))
		return (NULL);
	return (all->pl.ceiling);
}

float	*init_offset(t_all *all)
{
	if (!(all->cross.offset = (float *)malloc(sizeof(float) *
					(all->map.s_width))))
		return (NULL);
	return (all->cross.offset);
}
