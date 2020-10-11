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

void	chipher_sides_valid(char *str, t_pars *pars)
{
	int i;
	i = 0;
	if (str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ')
		pars->NO = texture_reader(str);
	if (str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ')
		pars->SO = texture_reader(str);
	if (str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ')
		pars->WE = texture_reader(str);
	if (str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ')
		pars->EA = texture_reader(str);
	if (str[i] == 'S' && str[i + 1] == ' ')
		pars->S = texture_reader(str);
}

void floor_check(char *str, t_pars *pars, int k, int i)
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
				pars->resol1 = rosol_converting(str, pars);
				pars->resol2 = rosol_converting(str, pars);
				feedback(str, " -  Resol ok\n");
			}
}

void	chipher_rfc_valid(char *str, t_pars *pars)
{
	int			i;
	int			k;

	k = 0;
	i = 0;
	pars->el = 1;
	while (str[i])
	{
		if (str[i] == 'R')
		{
			floor_check(str, pars, k, i);
		}
		else if (str[i] == 'F')
		{
			pars->F = f_c_converting(str, pars);
			if (pars->F != 0)
				feedback(str, " - floor's colours ok\n");
		}
		else if (str[i] == 'C')
		{
			pars->C = f_c_converting(str, pars);
			if (pars->F != 0)
				feedback(str, " - ceiling's colours ok\n");
		}
		i++;
	}
}
