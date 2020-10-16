/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:24:58 by isel-jao          #+#    #+#             */
/*   Updated: 2020/10/16 08:22:13 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

void ft_exit(t_mlx *m)
{
	int i;

	if (m->tab)
		free_table(m->tab);
	if (m->map.map)
		free_table(m->map.map);
	i = -1;
	while (++i < 7)
		ft_free(m->path[i]);
	ft_free(m->dist);
	ft_free(m->spr);
	if (m)
		exit(0);
}

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
// ft_printf("\n%s   %s  %d\n", __FILE__, __FUNCTION__, __LINE__);
