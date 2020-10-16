/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:50:56 by isel-jao          #+#    #+#             */
/*   Updated: 2020/10/16 11:57:44 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"



static int in_map(t_mlx *m, double x, double y)
{
	if (x < 0 || y < 0 || x > 64 * m->map.cols - 64 || y > 64 * m->map.rows - 64 ||
		!m->map.map[(int)(x / 64)][(int)(y / 64)] || m->map.map[(int)(x / 64)][(int)(y / 64)] == ' ')
		return (0);
	return (1);
}

char haswall(t_mlx *m, double x, double y)
{
	if (in_map(m, x, y) && m->map.map[(int)x / 64] && m->map.map[(int)x / 64][(int)y / 64] != '1' )
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

void normlize2(double *ang)
{
	if (*ang < -M_PI)
		*ang += (2.0000 * M_PI);
	if (*ang > M_PI)
		*ang -= (2 * M_PI);
}

int is_up(double ang)
{
	if (ang > 1.57079632679 && ang < 4.71238898038)
		return (1);
	return (0);
}

int is_right(double ang)
{
	if (ang >= 0 && ang < 3.14159265359)
		return (1);
	return (0);
}