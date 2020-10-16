/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:52:07 by isel-jao          #+#    #+#             */
/*   Updated: 2020/10/16 11:20:49 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cube3d.h"

void	sqr(t_mlx *m, int x, int y, int h, int color)
{
	int i;
	int j;

	i = -1;
	while (++i < h)
	{
		j = -1;
		while (++j < h)
            m->img.data[(x + i) * m->w + y + j] = color;
	}
}
void	circle(t_mlx *m,int x0, int y0, int radus, int color)
{
	int x;
	int y;


	x = x0 - radus - 1;
	while (++x < x0 + radus)
	{
		y = y0 - radus - 1;
		while (++y < y0 + radus)
		{
			if (pow(x - x0, 2) + pow(y - y0, 2) < pow(radus, 2))
                m->img.data[x * m->w + y ] = color;
		}
	}
}
static void line1(t_mlx *m,int x, int y, int dx, int dy, int incx, int incy, int color)
{
	int e;
	int i;


	m->img.data[x * m->w + y ] = color;
	e = 2 * dy-dx;
	i = -1;
	while(++i < dx)
	{
		if (e >= 0) {
			y += incy;
			e += 2 * (dy-dx);
		}
		else
			e += 2*dy;
		x += incx;
		m->img.data[x * m->w + y ] = color;
	}
}

static void line2(t_mlx *m,int x, int y, int dx, int dy, int incx, int incy, int color)
{
	int e;
	int i;


	m->img.data[x * m->w + y ] = color;
	e = 2*dx-dy;
	i = -1;
	while (++i < dy)
	{
		if (e >= 0)
		{
			x += incx;
			e += 2*(dx-dy);
		}
		else
			e += 2*dx;
		y += incy;
		m->img.data[x * m->w + y ] = color;
	}
}

void	line(t_mlx *m,int x0, int y0, int x1, int y1, int color)
{
	int dx;
	int dy;
	int incx;
	int incy;
	// t_line line;
	

	dx = abs(x1-x0);
	// line.dx = abs(x1-x0);
	dy = abs(y1-y0);
	// line.dy = abs(y1-y0);
	incx = 1;
	// line.incx = 1;
	if (x1 < x0) incx = -1;
	incy = 1;
	if (y1 < y0) incy = -1;
	if (dx > dy) 
		line1(m,x0, y0, dx, dy, incx, incy, color);
	else 
		line2(m,x0, y0, dx, dy, incx, incy, color);
}
