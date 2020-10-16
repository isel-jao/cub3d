/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallcast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 02:00:44 by isel-jao          #+#    #+#             */
/*   Updated: 2020/10/16 13:40:56 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static	double	h_intesect(t_mlx *m, t_ray *ray, int *fact)
{
	t_intersect i;

	i.deltax = !is_up(ray->ang) ? 64 : -64;
	i.deltay = i.deltax * tan(ray->ang);
	i.dx = ((int)m->p.x / 64) * 64. - m->p.x;
	i.dx = !is_up(ray->ang) ? 64. + i.dx : i.dx;
	i.dy = i.dx * tan(ray->ang);
	i.new_x = m->p.x + i.dx;
	i.new_y = m->p.y + i.dy;
	i.e = (int)i.deltax / 64;
	while (haswall(m, i.new_x + i.e, i.new_y) != '1')
	{
		i.new_x += i.deltax;
		i.new_y += i.deltay;
	}
	*fact = ((int)(i.new_y)) % 64;
	return (sqrt(pow(i.new_x - m->p.x, 2) + pow(i.new_y - m->p.y, 2)));
}

static	double	v_intesect(t_mlx *m, t_ray *ray, int *fact)
{
	t_intersect i;

	i.deltay = is_right(ray->ang) ? 64 : -64;
	i.deltax = i.deltay / tan(ray->ang);
	i.dy = ((int)m->p.y / 64) * 64. - m->p.y;
	i.dy = is_right(ray->ang) ? 64. + i.dy : i.dy;
	i.dx = i.dy / tan(ray->ang);
	i.new_y = m->p.y + i.dy;
	i.new_x = m->p.x + i.dx;
	i.e = (int)i.deltay / 64;
	while (haswall(m, i.new_x, i.new_y + i.e) != '1')
	{
		i.new_x += i.deltax;
		i.new_y += i.deltay;
	}
	*fact = ((int)(i.new_x)) % 64;
	return (sqrt(pow(i.new_x - m->p.x, 2) + pow(i.new_y - m->p.y, 2)));
}

double			wallcast(t_mlx *m, t_ray *ray, int *fact)
{
	int		hfact;
	int		vfact;
	double	vd;
	double	hd;

	g_i++;
	vd = v_intesect(m, ray, &vfact);
	hd = h_intesect(m, ray, &hfact);
	if (vd <= hd)
	{
		ray->wallside = H;
		*fact = vfact;
		return (vd);
	}
	ray->wallside = V;
	*fact = hfact;
	return (hd);
}
