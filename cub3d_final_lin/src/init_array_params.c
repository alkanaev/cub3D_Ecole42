/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_array_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkanaev <alkanaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:59:09 by alkanaev          #+#    #+#             */
/*   Updated: 2020/11/04 14:59:10 by alkanaev         ###   ########.fr       */
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
