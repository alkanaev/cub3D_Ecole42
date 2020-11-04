/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cub_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkanaev <alkanaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:59:59 by alkanaev          #+#    #+#             */
/*   Updated: 2020/11/04 15:00:00 by alkanaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_pass_space(char *line, int *i)
{
	while (line[*i] == ' ' || line[*i] == '\n' || line[*i] == '\t' ||
		line[*i] == '\v' || line[*i] == '\f' || line[*i] == '\r')
		(*i)++;
}

int		ft_parser_map(t_map *map, char *line, int num_str)
{
	int	i;

	i = 0;
	while (line[i])
		if (line[i] == ' ' || line[i] == '1')
			i++;
		else
			return (-1);
	map->start_map = num_str;
	return (0);
}

int		ft_parser(t_map *map, char *line, int num_str)
{
	int	i;
	int	n;

	i = 0;
	if (ft_strlen(line) == 0)
		return (-1);
	if (map->start_map < 0)
		ft_parser_map(map, line, num_str);
	if (num_str >= map->start_map)
	{
		n = ft_strlen(line);
		if (n > map->max_str)
			map->max_str = n;
	}
	ft_pass_space(line, &i);
	return (0);
}

int		parser_map2(char *fichier, t_map *map, char *line, int i)
{
	int		fd;

	fd = open(fichier, O_RDONLY);
	while (i < map->start_map)
	{
		get_next_line(fd, &line);
		i++;
		free(line);
		line = NULL;
	}
	map->height_map = map->end_map - map->start_map + 1;
	map->map = (char **)malloc(sizeof(char *) * (map->height_map + 1));
	i = 0;
	while (i < map->height_map)
	{
		get_next_line(fd, &(map->map)[i]);
		i++;
	}
	(map->map)[i] = NULL;
	if (validator_map(map) || map->dir == -1)
		return (1);
	return (0);
}

void	launch_pm2(char *fichier, t_map *map, t_all *all, char *line)
{
	if (parser_map2(fichier, map, line, 0))
	{
		feedback(fichier, "\nError\n map isn't valid\n");
		all->map.valid = 0;
	}
}
