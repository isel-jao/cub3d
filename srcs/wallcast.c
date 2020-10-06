/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallcast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 02:00:44 by isel-jao          #+#    #+#             */
/*   Updated: 2020/09/19 02:01:04 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static double H_intesect(t_mlx *m, t_ray *ray, int *fact)
{
	double dx;
	double dy;
	double new_x;
	double new_y;
	double deltax;
	double deltay;

	deltax = !is_up(ray->ang) ? 64 : -64;
	deltay = deltax * tan(ray->ang);

	dx = ((int)m->p.x / 64) * 64. - m->p.x;
	dx = !is_up(ray->ang) ? 64. + dx : dx;
	dy = dx * tan(ray->ang);

	new_x = m->p.x + dx;
	new_y = m->p.y + dy;
	double e = (int)deltax / 64;
	while (haswall(m, new_x + e, new_y) != '1')
	{
		new_x += deltax;
		new_y += deltay;
	}
	*fact = ((int)(new_y)) % 64;
	return (sqrt(pow(new_x - m->p.x, 2) + pow(new_y - m->p.y, 2)));
}
static double V_intesect(t_mlx *m, t_ray *ray, int *fact)
{
	double deltax;
	double deltay;
	double dx;
	double dy;
	double new_x;
	double new_y;

	deltay = is_right(ray->ang) ? 64 : -64;
	deltax = deltay / tan(ray->ang);

	dy = ((int)m->p.y / 64) * 64. - m->p.y;
	dy = is_right(ray->ang) ? 64. + dy : dy;
	dx = dy / tan(ray->ang);
	new_y = m->p.y + dy;
	new_x = m->p.x + dx;
	double e = (int)deltay / 64;
	while (haswall(m, new_x, new_y + e) != '1')
	{
		new_x += deltax;
		new_y += deltay;
	}
	*fact = ((int)(new_x)) % 64;
	return (sqrt(pow(new_x - m->p.x, 2) + pow(new_y - m->p.y, 2)));
}
double Wallcast(t_mlx *m, t_ray *ray, int *fact)
{
	int hfact;
	int vfact;
	double vd;
	double hd;

	g_i++;
	vd = V_intesect(m, ray, &vfact);
	hd = H_intesect(m, ray, &hfact);
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