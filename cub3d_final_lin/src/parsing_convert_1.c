/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_convert_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkanaev <alkanaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:59:36 by alkanaev          #+#    #+#             */
/*   Updated: 2020/11/04 14:59:37 by alkanaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		floor_conv(t_map *map, char **colours, int res)
{
	map->red_f = ft_atoi(colours[0]);
	map->green_f = ft_atoi(colours[1]);
	map->blue_f = ft_atoi(colours[2]);
	res = check_colours_range_f(map);
	ft_free(colours);
	return (res);
}

int		ceiling_conv(t_map *map, char **colours, int res)
{
	map->red_c = ft_atoi(colours[0]);
	map->green_c = ft_atoi(colours[1]);
	map->blue_c = ft_atoi(colours[2]);
	res = check_colours_range_c(map);
	ft_free(colours);
	return (res);
}

void	floor_ceiling_work(char *str, t_map *map, char **colours, int res)
{
	if (colours[0] == NULL && linelen(colours) != 3)
	{
		feedback(str, "Error\nMistake in map codes (amount) \n");
		map->valid = 0;
	}
	else if (!ft_isnumber(colours[0]) || !ft_isnumber(colours[1])
			|| !ft_isnumber(colours[2]))
	{
		feedback(str, "\nError\nMistake in map codes (not num) \n");
		map->valid = 0;
	}
	else
	{
		if (map->k == 1)
			res = floor_conv(map, colours, res);
		if (map->k == 2)
			res = ceiling_conv(map, colours, res);
		if (res == 0)
		{
			feedback(str, "\nError\nAt least one of val not in right range\n");
			map->valid = 0;
		}
	}
}

int		f_converting(char *str, t_map *map)
{
	char	*prep_line;
	char	**colours_line;
	char	**colours;
	int		res;

	prep_line = ft_strtrim(str, SPACES);
	colours_line = take_f_c_line(prep_line);
	free(prep_line);
	prep_line = ft_strtrim(colours_line[1], SPACES);
	ft_free(colours_line);
	if (!(prep_line))
	{
		ft_putstr("\nError\nmap failed");
		map->valid = 0;
	}
	res = 1;
	colours = get_colours_codes(prep_line);
	free(prep_line);
	map->k = 1;
	floor_ceiling_work(str, map, colours, res);
	if (map->valid == 1)
		feedback(str, " - colours ok\n");
	return (0);
}

int		c_converting(char *str, t_map *map)
{
	char	*prep_line;
	char	**colours_line;
	char	**colours;
	int		res;

	prep_line = ft_strtrim(str, SPACES);
	colours_line = take_f_c_line(prep_line);
	free(prep_line);
	prep_line = ft_strtrim(colours_line[1], SPACES);
	ft_free(colours_line);
	if (!(prep_line))
	{
		ft_putstr("\nError\nmap failed");
		map->valid = 0;
	}
	res = 1;
	colours = get_colours_codes(prep_line);
	free(prep_line);
	map->k = 2;
	floor_ceiling_work(str, map, colours, res);
	if (map->valid == 1)
		feedback(str, " - colours ok\n");
	return (0);
}
