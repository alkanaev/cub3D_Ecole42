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
	static int lines_cnt = 0;
	static int maxsize = 0;
	int k;

	k = 0;
	if (map_search(str) == 1)
	{
		if ((k = ft_strlen(str)) > maxsize)
			maxsize = k;
		lines_cnt = lines_cnt + 1;
	}
	map->lines_cnt = lines_cnt;
	map->maxsize = maxsize;
	//printf("%d\n", lines_cnt);
	//printf("%d\n", map->maxsize);
}


void	initialization_of_structures(t_map *map)
{
	map->start_map = -1;
	map->end_map = -1;
	map->max_str = -1;
	map->height_map = -1;
	//map->direction = -1;
	map->direction = 0;
	//исправила map->direction на ноль так как пока координаты задаются мануально в инит файле:
	map->map = NULL;
	map->error = -1;
}


int		check_cell(t_map *map, char c, int i, size_t j)
{
	if (c != 'N' && c != 'S' && c != 'W' && c != 'E' && c != '0' && c != '2')
	{
		if (c == '1' || c == ' ')
			return (0);
		else
			return (1);
	}
	/*if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (map->direction > 0)
			return (1);
		map->direction = 1;
	}*/
	if (map->map[i][j + 1] == ' ' || map->map[i][j - 1] == ' ' \
		|| map->map[i + 1][j] == ' ' || map->map[i - 1][j] == ' ')
		return (1);
	if (!(map->map[i - 1][j]) || !(map->map[i + 1][j]))
		return (1);
	return (0);
}

int check_edge_end(t_map *map, int i, int up)
{
    int j;

    up = 0;
    j = ft_strlen(map->map[i]) - 1;
    while(j >= 0 && map->map[i][j] != '0')
    {
        if(map->map[i - 1][j] == '1')
            up++;
        if(up == 0 && map->map[i - 1][j] == '0')
            return (1);
        j--;
    }
    if(up == 0)
        return (1);
    return (0);
}

int check_edge_origin(t_map *map, int i)
{
    int j;
    int up;

    j = 0;
    up = 0;
    if(i == 0)
        return (0);
    while(map->map[i][j] && map->map[i][j] != '0')
    {
        if(map->map[i][j] == ' ')
        {    
            j++;
            continue;
        }
        if(map->map[i - 1][j] == '1')
            up++;
        if(up == 0 && map->map[i - 1][j] == '0')
            return (1);
        j++;
    }
    if(up == 0)
        return (1);
    if(check_edge_end(map, i, up))
        return (1);
    return (0);
}

int		validator_map_wtf30(t_map *map, int i, size_t j)
{
	while (map->map[i][j])
	{
		if (map->map[i][j] == '1' || map->map[i][j] == ' ')
			j++;
		else
			return (1);
	}
	return (0);
}

int		validator_map_wtf25(t_map *map, int i, size_t j)
{
	j++;
	while (j < ft_strlen(map->map[i]))
	{
		if (check_cell(map, map->map[i][j], i, j))
			return (1);
		j++;
	}
	if (check_edge_origin(map, i))
            return (1);
        i++;
	return (0);
}

int		validator_map(t_map *map)
{
	int		i;
	size_t	j;

	i = 0;
	while (map->map[i])
	{
		if (map->map[i][0] != ' ' && map->map[i][0] != '1')
			return (1);
		if (map->map[i][ft_strlen(map->map[i]) - 1] != ' ' \
			&& map->map[i][ft_strlen(map->map[i]) - 1] != '1')
			return (1);
		j = 0;
		printf("%s\n", map->map[i]);
		if (i == 0 || i == map->height_map - 1)
			validator_map_wtf30(map, i, j);
		else
			if (validator_map_wtf25(map, i, j))
				return (1);
		i++;
	}
	return (0);
}

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

int		parser_map2(char *fichier, t_map *map, char *line, int i)// (char *argv, int i, t_map *map, char *line) // reading_map
{
	// char	**card;
	int		fd;

	fd = open(fichier, O_RDONLY);
	while (i < map->start_map)
	{
		get_next_line(fd, &line);
		i++;
	}
	map->height_map = map->end_map - map->start_map + 1;
	map->map = (char **)malloc(sizeof(char *) * (map->height_map + 1));
	i = 0;
	while (i < map->height_map)
	{
		(map->map)[i] = (char *)malloc(sizeof(char) * map->max_str);
		get_next_line(fd, &(map->map)[i]);
		// card[i] = line;
		i++;
	}
	(map->map)[i] = NULL;
	// map->map = card;
	if (validator_map(map) || map->direction == -1)
		return (1);
	return (0);
}

int		parser_map(char *fichier, t_map *map)//pars_cub
{
	int		r;
	int i;
	int			fd;
	char	*line;
	//char		*str = NULL;

	i = 0;
	line = NULL;
	//map = initialization_of_structures();
	fd = open(fichier, O_RDONLY);
	while ((r = get_next_line(fd, &line)) > 0)
	{
		ft_parser(map, line, i);
		//chipher_rfc_valid(str, map);
		//chipher_sides_valid(str, map);
		cnt_map(line, map);
		i++;
		free(line);
		line = NULL;
	}
	printf("%d\n", map->maxsize);
	printf("%d\n", map->lines_cnt);
	map->end_map = i;
	close(fd);
	if (parser_map2(fichier, map, line, 0))
		feedback(fichier, " -  parser_map_gives_mistake\n\n\n\n");
	// printf("%c\n", map->map[2][0]);
	// printf("%c\n", map->map[2][1]);
	// printf("%c\n", map->map[2][2]);
	// printf("%c\n", map->map[2][3]);
	// printf("%c\n", map->map[2][4]);
	/*checking what was parsed into map // 
	int k = 0;
	while (map->map[k])
	{
		printf("%c\n", map->map[k][8]);
		k++;
	}*/
	return (0);
}