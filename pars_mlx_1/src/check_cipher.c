#include "../cub3d.h"

void	texture_reader2(char *str, char *texture, int i, int j)
{
	while (str[j] != '\0')
	{
		texture[i] = str[j];
		i++;
		j++;
	}
	feedback(str, " - texture ok\n");
	texture[i] = '\0';
}

char	*texture_reader(char *str)
{
	int i;
	int j;
	char *texture;

	i = 0;
	j = 0;
	while (str[j] != '.')
	{
		j++;
		if (str[j] == '\0')
		{
			feedback(str, " - mistake in file\n");
			return (NULL);
		}
	}
	if (str[ft_strlen(str)-4] != '.' && str[ft_strlen(str)-3] != 'x' 
		&& str[ft_strlen(str)-2] != 'p' && str[ft_strlen(str)-1] != 'm')
	{
		feedback(str, " -  bad format\n");
		return (NULL);
	}
	if (!(texture = (malloc(sizeof(char) * (len_mod(str) + 1)))))
		return (NULL);
	texture_reader2(str, texture, i, j);
	return (texture);
}

void	chipher_sides_valid(char *str, t_map *map)
{
	int i;
	i = 0;
	if (str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ')
		map->NO = texture_reader(str);
	if (str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ')
		map->SO = texture_reader(str);
	if (str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ')
		map->WE = texture_reader(str);
	if (str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ')
		map->EA = texture_reader(str);
	if (str[i] == 'S' && str[i + 1] == ' ')
		map->S = texture_reader(str);
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
			{
				feedback(str, " -  Resol mistake\n");
			}
			else
			{
				map->resol1 = rosol_converting(str, map);
				map->resol2 = rosol_converting(str, map);
				feedback(str, " -  Resol ok\n");
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
		if (str[i] == 'R')
		{
			floor_check(str, map, k, i);
		}
		else if (str[i] == 'F')
		{
			map->F = f_c_converting(str, map);
			if (map->F != 0)
				feedback(str, " - floor's colours ok\n");
		}
		else if (str[i] == 'C')
		{
			map->C = f_c_converting(str, map);
			if (map->F != 0)
				feedback(str, " - ceiling's colours ok\n");
		}
		i++;
	}
}