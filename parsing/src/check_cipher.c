#include "../cub3d.h"

char	*texture_reader(char *str)
{
	int i;
	int j;
	int k;
	char *texture;

	i = 0;
	j = 0;
	while (str[j] != '.')
	{
		j++;
		if (str[j] == '\0')
		{
			printf("%s", str);
			printf(" - mistake in file\n");
			return (NULL);
		}
	}
	k = j+1;
	/*printf("___________________________________________\n");
	printf("%c\n", str[j]);
	printf("%c\n", str[k]);
	printf("___________________________________________\n");*/
	while (str[k] != '.')
	{
		k++;
		if (str[k] == '.' && str[k + 1] != 'x')
		{
			printf("%s", str);
			printf(" -  bad format\n");
			return (NULL);
		}
		if (str[j] == '\0')
		{
			printf("%s", str);
			printf(" - mistake in file\n");
			return (NULL);
		}
	}
	if (!(texture = (malloc(sizeof(char) * (len_mod(str) + 1)))))
		return (NULL);
	while (str[j] != '\0')
	{
		texture[i] = str[j];
		i++;
		j++;
	}
	printf("%s", str);
	printf(" - texture ok\n");
	texture[i] = '\0';
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
	while (str[i] != '\0')
			{
				if (str[i] == ' ')
					k++;
				i++;
			}
			if (k != 2)
			{
				printf("%s", str);
				printf(" - Resol mistake\n");
			}
			else
			{
				pars->resol1 = rosol_converting(str, pars);
				pars->resol2 = rosol_converting(str, pars);
				printf("%s", str);
				printf(" - Resol ok\n");
			}
}

void	chipher_fc_valid(char *str, t_pars *pars)
{
	int			i;
	int			k;

	k = 0;
	i = 0;
	pars->el = 1;
	while (str[i] != '\0')
	{
		if (str[i] == 'R')
		{
			floor_check(str, pars, k, i);
		}
		else if (str[i] == 'F')
		{
			pars->F = f_c_converting(str, pars);
			printf("%s", str);
			printf(" - checked\n");
		}
		else if (str[i] == 'C')
		{
			pars->C = f_c_converting(str, pars);
			printf("%s", str);
			printf(" - checked\n");
		}
		i++;
	}
}
