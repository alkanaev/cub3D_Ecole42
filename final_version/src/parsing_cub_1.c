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

int		map_search(char *str) //проверка что элеиент - часть карты
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

void	cnt_map(char *str, t_map *map) // подсчет карты
{
	static int max_columns = 0;
	static int max_rows = 0;
	int k;

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
		if (map->flag == 0)
			chipher_f_valid(line, map);
		// printf("VALID OR NOT VALID FLAG: %d\n", map->valid);
		// printf("YOUR FLAG IS: %d\n", map->flag);
		else if (/*map->valid == 1 && */map->flag > 0 && map->flag < 6)
		{
			chipher_sides_valid(line, all);
			printf("YOUR FLAG IS: %d\n", map->flag);
		}
		else if (map->flag == 6 || map->flag == 7)
			chipher_rc_valid(line, map);
		else if (map->flag == 8)
			cnt_map(line, map);
		i++;
		free(line);
		line = NULL;
		// else
		// {
		// 	ft_putstr("There was a mistake in params or in a map\n");
		// }
		
	}
	// printf("TOK %d", map->tok);
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
			ft_putstr("wrong file:\n");
			all->map.valid = 0;
		}
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b')
	{
			parser_map(str, map, all);
	}
	else
	{
		feedback(str, " -  not a cub file\n");
		all->map.valid = 0;
	}
	return (0);
}