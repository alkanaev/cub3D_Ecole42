#include "../cub3d.h"

int  reading_map(char *fichier, t_pars *pars)
{
	int			fd;
	int			ret;
	char		*str = NULL;

	ret = 1;
	fd = open(fichier, O_RDONLY);
	if (!(pars->map = malloc(sizeof(char*) * pars->lines_cnt)))
		return (0);
	while (ret != 0)
	{
		ret = get_next_line(fd, &str);
		//------------------------------------------------------------------------
		//if (ft_is_map(str) == 1)
		//	ft_copy_map(str, pars);
		//------------------------------------------------------------------------
		free(str);
	}
	close(fd);
	return (0);
}

void	pars_cub(char *fichier)
{
	int			fd;
	int			ret;
	t_pars		pars;
	char		*str = NULL;

	ret = 1;
	fd = open(fichier, O_RDONLY);
	while (ret != 0)
	{
		ret = get_next_line(fd, &str);
		chipher_rfc_valid(str, &pars);
		chipher_sides_valid(str, &pars);
		free(str);
	}
	close(fd);
	reading_map(fichier, &pars);
}

int		check_format(char *str)
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
		pars_cub(str);
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