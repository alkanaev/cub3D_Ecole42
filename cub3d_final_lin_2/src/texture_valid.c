/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkanaev <alkanaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:00:40 by alkanaev          #+#    #+#             */
/*   Updated: 2020/11/04 15:00:41 by alkanaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		feedback_invalid(char *str, t_all *all)
{
	ft_putstr(str);
	all->map.valid = 0;
}

void		sprite_valid(char *str, t_all *all)
{
	int i;

	i = 0;
	if (str[i] == 'S' && str[i + 1] == ' ')
	{
		if (all->sprite_img.relative_path == NULL)
		{
			all->sprite_img.relative_path = texture_reader(str, all);
			all->map.tok = all->map.tok + 1;
		}
		else
			feedback_invalid("- Double sprite texture", all);
	}
}

void		texture_valid(char *str, t_all *all)
{
	int i;

	i = 0;
	if (str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ')
	{
		if (all->texture[east].relative_path == NULL)
		{
			all->texture[east].relative_path = texture_reader(str, all);
			all->map.tok = all->map.tok + 1;
		}
		else
			feedback_invalid("- Double texture", all);
	}
	if (str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ')
	{
		if (all->texture[west].relative_path == NULL)
		{
			all->texture[west].relative_path = texture_reader(str, all);
			all->map.tok = all->map.tok + 1;
		}
		else
			feedback_invalid("- Double texture", all);
	}
}
