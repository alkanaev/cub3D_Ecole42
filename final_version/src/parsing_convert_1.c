#include "../cub3d.h"

int	floor_conv(t_map *map, char	**colours, int res)
{
	map->red_f = atoi(colours[0]);
	map->green_f = atoi(colours[1]);
	map->blue_f = atoi(colours[2]);
	res = check_colours_range_f(map);
	return (res);
}

int	ceiling_conv(t_map *map, char **colours, int res)
{
	map->red_c = atoi(colours[0]);
	map->green_c = atoi(colours[1]);
	map->blue_c = atoi(colours[2]);
	res = check_colours_range_c(map);
	return (res);
}

void	floor_ceiling_work(char *str, t_map *map, char	**colours, int res, int k)
{
	if (colours[0] == NULL && linelen(colours) != 3)
	{
		feedback(str, " -  Mistake in map codes (amount) \n");
		map->valid = 0;
	}
	else if (!ft_isnumber(colours[0]) || !ft_isnumber(colours[1])
			|| !ft_isnumber(colours[2]))
	{
		feedback(str, " -  Mistake in map codes (not num) \n");
		map->valid = 0;
	}
	else
	{
		if (k == 1)
			res = floor_conv(map, colours, res);
		if (k == 2)
			res = ceiling_conv(map, colours, res);
		if (res == 0)
		{
			feedback(str, " - at least one of values not in a right range\n");
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
	int 	k;

	prep_line = ft_strtrim(str, SPACES);
	colours_line = take_f_c_line(prep_line);
	prep_line = ft_strtrim(colours_line[1], SPACES);
	if (!(prep_line))
	{
		ft_putstr("map failed");
		map->valid = 0;
	}
	res = 1;
	colours = get_colours_codes(prep_line);
	k = 1;
	floor_ceiling_work(str, map, colours, res, k);
	// if (map->valid == 1)
	// {
	// 	// map->flag += 1;
	// 	feedback(str, "colours ok\n");
	// }
	return (0);
}

int		c_converting(char *str, t_map *map)
{
	char	*prep_line;
	char	**colours_line;
	char	**colours;
	int		res;
	int 	k;

	prep_line = ft_strtrim(str, SPACES);
	colours_line = take_f_c_line(prep_line);
	prep_line = ft_strtrim(colours_line[1], SPACES);
	if (!(prep_line))
	{
		ft_putstr("map failed");
		map->valid = 0;
	}
	res = 1;
	colours = get_colours_codes(prep_line);
	k = 2;
	floor_ceiling_work(str, map, colours, res, k);
	if (map->valid == 1)
	{
		//map->flag += 1;
		feedback(str, "colours ok\n");
	}
	return (0);
}