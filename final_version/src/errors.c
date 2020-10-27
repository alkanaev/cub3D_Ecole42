#include "../cub3d.h"

int		len_mod(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '.')
		i++;
	while (str[i])
	{
		i++;
		j++;
	}
	return (j);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int			linelen(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			ft_isnumber(char *str)
{
	int		i;
	char	*no_space;
	char	*white_spaces;

	white_spaces = " \t\n\v\f\r";
	no_space = ft_strtrim(str, white_spaces);
	i = 0;
	if (!no_space || no_space[i] == '\0')
	{
		free(no_space);
		return (0);
	}
	if (no_space[i] == '-')
		i++;
	while (no_space[i])
	{
		if (no_space[i] < '0' || no_space[i] > '9')
		{
			free(no_space);
			return (0);
		}
		i++;
	}
	free(no_space);
	return (1);
}

void    feedback(char *str, char *feedback)
{
	ft_putstr(str);
    ft_putstr(feedback);
}