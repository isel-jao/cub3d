/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:45:53 by isel-jao          #+#    #+#             */
/*   Updated: 2020/10/16 08:13:25 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

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

static int load_texture(t_mlx *m)
{
	static int i = 0;
	int tab[2];
	void *img;
	int fd;

	if (!(m->textures[i].img = mlx_xpm_file_to_image(m->mlx, m->path[i], &tab[0], &tab[1])))
	{
		ft_printf("error laoding %s\n", m->path[i]);
		return (-1);
	}
	m->textures[i].data = (int *)mlx_get_data_addr(m->textures[i].img,
												   &m->textures[i].bpp,
												   &m->textures[i].sizeline,
												   &m->textures[i].endian);
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

int check_rows(t_mlx *m)
{
	int i;
	int j;
	char **s;
	s = m->map.map;

	i = -1;
	while (s[++i])
	{
		j = 0;
		while (s[i][j])
		{
			while (s[i][j] == ' ')
				j++;
			if (s[i][j] && s[i][j] != '1')
				return (-1);
			while (s[i][j] && s[i][j] != ' ')
				j++;
			if (s[i][j - 1] != '1')
				return (-1);
		}
	}
	return (0);
}
int check_cols(t_mlx *m)
{
	int i;
	int j;
	char **s;

	s = m->map.map;
	j = -1;
	while (++j < m->map.rows)
	{
		i = 0;
		while (s[i])
		{
			while (s[i] && (j >= ft_strlen(s[i]) || s[i][j] == ' '))
				i++;
			if (s[i] && s[i][j] != '1')
				return (-1);
			while (s[i] && (j < ft_strlen(s[i]) && s[i][j] != ' '))
				i++;
			if (j < ft_strlen(s[i - 1]) && s[i - 1][j] != '1' && s[i - 1][j] != ' ')
				return (-1);
		}
	}
	return (0);
}
static void get_crmax(t_mlx *m)
{
	int i;
	int j;

	i = -1;
	while (m->map.map[++i])
	{
		if (m->map.rows < strlen(m->map.map[i]))
			m->map.rows = strlen(m->map.map[i]);
	}
	m->map.cols = i;
}

int ft_check_map(t_mlx *m)
{
	get_crmax(m);
	if (check_cols(m) || check_rows(m))
		return (ft_error(6));
	return (0);
}
