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

void	chipher_sides_valid(char *str, t_all *all)
{
	int i;
	i = 0;
	if (str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ')
		all->texture[north].no_path = texture_reader(str);
		//all->map.no_path = texture_reader(str);
		
	if (str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ')
		all->texture[south].so_path = texture_reader(str);
		//all->map.so_path = texture_reader(str);
		
	if (str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ')
		all->texture[west].we_path = texture_reader(str);
		//all->map.we_path = texture_reader(str);
		
	if (str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ')
		all->texture[east].ea_path = texture_reader(str);
		//all->map.ea_path = texture_reader(str);
		
	if (str[i] == 'S' && str[i + 1] == ' ')
		all->sprite_img.spr = texture_reader(str);
		
}

void floor_check(char *str, t_map *map, int k, int i)
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
				resol_init(map);
				printf("map->resol1 is now by default : %d\n", map->resol1);
				printf("map->resol1 is now by default : %d\n\n", map->resol2);
			}
			else
			{
				map->resol1 = rosol_converting(str, map);
				printf("map->resol1 in structures : %d\n", map->resol1);
				map->resol2 = rosol_converting(str, map);
				printf("map->resol1 in structures : %d\n", map->resol2);
				if ((map->resol1 > 0) && (map->resol2 > 0))
					feedback(str, " -  Resol ok\n\n");
				else
				{
					feedback(str, " -  Resol error // Making default resol\n");
					resol_init(map);
					printf("map->resol1 is now by default !!!!! : %d\n", map->resol1);
					printf("map->resol1 is now by default !!!!! :%d\n\n", map->resol2);
				}
			}
}

char *ft_itoa_h(int nb)
{
 int nb_tmp;
 char *str;
 int len = 0;

 nb_tmp = nb;
 if (nb == 0)
  len++;
 while (nb_tmp > 0)
 {
  nb_tmp /= 16;
  len++;
 }
 if(!(str = malloc(sizeof(*str) * (len + 1))))
  return (NULL);
 str[len] = '\0';
 while (len > 0)
 {
  str[len - 1] = nb % 16;
  if (nb % 16 > 9)
   str[len - 1] += 87;
  else
   str[len - 1] += '0';
  nb /= 16;
  len--;
 }
 return(str);
}

void	chipher_rfc_valid(char *str, t_map *map)
{
	int			i;
	int			k;

	k = 0;
	i = 0;
	map->el = 1;
	while (str[i])
	{
		if (str[i] == 'R')
		{
			floor_check(str, map, k, i);
		}
		// else if (str[i] == 'F')
		if (str[i] == 'F')
		{
			if (f_converting(str, map) == 0)
			{
				map->Fint = convert_colours(map->red_f, map->green_f, map->blue_f);
				map->Fhex = ft_itoa_h(map->Fint);
			}
			//if (map->F != 0)
			//	feedback(str, " - floor's colours ok\n");
		}
		else if (str[i] == 'C')
		if (str[i] == 'C')
		{
			if (c_converting(str, map) == 0)
			{
				map->Cint = convert_colours(map->red_c, map->green_c, map->blue_c);
				map->Chex = ft_itoa_h(map->Cint);
			}
			//if (map->F != 0)
			//	feedback(str, " - ceiling's colours ok\n");
		}
		i++;
	}

}