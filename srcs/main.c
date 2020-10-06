/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:24:58 by isel-jao          #+#    #+#             */
/*   Updated: 2020/09/19 03:40:19 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"



void render(t_mlx *m)
{
	mlx_clear_window(m->mlx, m->win);
	randerfloorceil(m);
	render_walls(m);
	render_sprites(m);
	render_mini_map(m);
	mlx_put_image_to_window(m->mlx, m->win, m->img.img, 0, 0);
}

int main(int ac, char **av)
{
	t_mlx m;

	if (ft_check_ext(av[1], ".cub"))
		return (ft_error(1));
	if (ac > 2 && ft_strcmp(av[2], "--save"))
		return (ft_error(2));
	unit_mlx(&m);
	m.mlx = mlx_init();
	if (parse(&m, av[1]))
		ft_exit(&m);
	if (ft_check(&m))
		ft_exit(&m);
	init_env(&m);
	init_image(&m, ac, av);
	render(&m);
	key_handle(&m);
	return (0);
}
