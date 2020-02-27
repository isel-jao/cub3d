/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:50:56 by isel-jao          #+#    #+#             */
/*   Updated: 2020/02/27 12:16:11 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cube3d.h"


int	init_player(t_mlx *m)
{
	int ret;
	m->p.radus = 10;
	m->p.turndir = 0;
	m->p.upmoove = 0;
	m->p.rightmove = 0;
	m->p.speed = 16.0;
	m->p.rotspeed = 8. * M_PI / 180.;
	m->p.fov	= M_PI / 3.;
		// m->p.fov	= (double)m->w / 1800 * (M_PI / 2.25);
	// printf ("%s   line %d  fov = %f\n", __FILE__, __LINE__, m->p.fov * 180 / M_PI);
	m->p.radus = 12;
	m->p.dir = 9;
	return (0);
}
void    clear(t_mlx *m)
{
	int i = -1;
	while(++i < m->w * m->h)
		m->img.data[i] = 0;
	
}

char		haswall(t_mlx *m, int x, int y)
{
	return (m->map.map[x / 64][y / 64]);
}



void	normlize(double *ang)
{
	if (*ang < 0.0000)
		*ang += (2.0000 * M_PI);
	if (*ang > (2.0000 * M_PI))
		*ang -= (2 * M_PI);
}

static double		v_intesect(t_mlx *m,  t_ray *ray, double *x, double *y, int *fact)
{
	ray->wallside = V;
	*x = floor(*x);
	*y -= sin(ray->ang);
	*fact = ((int)(*y)) % 64;
	return (sqrt(pow(*x - m->p.x, 2) + pow(*y - m->p.y, 2)));
}
static double		h_intesect(t_mlx *m,  t_ray *ray, double *x, double *y, int *fact)
{
	ray->wallside = H;
	*y = floor(*y);
	*x -= cos(ray->ang);
	*fact = ((int)(*x)) % 64;
	return (sqrt(pow(*x - m->p.x, 2) + pow(*y - m->p.y, 2)));
}
double		wallcast(t_mlx *m, t_ray *ray,  int *fact)
{
	double new_x;
	double new_y;
	new_x = m->p.x;
	new_y = m->p.y;
	while (haswall(m, new_x, new_y) != '1')
	{
		new_x += cos(ray->ang);
		new_y += sin(ray->ang);
	}
    if (haswall(m, new_x , new_y - sin(ray->ang)) == '1')
        return (v_intesect(m, ray, &new_x, &new_y, fact));
    else if (haswall(m, new_x - cos(ray->ang), new_y) == '1')
		return (h_intesect(m, ray, &new_x, &new_y, fact));
	*fact = 0;
	new_x = floor(new_x);
	new_y = floor(new_y);
	return (sqrt(pow(new_x - m->p.x, 2) + pow(new_y -m->p.y, 2)) );
}

