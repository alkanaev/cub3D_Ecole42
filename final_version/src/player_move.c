/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:09:22 by dbliss            #+#    #+#             */
/*   Updated: 2020/10/28 21:12:19 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		keycodes_wasd(int keycode, t_all *all)
{
	if (keycode == KA)
	{
		all->pl.x -= 8.23 * sin(all->map.dir);
		all->pl.y -= 8.23 * cos(all->map.dir);
	}
	else if (keycode == KS)
	{
		all->pl.x -= 8.23 * cos(all->map.dir);
		all->pl.y += 8.23 * sin(all->map.dir);
	}
	else if (keycode == KD)
	{
		all->pl.x += 8.23 * sin(all->map.dir);
		all->pl.y += 8.23 * cos(all->map.dir);
	}
	else if (keycode == KW)
	{
		all->pl.x += 8.23 * cos(all->map.dir);
		all->pl.y -= 8.23 * sin(all->map.dir);
	}
}

static void		player_move(int keycode, t_all *all)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(all->data.mlx, all->data.mlx_win);
		exit(0);
	}
	if (keycode == KA || keycode == KS || keycode == KW || keycode == KD)
		keycodes_wasd(keycode, all);
	else if (keycode == LEFT)
	{
		all->map.dir += 0.03;
		fix_angle(&all->map.dir);
	}
	else if (keycode == RIGHT)
	{
		all->map.dir -= 0.03;
		fix_angle(&all->map.dir);
	}
}

int				control_player(int keycode, t_all *all)
{
	int		i;
	int		j;
	int		x_max;
	int		y_max;

	x_max = all->pl.x;
	y_max = all->pl.y;
	player_move(keycode, all);
	i = (int)all->pl.x / SCALE;
	j = (int)all->pl.y / SCALE;
	if (all->map.map[j][i] == '1')
	{
		all->pl.x = x_max;
		all->pl.y = y_max;
	}
	return (0);
}
