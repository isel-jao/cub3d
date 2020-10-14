/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:44:08 by asegovia          #+#    #+#             */
/*   Updated: 2020/10/14 10:08:04 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void bmp_image(t_mlx *m, int fd)
{
	int y;
	int x;
	int size;

	y = 0;
	size = m->w * (m->h);
	while (y <= m->h)
	{
		ft_printf("%c%c%c", 8, 8, 8, 8);
		ft_printf("%02d%%", 100 * y / m->h);
		x = 0;
		while (x < m->w)
		{
			write(fd, &m->img.data[size - (y * m->w + m->w - x)],
				  4);
			x++;
		}
		y++;
	}
}

void bmp_header(t_mlx *m, int fd)
{
	int header_size;
	int plane;
	int i;

	header_size = 40;
	plane = 1;
	write(fd, &header_size, 4);
	write(fd, &m->w, 4);
	write(fd, &m->h, 4);
	write(fd, &plane, 2);
	write(fd, &m->img.bpp, 2);
	i = 0;
	while (i++ < 32)
	{
		write(fd, "\0", 1);
	}
}

void creat_bmp(t_mlx *m)
{
	int size;
	int fd;
	int empty;

	fd = 0;
	size = 0;
	empty = 54;
	fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0640);
	size = 54 + (4 * (m->w * m->h));
	write(fd, "BM", 2);
	write(fd, &size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &empty, 4);
	bmp_header(m, fd);
	bmp_image(m, fd);
	close(fd);
}

void save_bmp(t_mlx *m, int ac, char **av)
{

	if (ac < 2 || ft_strcmp(av[2], "--save"))
		return;
	ft_printf("creating save.pmp        ");
	randerfloorceil(m);
	render_walls(m);
	render_sprites(m);
	render_mini_map(m);
	creat_bmp(m);
	ft_printf("\ndone\n");
	ft_exit(m);
}