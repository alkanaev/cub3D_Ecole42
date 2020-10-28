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

void	check_path(char *str, t_all *all)
{
	char **res;
	int ret;

	res = ft_split(str, ' ');
	ret = open(res[1], O_RDONLY);
	if (ret < 0)
	{
		feedback(str, " - wrong file\n");
		all->map.valid = 0;
	}
	close(ret);
}

char	*texture_reader(char *str, t_all *all)
{
	int i;
	int j;
	char *texture;

	i = 0;
	j = 0;
	check_path(str, all);
	while (str[j] != '.')
	{
		j++;
		if (str[j] == '\0')
		{
			feedback(str, " - mistake in file\n");
			all->map.valid = 0;
		}
	}
	if (!(texture = (malloc(sizeof(char) * (len_mod(str) + 1)))))
	{
		feedback(str, " - malloc ptoblems\n");
		all->map.valid = 0;
	}
	if (all->map.valid == 1)
		texture_reader2(str, texture, i, j);
	return (texture);
}

void	chipher_sides_valid(char *str, t_all *all)
{
	int i;
	i = 0;
	if (all->map.rok == 1)
	{
		if (str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ')
		{
			all->texture[north].relative_path = texture_reader(str, all);
			all->map.tok = all->map.tok + 1;
		}
		if (str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ')
		{
			all->texture[south].relative_path = texture_reader(str, all);
			all->map.tok = all->map.tok + 1;
		}
		if (str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ')
		{
			all->texture[west].relative_path = texture_reader(str, all);
			all->map.tok = all->map.tok + 1;
		}
		if (str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ')
		{
			all->texture[east].relative_path = texture_reader(str, all);
			all->map.tok = all->map.tok + 1;
		}
		if (str[i] == 'S' && str[i + 1] == ' ')
		{
			all->sprite_img.relative_path = texture_reader(str, all);
			all->map.tok = all->map.tok + 1;
		}
		// else
		// 	all->map.valid = 0;
			// printf("MAP VAL %d\n", all->map.valid);
		
	}
	// else
	// 		all->map.valid = 0;

}