/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 01:49:56 by isel-jao          #+#    #+#             */
/*   Updated: 2020/10/14 11:16:58 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

// int		red_cross(void *mlx)
// {
// 	t_mlx	*b;

// 	b = (t_mx*)mlx;
// 	b->ctx->red_cross = 1;
// 	exit_cube(mlx, 0, "Exit From Red Cross", 0);
// 	return (1);
// }

int loop_hook(t_mlx *m)
{
	return (0);
}

int key_press(int key, t_mlx *m)
{

	static int sp;
	static int r;
	if (!sp)
		sp = 8;
	if (!r)
		r = 16;
	if (key == KEY_E && sp < 32)
		sp++;
	if (key == KEY_Q && sp > 1)
		sp--;
	if (key == KEY_T && r < 16)
		r++;
	if (key == KEY_R && r > 1)
		r--;
	if (key == KEY_W)
		m->p.upmoove = sp;
	if (key == KEY_S)
		m->p.upmoove = -sp;
	if (key == KEY_D)
		m->p.rightmove = sp;
	if (key == KEY_A)
		m->p.rightmove = -sp;
	if (key == KEY_RIGHT)
		m->p.turndir += m->p.rotspeed * r;
	if (key == KEY_LEFT)
		m->p.turndir -= m->p.rotspeed * r;
	if (key == KEY_P)
		g_w ^= 1;
	if (key == KEY_O)
		g_s ^= 1;
	if (key == KEY_I)
		g_m ^= 1;
	update_player(m);
	render(m);
	return (0);
}
int key_release(int key, void *ml)
{
	t_mlx *m;

	m = (t_mlx *)ml;
	if (key == KEY_W)
		m->p.upmoove = 0;
	else if (key == KEY_S)
		m->p.upmoove = 0;
	else if (key == KEY_D)
		m->p.rightmove = 0;
	else if (key == KEY_A)
		m->p.rightmove = 0;
	else if (key == KEY_RIGHT)
		m->p.turndir = 0;
	else if (key == KEY_LEFT)
		m->p.turndir = 0;
	else if (key == 53)
		ft_exit(m);
	else if (key == KEY_C)
		mlx_clear_window(m->mlx, m->win);
	// render(m);
	return (0);
}

void key_handle(t_mlx *m)
{

	// mlx_loop_hook(m->win, &loop_hook, m);
	mlx_hook(m->win, 2, (1L << 0), &key_press, m);
	mlx_hook(m->win, 3, (1L << 1), &key_release, m);
	mlx_loop(m->mlx);
	ft_printf("\n%s %d\n", __FILE__, __LINE__);
}