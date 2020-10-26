#include "../cub3d.h"

int			check_colours_range_c(t_map *map)
{
	if (map->red_c < 0 || map->green_c < 0 || map->blue_c < 0
		|| map->red_c > 255 || map->green_c > 255 || map->blue_c > 255)
		return (0);
	else
		return (1);
}

int			check_colours_range_f(t_map *map)
{
	if (map->red_f < 0 || map->green_f < 0 || map->blue_f < 0
		|| map->red_f > 255 || map->green_f > 255 || map->blue_f > 255)
		return (0);
	else
		return (1);
}

char		**take_f_c_line(char *prep_line)
{
	int		i;
	int		len;
	char	**colours_line;

	i = 0;
	len = ft_strlen(prep_line);
	while (prep_line[i] != ' ')
		i++;
	colours_line = (char **)malloc(sizeof(char *) * 3);
	if (!colours_line)
		return (NULL);
	colours_line[0] = ft_substr(prep_line, 0, i);
	colours_line[1] = ft_substr(prep_line, i, len);
	colours_line[2] = NULL;
	return (colours_line);
}

char		**get_colours_codes(char *colours_line)
{
	int		i;
	char	**colours;
	int		separator;

	i = 0;
	separator = 0;
	colours = (char **)malloc(sizeof(char *) * 1);
	if (!colours)
		return (NULL);
	colours[0] = NULL;
	while (colours_line[i])
	{
		if (colours_line[i] == ',')
			separator++;
		i++;
	}
	if (separator == 2)
	{
		free(colours);
		colours = ft_split(colours_line, ',');
	}
	return (colours);
}

int	convert_colours(int r, int g, int b)
{
	int res;

	res = r;
	res = (res << 8) | g;
	res = (res << 8) | b;
	return (res);
}