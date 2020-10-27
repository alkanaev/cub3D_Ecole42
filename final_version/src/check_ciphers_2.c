#include "../cub3d.h"

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
		if (map->dir > 0)
			return (1);
		map->dir = 1;
	}
	if (map->map[i][j + 1] == ' ' || map->map[i][j - 1] == ' ' \
		|| map->map[i + 1][j] == ' ' || map->map[i - 1][j] == ' ')
		return (1);
	if (!(map->map[i - 1][j]) || !(map->map[i + 1][j]))
		return (1);
	return (0);
}

int		rosol_converting(const char *str, t_map *map)
{
	int signe;
	int sum;

	sum = 0;
	signe = 1;
	while (str[map->el] == ' ' || str[map->el] == '\t'
			|| str[map->el] == ',' || str[map->el] == '\n'
			|| str[map->el] == '\r' || str[map->el] == '\v'
			|| str[map->el] == '\f')
		map->el++;
	if (str[map->el] == '-' || str[map->el] == '+')
	{
		if (str[map->el] == '-')
			signe = -1;
		map->el++;
	}
	while (str[map->el] >= '0' && str[map->el] <= '9')
	{
		sum = (sum * 10) + (str[map->el] - 48);
		map->el++;
	}
	return (sum * signe);
}

void floor_check(char *str, t_map *map, int k, int i)
{
	while (str[i])
	{
		if (str[i] == ' ')
			k++;
		i++;
	}
	if (k != 2)
		feedback(str, " -  Resol mistake\n");
	else
	{
		// if (map->s_width != 0 || map->s_height != 0)
		// {
		// 	map->valid = 0;
		// 	feedback(str, " -  double resol\n\n");
		// }
		map->s_width = rosol_converting(str, map);
		map->s_height = rosol_converting(str, map);
		if ((map->s_width > 0) && (map->s_height > 0))
			feedback(str, " -  Resol ok\n\n");
		else
		{
			feedback(str, " -  Resol error\n");
			map->valid = 0;
		}
	}
}

void	chipher_rfc_valid(char *str, t_map *map)
{
	int			i;
	int			k;

	k = 0;
	i = 0;
	map->el = 1;
	while (str[i])
	{
		if (str[i] == 'R' && str[i + 1] == ' ')
			floor_check(str, map, k, i);
		if (str[i] == 'F')
		{
			if (f_converting(str, map) == 0)
				map->Fint = convert_colours(map->red_f, map->green_f, map->blue_f);
		}
		if (str[i] == 'C')
		{
			if (c_converting(str, map) == 0)
				map->Cint = convert_colours(map->red_c, map->green_c, map->blue_c);
		}
		i++;
	}
}