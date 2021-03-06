/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 01:49:56 by isel-jao          #+#    #+#             */
/*   Updated: 2020/10/16 10:55:03 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static void	sub_key_press(int key, t_mlx *m, int sp, int r)
{
	if (key == K_W)
		m->p.upmoove = sp;
	if (key == K_S)
		m->p.upmoove = -sp;
	if (key == K_D)
		m->p.rightmove = sp;
	if (key == K_A)
		m->p.rightmove = -sp;
	if (key == K_AR_R)
		m->p.turndir += m->p.rotspeed * r;
	if (key == K_AR_L)
		m->p.turndir -= m->p.rotspeed * r;
	if (key == K_I)
		g_m ^= 1;
}

static int	key_press(int key, t_mlx *m)
{
	static int sp;
	static int r;

	m->p.turndir = 0;
	if (!sp)
		sp = 8;
	if (!r)
		r = 16;
	if (key == K_E && sp < 32)
		sp++;
	if (key == K_Q && sp > 1)
		sp--;
	if (key == K_T && r < 16)
		r++;
	if (key == K_R && r > 1)
		r--;
	sub_key_press(key, m, sp, r);
	update_player(m);
	render(m);
	return (0);
}

static int	key_release(int key, void *ml)
{
	t_mlx *m;

	m = (t_mlx *)ml;
	if (key == K_W)
		m->p.upmoove = 0;
	if (key == K_S)
		m->p.upmoove = 0;
	if (key == K_D)
		m->p.rightmove = 0;
	if (key == K_A)
		m->p.rightmove = 0;
	if (key == K_ESC)
		ft_exit(m);
	return (0);
}

void		key_handle(t_mlx *m)
{
	mlx_hook(m->win, 2, (1L << 0), &key_press, m);
	mlx_hook(m->win, 3, (1L << 1), &key_release, m);
	mlx_loop(m->mlx);
}
