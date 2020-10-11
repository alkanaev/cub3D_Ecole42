#include "../cub3d.h"
#include <stdio.h> 
#include <time.h> 
 
#define type_name(expr) \
    (_Generic((expr), \
              char: "char", unsigned char: "unsigned char", signed char: "signed char", \
              short: "short", unsigned short: "unsigned short", \
              int: "int", unsigned int: "unsigned int", \
              long: "long", unsigned long: "unsigned long", \
              long long: "long long", unsigned long long: "unsigned long long", \
              float: "float", \
              double: "double", \
              long double: "long double", \
              void*: "void*", \
              default: "?")) 

/*int map_int2 [10] [10] = { // нужно обязательно найти потом макс. кол-во элементов массива
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};*/

t_map	*create_map_struct()
{
	t_map	*map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	return (map);
}

t_map	*initialization_of_structures()
{
	t_map	*map;

	map = create_map_struct();
	map->start_map = -1;
	map->end_map = -1;
	map->max_str = -1;
	map->height_map = -1;
	map->direction = -1;
	map->map = NULL;
	map->error = -1;
	return (map);
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
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (map->direction > 0)
			return (1);
		map->direction = 1;
	}
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
	/*i = 0;
	int k = 0;
	while (map->map[i])
	{
		printf("%s\n", map->map[i]);
		map->map2[i][k] = atoi(map->map[i]);
		printf("%d\n", map->map2[i][k]);
		k++;
		i++;
	}*/
	//int k = 1;
	//int l = 0;
	//int h = 0;
	//while (*map->map) printf( "%s\n", *map->map++);
	//while (*map->map) {
	//	printf( "%s\n", *map->map++);
	//	k = k+1;
	//}
	//printf( "%d\n", k);
	/*while (map->map[h]) {
		//map->map2[h][l] = ft_atoi(map->map[k]);
		while (map->map[h][l]) {
			map->map2[h][l] = map->map[h][l] - '0';
			printf( "int-%d", map->map2[h][l]);
			//printf( "-char-%c\n", map->map[h][l]);
			//printf( "--num-%d\n\n", k);
			l++;
			k++;
		}
		//k++;
		h++;
	}*/
	/*k = 0;
	h = 0;
	while (map->map2[k]) {
		while (map->map2[k][h]){
			printf("%s\n", type_name(map->map2[k][h]));
			h++;
		}
		k++;
	}*/
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

int		parser_map2(char *argv, int i, t_map *map, char *line)
{
	char	**card;
	int		fd;

	fd = open(argv, O_RDONLY);
	while (i < map->start_map)
	{
		get_next_line(fd, &line);
		i++;
	}
	map->height_map = map->end_map - map->start_map + 1;
	card = (char **)malloc(sizeof(char *) * (map->height_map + 1));
	i = 0;
	while (i < map->height_map)
	{
		card[i] = (char *)malloc(sizeof(char) * map->max_str);
		get_next_line(fd, &line);
		card[i] = line;
		i++;
	}
	card[i] = NULL;
	map->map = card;
	if (validator_map(map) || map->direction == -1)
		return (1);
	return (0);
}

int		parser_map(char *argv, int i, int fd)
{
	int		r;
	char	*line;
	t_map	*map;

	i = 0;
	line = NULL;
	map = initialization_of_structures();
	fd = open(argv, O_RDONLY);
	while ((r = get_next_line(fd, &line)) > 0)
	{
		ft_parser(map, line, i);
		i++;
		free(line);
		line = NULL;
	}
	map->end_map = i;
	close(fd);
	if (parser_map2(argv, 0, map, line))
		printf("error map");
	return (0);
}
