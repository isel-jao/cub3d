/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:27:09 by isel-jao          #+#    #+#             */
/*   Updated: 2020/02/27 12:50:27 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cube3d.h"

int			is_up(double ang)
{
	if(ang > 1.57079632679  && ang < 4.71238898038)
		return (1);
	return (0);
}

int			is_right(double ang)
{
	if(ang >= 0  && ang < 3.14159265359)
		return (1);
	return (0);
}

void		renderwall(t_mlx *m,int fact, int col, double d, int side)
{
	int	start = m->h / 2. - d;
	int i;
	double index;
	int color;

	i = -1;
	while (++i < 2 * d)
	{
		index = 32. / d * (double)i;
		if (start + i >= 0 && start + i <= m->h)
			m->img.data[(start + i) * m->w + col ] = \
			m->textures[side].data[ (int)index * 64 + fact];
		// line(m, ft_max(start + i -1 , 0), col, ft_min(start + i, m->h -1), col, 200 * WHITE);
	}
}



void		update_player(t_mlx *m)
{
	t_ray ray;
	double new_x;
	double new_y;
	double cast;

	m->p.step = m->p.upmoove * m->p.speed;
	m->p.rotang -= m->p.turndir;
	new_x = m->p.x + cos(m->p.rotang) * m->p.step;
	new_y = m->p.y + sin(m->p.rotang) * m->p.step;
	normlize(&m->p.rotang);
	if (haswall(m, new_x, m->p.y) != '1')
		m->p.x = new_x;
	if (haswall(m, m->p.x, new_y) != '1')
		m->p.y = new_y;
	
}



void	put_mini_map(t_mlx *m)
{
	int tile_size = 8;
	int i;
	int j;
	
	i = -1;
	while  (++i < m->map.cols)
	{
		j = -1;
			while (++j < m->map.rows)
			{
				int tile_x = i * tile_size; 
				int tile_y = j * tile_size;
				if (m->map.map[i][j] == '1')
					sqr(m,i * tile_size,j * tile_size, tile_size, 200 * WHITE);
				if (m->map.map[i][j] == '2')
					sqr(m,i * tile_size,j * tile_size, tile_size, 200 * YELLOW);
			}
		}
	circle(m, m->p.x / 8., m->p.y / 8., m->p.radus / 6., 200 * RED);
	line(m, m->p.x / 8., m->p.y / 8., m->p.x / 8. + cos(m->p.rotang) * 10., \
	m->p.y / 8. + sin(m->p.rotang) * 10., 200 * RED);
}

void	randerfloorceil(t_mlx *m)
{
	int x;
	int y;

	int color;
	x = -1;
	while (++x < m->h / 2)
	{
		y = -1;
		while (++y < m->w - 1)
			m->img.data[x * m->w + y ] =  m->floorcol;
		
	}
	while (++x < m->h)
	{
		y = -1;
		while (++y < m->w - 1)
			m->img.data[x * m->w + y ] = m->cielcol;
	}
}

void	ray_render(t_mlx *m)
{
	t_ray ray;
	int fact;
	double d;
	int col;

	m->dist = malloc(sizeof(double) * (m->w + 1));
	ray.ang = m->p.rotang + (m->p.fov / 2.);
	normlize(&ray.ang);
		randerfloorceil(m);
	if (haswall(m, m->p.x, m->p.y) != '1')
	{
			// printf ("%s   line %d w = %d col = %d \n", __FILE__, __LINE__, m->w, col);
		col = -1;
		while (++col < m->w)
		{
			m->dist[col]= wallcast(m, &ray,&fact);
			d = m->h * 64. / m->dist[col] / cos(ray.ang - m->p.rotang);
			if(ray.wallside == V && is_up(ray.ang))
				renderwall(m,fact, col, d, 0);					
			if(ray.wallside == V && !is_up(ray.ang))
				renderwall(m,fact, col, d, 1);					
			if (ray.wallside == H && is_right(ray.ang))
				renderwall(m,fact, col, d, 2);
			if (ray.wallside == H && !is_right(ray.ang))
				renderwall(m,fact, col, d, 3);
			ray.ang -= m->p.fov / m->w ;
		}
	}
}
// printf ("%s   line %d\n", __FILE__, __LINE__);

