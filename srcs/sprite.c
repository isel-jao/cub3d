/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:51:46 by isel-jao          #+#    #+#             */
/*   Updated: 2020/10/16 13:00:28 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static	void	swap_sprite(t_sprite *a, t_sprite *b)
{
	double tmp;

	tmp = b->dist;
	b->dist = a->dist;
	a->dist = tmp;
	tmp = b->pos.x;
	b->pos.x = a->pos.x;
	a->pos.x = tmp;
	tmp = b->pos.y;
	b->pos.y = a->pos.y;
	a->pos.y = tmp;
}

static	void	ft_selection_sort(t_mlx *m, t_sprite *s)
{
	int i;
	int j;
	int ind;

	i = -1;
	while (++i < m->s_num)
	{
		ind = i;
		j = i;
		while (++j < m->s_num)
			if (s[ind].dist < s[j].dist)
				ind = j;
		swap_sprite(&s[i], &s[ind]);
	}
}

static	void	ft_sdraw(t_mlx *m, t_sprite s, int col, int ind)
{
	int i;
	int j;
	int w_loc;
	int h_loc;

	w_loc = (int)(m->w * (0.5 + s.ang / 1.0471975512) - s.w / 2.);
	i = w_loc < 0 ? -w_loc : 0;
	while (i < s.w && w_loc + i < m->w)
	{
		h_loc = (int)(m->h / 2. - s.h / 2.);
		j = h_loc < 0 ? -h_loc : 0;
		while (j < s.h && h_loc + j < m->h)
		{
			col = 64 * floor(64 * (double)j / s.h) + (double)i / s.w * 64;
			col = m->textures[4].data[col];
			ind = (h_loc + j) * m->w + w_loc + i;
			if (ind > 0 && ind < m->w * m->h && s.dist < m->dist[w_loc + i])
				m->img.data[ind] = col == NONE ? m->img.data[ind] : col;
			j++;
		}
		i++;
	}
}

static	void	render_sprite(t_mlx *m, t_sprite *s)
{
	int i;

	i = -1;
	while (++i < m->s_num)
	{
		s[i].dir.x = (s[i].pos.x - m->p.x) / s[i].dist;
		s[i].dir.y = (s[i].pos.y - m->p.y) / s[i].dist;
		if (s[i].dir.y >= 0)
			s[i].ang = acos(s[i].dir.x);
		else
			s[i].ang = -acos(s[i].dir.x);
		s[i].ang = m->p.rotang - s[i].ang;
		s[i].h = m->h * 128. / s[i].dist;
		s[i].w = m->w * 64. / s[i].dist;
		if (s[i].ang < -M_PI)
			s[i].ang += (2.0000 * M_PI);
		if (s[i].ang > M_PI)
			s[i].ang -= (2 * M_PI);
		ft_sdraw(m, s[i], 0, 0);
	}
}

void			render_sprites(t_mlx *m)
{
	int i;
	int j;
	int c;

	i = -1;
	c = 0;
	while (++i < m->map.cols)
	{
		j = -1;
		while (m->map.map[i][++j])
		{
			if (m->map.map[i][j] == '2')
			{
				m->spr[c].pos.x = (double)i * 64 + (double)64 / 2.;
				m->spr[c].pos.y = (double)j * 64 + (double)64 / 2.;
				m->spr[c].dist = sqrt(pow(m->spr[c].pos.x - m->p.x, 2) \
				+ pow(m->spr[c].pos.y - m->p.y, 2));
				c++;
			}
		}
	}
	ft_selection_sort(m, m->spr);
	render_sprite(m, m->spr);
}
