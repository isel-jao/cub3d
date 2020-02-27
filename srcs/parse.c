/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:41:36 by isel-jao          #+#    #+#             */
/*   Updated: 2020/02/26 19:36:34 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	unit_mlx(t_mlx *m)
{
	int i;

	m->w = 0;
	m->h = 0;
	m->p_num = 0;
	m->s_num = 0;
	m->tab = NULL;
	m->tab = NULL;
	m->mlx = NULL;
	m->win = NULL;
	m->spr = NULL;
	m->map.map = NULL;
	i = -1;
	while (++i < 7)
	{
		m->path[i] = NULL;
		m->textures[i].img = NULL;
		m->textures[i].data = NULL;
		m->path[i] = NULL;
	}
}

int	ft_strerror(int ret, int i)
{
	if (!ret)
		return (0);
	if (ret == 1)
		ft_printf ("to much arguments line %d\n", i);
	else if (ret == 3)
		ft_printf("player position not set or more than one is set!%d\n", i);
	else if (ret == 2)
		ft_printf("map error line %d\n", i);
	else 
		ft_printf("error line %d\n", i);
	return (ret);
}

void	ft_exit(t_mlx *m)
{
	int i;

	if (m->tab)
		free_table(m->tab);
	if (m->map.map)
		free_table(m->map.map);
	i = -1;
	while (++i < 7)
	{
		if (m->path[i])
			free(m->path[i]);
	}
	exit(0);
}

int		ft_check(t_mlx *m)
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

int	parse(t_mlx *m, char *cub)
{
	char ret;
	int i = 0;

	if(file_to_tab(&m->tab, cub) == -1)
	{
		ft_printf("faild to open %s\n", cub);
		return (-1);
	}
	ret = 0;
	while(m->tab[i] && !ret)
	{
		if (m->tab[i][0] == 'R' && m->tab[i][1] == ' ')
			ret = ft_res(m, i);
		else if (!ft_strncmp(m->tab[i], "NO ", 3) || !ft_strncmp(m->tab[i], "SO ", 3) || \
		!ft_strncmp(m->tab[i], "WE ", 3) || !ft_strncmp(m->tab[i], "EA ", 3) || \
		(m->tab[i][0] == 'S' && m->tab[i][1] == ' '))
			ret = ft_texture(m, i);
		else if ((m->tab[i][0] == 'F' && m->tab[i][1] == ' ' ) || \
		(m->tab[i][0] == 'C' && m->tab[i][1] == ' ' ))
			ret = ft_floorceil(m, i);
		else if (m->tab[i][0] == '1' || m->tab[i][0] == '0')
			ret = ft_map(m, &i);
		else if (m->tab[i] && m->tab[i][0] != 0)
			ret = -1;
		i++;
	}
	return(ft_strerror(ret, i));
}