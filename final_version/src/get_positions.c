/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:19:38 by dbliss            #+#    #+#             */
/*   Updated: 2020/10/28 20:38:13 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_player_position(t_all *all)
{
	int		y;
	size_t	x;

	y = 0;
	all->sprite_count = 0;
	while (y < (all->map.max_columns + 1))
	{
		x = 0;
		while (x < ft_strlen(all->map.map[y]))
		{
			if (all->map.map[y][x] == 'N' || all->map.map[y][x] == 'S'
					|| all->map.map[y][x] == 'E' || all->map.map[y][x] == 'W')
			{
				all->pl.x = x * SCALE + 32;
				all->pl.y = y * SCALE + 32;
			}
			if (all->map.map[y][x] == '2')
				all->sprite_count++;
			x++;
		}
		y++;
	}
}

void	get_player_direction(t_all *all)
{
	int		y;
	size_t	x;

	y = 0;
	while (y < (all->map.max_columns + 1))
	{
		x = 0;
		while (x < ft_strlen(all->map.map[y]))
		{
			if (all->map.map[y][x] == 'N' || all->map.map[y][x] == 'S'
					|| all->map.map[y][x] == 'E' || all->map.map[y][x] == 'W')
			{
				if (all->map.map[y][x] == 'N')
					all->map.dir = M_PI_2;
				else if (all->map.map[y][x] == 'S')
					all->map.dir = 3 * M_PI_2;
				else if (all->map.map[y][x] == 'W')
					all->map.dir = M_PI;
				else if (all->map.map[y][x] == 'E')
					all->map.dir = 0;
			}
			x++;
		}
		y++;
	}
}

void	get_sprite_positions(t_all *all)
{
	int		i;
	int		y;
	size_t	x;

	i = 0;
	while (i < all->sprite_count)
	{
		y = 0;
		while (y < (all->map.max_columns + 1))
		{
			x = 0;
			while (x < ft_strlen(all->map.map[y]))
			{
				if (all->map.map[y][x] == '2')
				{
					all->sp[i].x = x * SCALE + 32;
					all->sp[i].y = y * SCALE + 32;
					i++;
				}
				x++;
			}
			y++;
		}
	}
}
