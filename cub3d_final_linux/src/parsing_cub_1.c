#include "../cub3d.h"

int		check_char(char *str, char sym)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == sym)
			return (1);
		i++;
	}
	return (0);
}

int		map_search(char *str)
{
	int i;

	i = 0;
	if (check_char(str, '1') == 1)
	{
		while (str[i] != '\0')
		{
			if (str[i] != 'N' && str[i] != 'S' && str[i] != 'W' \
				&& str[i] != 'E' && str[i] != '0' && str[i] != '1' \
				&& str[i] != '2' && str[i] != ' ')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

void	cnt_map(char *str, t_map *map)
{
	static int		max_columns;
	static int		max_rows;
	int				k;

	k = 0;
	if (map_search(str) == 1)
	{
		if ((k = ft_strlen(str)) > max_rows)
			max_rows = k;
		max_columns = max_columns + 1;
	}
	map->max_columns = max_columns;
	map->max_rows = max_rows;
}

int		parser_map(char *fichier, t_map *map, t_all *all)
{
	int		r;
	int		i;
	int		fd;
	char	*line;

	i = 0;
	line = NULL;
	fd = open(fichier, O_RDONLY);
	while ((r = get_next_line(fd, &line)) > 0)
	{
		ft_parser(map, line, i);
		chipher_rfc_valid(line, map);
		if (map->valid == 1)
			chipher_sides_valid(line, all);
		cnt_map(line, map);
		i++;
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
	map->end_map = i;
	close(fd);
	launch_pm2(fichier, map, all, line);
	return (0);
}

int		check_format(char *str, t_map *map, t_all *all)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	while (str[i] != '.')
	{
		i--;
		if (i == 0)
		{
			ft_putstr("\nError\n wrong file:\n");
			all->map.valid = 0;
		}
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b')
	{
		parser_map(str, map, all);
	}
	else
	{
		feedback(str, "\nError\n not a cub file\n");
		all->map.valid = 0;
	}
	return (0);
}
