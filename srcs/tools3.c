/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:50:56 by isel-jao          #+#    #+#             */
/*   Updated: 2020/10/14 13:08:59 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static int in_map(t_mlx *m, double x, double y)
{
	if (x < 0 || y < 0 || x > 64 * m->map.cols - 64 || \
	y > 64 * m->map.rows - 64 || !m->map.map[(int)(x / 64)][(int)(y / 64)] || \
	m->map.map[(int)(x / 64)][(int)(y / 64)] == ' ')
		return (0);
	return (1);
}

char haswall(t_mlx *m, double x, double y)
{
	if (in_map(m, x, y) && m->map.map[(int)x / 64] && \
	 m->map.map[(int)x / 64][(int)y / 64] != '1' && m->map.map[(int)x / 64][(int)y / 64])
		return (m->map.map[(int)x / 64][(int)y / 64]);
	return ('1');
}

void normlize(double *ang)
{
	if (*ang < 0.0000)
		*ang += (2.0000 * M_PI);
	if (*ang > (2.0000 * M_PI))
		*ang -= (2 * M_PI);
}
