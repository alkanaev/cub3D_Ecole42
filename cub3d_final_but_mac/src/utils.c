#include "../cub3d.h"

int			ft_strcmp(char const *s1, char const *s2)
{
	unsigned int	i;

	i = 0;
	if (s1 == 0 || s2 == 0)
	{
		if (s1 == 0 && s2 == 0)
			return (0);
		if (s1 != 0)
			return (1);
		else
			return (-1);
	}
	while ((s1[i] != 0 || s2[i] != 0))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void		check_tex_extent(char *str, t_all *all)
{
	if (ft_check_extension(str, ".xpm") == 1)
		check_path(str, all);
	else
	{
		all->map.valid = 0;
		feedback(str, "\nError\nBad path or smth after the path\n");
	}
}

void		ft_free(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void		double_resol(char *str, t_map *map, int k)
{
	if (k == 2)
	{
		if (map->s_width == 0 && map->s_height == 0)
			floor_check(str, map);
	}
	else
	{
		map->valid = 0;
		feedback(str, "\nError\nError resol\n\n");
	}
}
