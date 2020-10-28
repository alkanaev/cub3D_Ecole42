/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:16:04 by dbliss            #+#    #+#             */
/*   Updated: 2020/10/28 21:21:10 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		int_to_char(unsigned char *c, int i)
{
	c[0] = (unsigned char)(i);
	c[1] = (unsigned char)(i >> 8);
	c[2] = (unsigned char)(i >> 16);
	c[3] = (unsigned char)(i >> 24);
}

static int		bmp_header(int fd, int h, int w, int padsize)
{
	unsigned char	header[54];
	int				filesize;

	filesize = 54 + (w * 3 * h) + (padsize * h);
	ft_bzero(header, 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	int_to_char(header + 2, filesize);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	int_to_char(header + 18, w);
	int_to_char(header + 22, h);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	return (!(write(fd, header, 54) < 0));
}

static int		bmp_data(int fd, t_all *all, int padsize)
{
	unsigned char	zero[3];
	int				x;
	int				y;
	int				pixel;

	y = all->map.s_height;
	ft_bzero(zero, 3);
	while (--y >= 0)
	{
		x = -1;
		while (++x < all->map.s_width)
		{
			pixel = *(all->data.addr_int + x + y * all->data.line_length / 4);
			if (write(fd, &pixel, 3) < 0)
				return (0);
			if (padsize > 0 && write(fd, &zero, padsize) < 0)
				return (0);
		}
	}
	return (1);
}

static int		take_screenshot(t_all *all)
{
	int		padsize;
	int		fd;

	cast_rays(all);
	padsize = (4 - ((int)all->map.s_width * 3) % 4) % 4;
	if ((fd = open("screenshot.bmp",
					O_WRONLY | O_CREAT, 0777 | O_TRUNC | O_APPEND)) < 0)
		return (0);
	bmp_header(fd, all->map.s_height, all->map.s_width, padsize);
	bmp_data(fd, all, padsize);
	close(fd);
	return (1);
}

void			make_screenshot(t_all *all)
{
	all->data.addr_int = (int *)mlx_get_data_addr(all->data.img,
			&all->data.bits_per_pixel, &all->data.line_length,
			&all->data.endian);
	take_screenshot(all);
	if (!take_screenshot(all))
		ft_putstr("ERROR\n  --Couldn't create/open screenshot.bmp--make\n");
	ft_putstr("Screenshot created!\n");
}
