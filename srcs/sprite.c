/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:51:46 by isel-jao          #+#    #+#             */
/*   Updated: 2020/02/27 13:21:40 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cube3d.h"

void	normlize2(double *ang)
{
	if (*ang < - M_PI)
		*ang += (2.0000 * M_PI);
	if (*ang > M_PI)
		*ang -= (2 * M_PI);
}

void		swap_sprite(t_sprite *a, t_sprite *b)
{
	// t_sprite *tmp;
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

void		sort_sprite(t_mlx *m, t_sprite *s)
{
	int i = 1;
	int j;
	while (i < m->s_num)
	{
		j = i;
		while (j > 0)
		{
			if (s[j - 1].dist < s[j].dist)
				swap_sprite(&s[j], &s[j - 1]);
			j--;
		}
		i++;
	}
}

void	swap(int *a, int *b)
{
	int tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

unsigned int	ft_spixel(t_mlx *m,int index, unsigned int col)
{
	int	t;
	int	r;
	int	g;
	int	b;

	if (col >= NONE)
		return (m->img.data[index]);
	return (col);
}

void			ft_sdraw(t_mlx *m, t_sprite s)
{
	unsigned int	col;
	double			size;
	int				index;
	int				i;
	int				j;
	int loc;
	i = 0;
	size = m->h * 64. / s.dist ;
	loc = (int)(m->w *( 0.5 + s.ang / 1.0471975512) - size / 2.);
	while (i < size )
	{
		j = 0;
			while ((loc + i >= 0 && loc + i < m->w) && j < size )
			{
				col = 64 * floor(64 * (double)j / size) + (double)i / size * 64;
				// if (col < 64 * 64)
					col = m->textures[4].data[col];
				index =  (m->h / 2  + j) * m->w + loc + i;
				if (index < m->w * m->h && s.dist < m->dist[ loc + i])
					m->img.data[index] = ft_spixel(m, index, col);
				j++;
			}
		i++;
	}
}

void			ft_slocate(t_mlx *m, t_sprite *s)
{
	int i = -1;
	while (++i < m->s_num)
	{
		s[i].dir.x = (s[i].pos.x - m->p.x) / s[i].dist;
		s[i].dir.y = (s[i].pos.y - m->p.y) / s[i].dist;
		if (s[i].dir.y >= 0)
			s[i].ang = acos(s[i].dir.x);
		else
			s[i].ang = -acos(s[i].dir.x);
		s[i].ang = m->p.rotang - s[i].ang;
		normlize2(&s[i].ang);
		ft_sdraw(m, s[i]);
	}
	
}

void	render_sprite(t_mlx *m)
{
	t_sprite *s;
	t_ray ray;
	double cast;
	double d;
	int i = -1;
	int j;
	
	s = malloc(sizeof(t_sprite) * (m->s_num + 1));
	int count = 0;
	while (++i < m->map.cols)
	{
		j = -1;
		while (++j < m->map.rows)
		{
			if (m->map.map[i][j] == '2')
			{
				s[count].pos.x = (double)i * 64  + (double)64 / 2.;
				s[count].pos.y = (double)j * 64  + (double)64 / 2.;
				s[count].dist = sqrt(pow(s[count].pos.x - m->p.x, 2) + pow(s[count].pos.y -m->p.y, 2));
				count++;
			}
		}
	}
	sort_sprite(m, s);
	ft_slocate(m, s);
}

                // printf("\nnow problem file %s  line %d\n\n",__FILE__,  __LINE__); 