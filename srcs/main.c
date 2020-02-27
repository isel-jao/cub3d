/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:24:58 by isel-jao          #+#    #+#             */
/*   Updated: 2020/02/26 20:43:19 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cube3d.h"


int		ft_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}


int     key_press(int key, void *ml)
{

    t_mlx *m;
    m = (t_mlx *)ml;
	m->p.upmoove = 0;
	m->p.rightmove= 0;
	// m->p.rotang = 0;
	m->p.turndir = 0;
    if (key == 53)
        exit(0);
    if (key == 13)
        m->p.upmoove++;
    if (key == 1)
        m->p.upmoove--;
    if (key == 2)
        m->p.turndir += m->p.rotspeed;
    else if (key == 0)
        m->p.turndir -= m->p.rotspeed;
    clear(m);
    update_player(m);
    ray_render(m);
	render_sprite(m);
	 put_mini_map(m);
	mlx_put_image_to_window(m->mlx, m->win, m->img.img, 0, 0);
    return (0);
}


void	key_handle(t_mlx *m)
{
	mlx_hook(m->win, 17, 0, ft_close, (void *)0);
    mlx_hook(m->win, 2, 0, key_press, (void *)m);
}


void    init_image(t_mlx *m)
{
	m->win = mlx_new_window(m->mlx, m->w, m->h, "cube3D");
	m->img.img = mlx_new_image(m->mlx, m->w, m->h);
	m->img.data = (int *)mlx_get_data_addr(m->img.img, \
    &(m->img.bpp), &(m->img.sizeline), &(m->img.endian));
}

int main(int ac, char **av)
{
	t_mlx m;

	unit_mlx(&m);
	m.mlx = mlx_init();
	if (parse(&m, av[1]))
		ft_exit(&m);
	if (ft_check(&m))
		ft_exit(&m);
	init_image(&m);
	init_player(&m);
	update_player(&m);
    ray_render(&m);
	// printf ("%s   line %d\n", __FILE__, __LINE__);
	render_sprite(&m);
    put_mini_map(&m);
	mlx_put_image_to_window(m.mlx, m.win, m.img.img, 0, 0);
	key_handle(&m);
	mlx_loop(m.mlx);
	return(0);
}
