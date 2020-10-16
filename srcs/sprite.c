/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:51:46 by isel-jao          #+#    #+#             */
/*   Updated: 2020/10/16 12:34:48 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	swap_sprite(t_sprite *a, t_sprite *b)
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

void	ft_selection_sortt(t_mlx *m, t_sprite *s)
{
	int i;
	int j;
	int index;

	i = -1;
	while (++i < m->s_num)
	{
		index = i;
		j = i;
		while (++j < m->s_num)
			if (s[index].dist < s[j].dist)
				index = j;
		swap_sprite(&s[i], &s[index]);
	}
}

void	ft_sdraw(t_mlx *m, t_sprite s)
{
	int col;
	int index;
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
			index = (h_loc + j) * m->w + w_loc + i;
			if (index > 0 && index < m->w * m->h && s.dist < m->dist[w_loc + i])
				m->img.data[index] = col == NONE ? m->img.data[index] : col;
			j++;
		}
		i++;
	}
}

void	render_sprite(t_mlx *m, t_sprite *s)
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
		ft_sdraw(m, s[i]);
	}
}

void	render_sprites(t_mlx *m)
{
	int i;
	int j;
	int count;

	i = -1;
	count = 0;
	while (++i < m->map.cols)
	{
		j = -1;
		while (m->map.map[i][++j])
		{
			if (m->map.map[i][j] == '2')
			{
				m->spr[count].pos.x = (double)i * 64 + (double)64 / 2.;
				m->spr[count].pos.y = (double)j * 64 + (double)64 / 2.;
				m->spr[count].dist = sqrt(pow(m->spr[count].pos.x - m->p.x, 2) + pow(m->spr[count].pos.y - m->p.y, 2));
				count++;
			}
		}
	}
	ft_selection_sortt(m, m->spr);
	render_sprite(m, m->spr);
}
