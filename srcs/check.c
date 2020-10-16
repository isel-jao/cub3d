/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:20:54 by isel-jao          #+#    #+#             */
/*   Updated: 2020/10/16 09:25:49 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static int load_texture(t_mlx *m)
{
	static int i = 0;
	int tab[2];

	if (!(m->textures[i].img = mlx_xpm_file_to_image(m->mlx, m->path[i], \
	&tab[0], &tab[1])))
	{
		ft_printf("error laoding %s\n", m->path[i]);
		return (-1);
	}
	m->textures[i].data = (int *)mlx_get_data_addr(m->textures[i].img, \
	&m->textures[i].bpp, &m->textures[i].sizeline, &m->textures[i].endian);
	i++;
	return (0);
}

int load_textures(t_mlx *m)
{
	int ret;
	int i;

	ret = 0;
	i = -1;
	while (!ret && ++i < 5)
	{
		ret = load_texture(m);
	}
	return (ret);
}

static double get_angel(char c)
{
	if (c == 'N')
		return (-M_PI);
	if (c == 'W')
		return (0);
	if (c == 'S')
		return (M_PI / 2.);
	return (-M_PI / 2.);
}

int ft_player(t_mlx *m)
{
	int i;
	int j;

	if (m->p_num != 1)
	{
		ft_printf("none or more than one player position!");
		return (-1);
	}
	i = -1;
	while (m->map.map[++i])
	{
		j = -1;
		while (m->map.map[i][++j])
		{
			if (m->map.map[i][j] == 'N' || m->map.map[i][j] == 'W' ||
				m->map.map[i][j] == 'S' || m->map.map[i][j] == 'E')
			{
				m->p.x = i * 64 + 32;
				m->p.y = j * 64 + 32;
				m->p.rotang = get_angel(m->map.map[i][j]);
				return (0);
			}
		}
	}
	return (0);
}

int ft_check(t_mlx *m)
{
	int ret;
	ret = 0;
	ret = ft_check_map(m);
	if (!ret)
		ret = ft_player(m);
	if (!ret)
		ret = load_textures(m);
	return (ret);
}