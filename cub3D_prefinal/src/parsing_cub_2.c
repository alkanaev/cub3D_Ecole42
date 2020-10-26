#include "../cub3d.h"

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
		if (map->valid == 1)
			feedback(map->map[i], "\n");
		if (i == 0 || i == map->height_map - 1)
			validator_map_wtf30(map, i, j);
		else
			if (validator_map_wtf25(map, i, j))
				return (1);
		i++;
	}
	return (0);
}

