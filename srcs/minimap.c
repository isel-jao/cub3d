/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 11:23:35 by isel-jao          #+#    #+#             */
/*   Updated: 2020/10/16 11:24:39 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void render_mini_map(t_mlx *m)
{
	int tile_size = 16;
	int i;
	int j;

	if (!g_m)
		return;
	i = -1;
	double sang = m->p.rotang + m->p.fov / 2.;
	double inc = m->p.fov / m->w;
	while (++i < m->w && haswall(m, m->p.x, m->p.y) != '1')
	{
		line(m, m->p.x / 4., m->p.y / 4., m->p.x / 4. + cos(sang) * m->dist[i] / 4.,
			 m->p.y / 4. + sin(sang) * m->dist[i] / 4., 200 * RED + 200 * BLUE);
		sang -= inc;
	}
	line(m, m->p.x / 4., m->p.y / 4., m->p.x / 4. + cos(m->p.rotang) * m->dist[m->w / 2] / 4.,
		 m->p.y / 4. + sin(m->p.rotang) * m->dist[m->w / 2] / 4., 200 * BLUE);
	i = -1;
	while (m->map.map[++i])
	{
		j = -1;
		while (m->map.map[i][++j])
		{
			if (m->map.map[i][j] == '1')
				sqr(m, i * tile_size, j * tile_size, tile_size, 200 * WHITE);
			if (m->map.map[i][j] == '2' && !g_s)
				sqr(m, i * tile_size, j * tile_size, tile_size, 200 * GREEN);
		}
	}
	circle(m, m->p.x / 4., m->p.y / 4., m->p.radus / 3., 200 * RED);
}