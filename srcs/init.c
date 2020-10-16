/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 01:54:13 by isel-jao          #+#    #+#             */
/*   Updated: 2020/10/16 09:59:10 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void unit_mlx(t_mlx *m)
{
	int i;

	m->w = 0;
	m->h = 0;
	m->p_num = 0;
	m->s_num = 0;
	m->tab = NULL;
	m->tab = NULL;
	m->mlx = NULL;
	m->win = NULL;
	m->spr = NULL;
	m->map.map = NULL;
	m->dist = NULL;
	i = -1;
	g_s = 0;
	g_m = 0;
	while (++i < 7)
	{
		m->path[i] = NULL;
		m->textures[i].img = NULL;
		m->textures[i].data = NULL;
		m->path[i] = NULL;
	}
}

int init_env(t_mlx *m)
{
	m->p.radus = 40;
	m->p.turndir = 0;
	m->p.upmoove = 0;
	m->p.rightmove = 0;
	m->p.speed = 2.0;
	m->p.rotspeed = 0.5 * M_PI / 180.;
	m->p.fov = M_PI / 3.;
	m->p.radus = 24;
	m->p.dir = 9;
	m->dist = malloc(sizeof(double) * (m->w + 1));
	m->spr = malloc(sizeof(t_sprite) * (m->s_num + 1));

	return (0);
}

void init_image(t_mlx *m, int ac, char **av)
{
	m->img.img = mlx_new_image(m->mlx, m->w, m->h);
	m->img.data = (int *)mlx_get_data_addr(m->img.img, \
	&(m->img.bpp), &(m->img.sizeline), &(m->img.endian));
	save_bmp(m,ac, av);
	m->win = mlx_new_window(m->mlx, m->w, m->h, "cube3D");
}