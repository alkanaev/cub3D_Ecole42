#include "../cub3d.h"

int		len_mod(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '.')
		i++;
	while (str[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

int		rosol_converting(const char *str, t_pars *pars)
{
	int signe;
	int sum;

	sum = 0;
	signe = 1;
	while (str[pars->el] == ' ' || str[pars->el] == '\t'
			|| str[pars->el] == ',' || str[pars->el] == '\n'
			|| str[pars->el] == '\r' || str[pars->el] == '\v'
			|| str[pars->el] == '\f')
		pars->el++;
	if (str[pars->el] == '-' || str[pars->el] == '+')
	{
		if (str[pars->el] == '-')
			signe = -1;
		pars->el++;
	}
	while (str[pars->el] >= '0' && str[pars->el] <= '9')
	{
		sum = (sum * 10) + (str[pars->el] - 48);
		pars->el++;
	}
	return (sum * signe);
}

int		f_c_converting(const char *str, t_pars *pars)
{
	int sum;
	sum = 0;
	while (str[pars->el] == ' ' || str[pars->el] == '\t'
			|| str[pars->el] == ',' || str[pars->el] == '\n'
			|| str[pars->el] == '\r' || str[pars->el] == '\v'
			|| str[pars->el] == '\f')
	{
		pars->el++;
		while (str[pars->el] >= '0' && str[pars->el] <= '9')
		{
			sum = (sum * 10) + (str[pars->el] - 48);
			pars->el++;
		}
	}
	return (sum);
}
