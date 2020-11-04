#include "../cub3d.h"

void		texture_reader2(char *str, char *texture, int i, int j)
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

int			ft_check_extension(char *file_name, char *valid_ext)
{
	int		name_size;
	int		ext_size;
	char	*temp;
	int		res;

	res = 0;
	name_size = ft_strlen(file_name);
	ext_size = ft_strlen(valid_ext);
	temp = ft_substr(file_name, (name_size - ext_size), name_size);
	if (ft_strcmp(temp, valid_ext) == 0)
		res = 1;
	free(temp);
	return (res);
}

void		check_path(char *str, t_all *all)
{
	char	**res;
	int		ret;

	res = ft_split(str, ' ');
	ret = open(res[1], O_RDONLY);
	if (ret < 0 || ft_check_extension(res[1], ".xpm") != 1)
	{
		feedback(str, "\nError\nWrong file\n");
		all->map.valid = 0;
	}
	ft_free(res);
	close(ret);
}

char		*texture_reader(char *str, t_all *all)
{
	int		i;
	int		j;
	char	*texture;

	i = 0;
	j = 0;
	check_tex_extent(str, all);
	while (str[j] != '.')
	{
		j++;
		if (str[j] == '\0')
			all->map.valid = 0;
	}
	if (!(texture = (malloc(sizeof(char) * (len_mod(str) + 1)))))
		all->map.valid = 0;
	if (all->map.valid == 1)
		texture_reader2(str, texture, i, j);
	return (texture);
}

void		chipher_sides_valid(char *str, t_all *all)
{
	int i;

	i = 0;
	if (str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ')
	{
		if (all->texture[north].relative_path == NULL)
		{
			all->texture[north].relative_path = texture_reader(str, all);
			all->map.tok = all->map.tok + 1;
		}
		else
			feedback_invalid("- Double texture", all);
	}
	if (str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ')
	{
		if (all->texture[south].relative_path == NULL)
		{
			all->texture[south].relative_path = texture_reader(str, all);
			all->map.tok = all->map.tok + 1;
		}
		else
			feedback_invalid("- Double texture", all);
	}
	texture_valid(str, all);
	sprite_valid(str, all);
}
