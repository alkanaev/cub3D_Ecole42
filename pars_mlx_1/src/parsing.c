#include "../cub3d.h"

/*int  reading_map(char *fichier, t_map *map)
{
	int			fd;
	int			ret;
	char		*str = NULL;

	ret = 1;
	fd = open(fichier, O_RDONLY);
	if (!(map->map = malloc(sizeof(char*) * map->lines_cnt)))
		return (0);
	while (ret != 0)
	{
		ret = get_next_line(fd, &str);
		free(str);
	}
	close(fd);
	return (0);
}

void	pars_cub(char *fichier)
{
	int			fd;
	int			ret;
	t_map		map;
	char		*str = NULL;

	ret = 1;
	fd = open(fichier, O_RDONLY);
	while (ret != 0)
	{
		ret = get_next_line(fd, &str);
		chipher_rfc_valid(str, &map);
		chipher_sides_valid(str, &map);
		free(str);
	}
	close(fd);
	reading_map(fichier, &map);
}*/

int		check_format(char *str, t_map *map)
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
			feedback(str, " -  not a cub file\n");
			return (0);
		}
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b')
	{
		parser_map(str, map);
		printf("%s\n", str);
	}
		
	else
		feedback(str, " -  not a cub file\n");
	return (0);
	
}

/*int		main(int argc, char **argv)
{
	if (argc >= 2)
		check_format(argv[1]);
	else
		ft_putstr("no file given");
	parser_map(argv[1], 0, 0);
}*/