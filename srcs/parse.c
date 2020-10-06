/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:41:36 by isel-jao          #+#    #+#             */
/*   Updated: 2020/09/19 18:13:23 by isel-jao         ###   ########.fr       */
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


int ft_check(t_mlx *m)
{
	int ret;
	ret = 0;
	ret = ft_check_map(m);
	if (!ret)
		ret = ft_player(m);
	if (!ret)
		ret = load_textures(m);
	return (ret);
}

int parse(t_mlx *m, char *cub)
{
	char ret;
	int i = 0;
	if (file_to_tab(&m->tab, cub) == -1)
		return (ft_error(1));
	ret = 0;
	while (m->tab[i] && !ret)
	{
		if (m->tab[i][0] == 'R' && m->tab[i][1] == ' ')
			ret = ft_res(m, i);
		else if (!ft_strncmp(m->tab[i], "NO ", 3) || !ft_strncmp(m->tab[i], "SO ", 3) ||
				 !ft_strncmp(m->tab[i], "WE ", 3) || !ft_strncmp(m->tab[i], "EA ", 3) ||
				 (m->tab[i][0] == 'S' && m->tab[i][1] == ' '))
			ret = ft_texture(m, i);
		else if ((m->tab[i][0] == 'F' && m->tab[i][1] == ' ') ||
				 (m->tab[i][0] == 'C' && m->tab[i][1] == ' '))
			ret = ft_floorceil(m, i);
		else if (m->tab[i][0] == '1' || m->tab[i][0] == ' ')
			ret = parse_map(m, &i);
		else if (m->tab[i] && m->tab[i][0] != 0)
			ret = -1;
		i++;
	}
	if (ret)
		ft_printf("error line %d\t", i);
	return (ft_error(ret));
}