/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:27:09 by isel-jao          #+#    #+#             */
/*   Updated: 2020/10/16 11:55:41 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int in_map(t_mlx *m, double x, double y)
{
	if (x <= 0 || y <= 0 || x >= 64 * m->map.cols || y >= 64 * m->map.rows ||
		!m->map.map[(int)(x / 64)][(int)(y / 64)] || m->map.map[(int)(x / 64)][(int)(y / 64)] == ' ')
		return (0);
	return (1);
}

void renderwall(t_mlx *m, int fact, int col, double d, int side)
{
	int start = m->h / 2. - d;
	int i;
	double index;

	i = start < 0 ? -start : 0;
	while (i < 2 * d && start + i < m->h - 1)
	{
		index = 32. / d * (double)i;
		m->img.data[(start + i) * m->w + col] =
			m->textures[side].data[(int)index * 64 + fact];
		i++;
	}
}

void update_player(t_mlx *m)
{
	double incx;
	double incy;

	m->p.rotang -= m->p.turndir;
	m->p.step = m->p.upmoove * m->p.speed;
	incx = cos(m->p.rotang) * m->p.upmoove * m->p.speed + sin(m->p.rotang) * m->p.rightmove * m->p.speed;
	incy = sin(m->p.rotang) * m->p.upmoove * m->p.speed - cos(m->p.rotang) * m->p.rightmove * m->p.speed;
	normlize(&m->p.rotang);
	if (haswall(m, m->p.x + incx, m->p.y) != '1')
		// if (in_map(m, m->p.x + incx, m->p.y))
		m->p.x = m->p.x + incx;
	if (haswall(m, m->p.x, m->p.y + incy) != '1')
		// if (in_map(m, m->p.x, m->p.y + incy))
		m->p.y = m->p.y + incy;
}

void randerfloorceil(t_mlx *m)
{
	int x;
	int y;

	x = -1;
	while (++x <= m->h / 2)
	{
		y = -1;
		while (++y < m->w)
			m->img.data[x * m->w + y] = m->cielcol;
	}
	while (++x < m->h)
	{
		y = -1;
		while (++y < m->w)
			m->img.data[x * m->w + y] = m->floorcol;
	}
}

void render_walls(t_mlx *m)
{
	t_ray ray;
	int fact;
	double d;
	int col;

	ray.ang = m->p.rotang + (m->p.fov / 2.);
	normlize(&ray.ang);
	col = -1;
	while (++col < m->w)
	{
		m->dist[col] = Wallcast(m, &ray, &fact);
		d = m->h * 64. / m->dist[col] / cos(ray.ang - m->p.rotang);
		if (ray.wallside == V && is_up(ray.ang))
			renderwall(m, fact, col, d, 0);
		if (ray.wallside == V && !is_up(ray.ang))
			renderwall(m, fact, col, d, 1);
		if (ray.wallside == H && is_right(ray.ang))
			renderwall(m, fact, col, d, 2);
		if (ray.wallside == H && !is_right(ray.ang))
			renderwall(m, fact, col, d, 3);
		ray.ang -= m->p.fov / m->w;
	}
}
