/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:21:33 by isel-jao          #+#    #+#             */
/*   Updated: 2020/10/16 11:45:22 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int ft_res(t_mlx *m, int i)
{
	char **tab;

	if (m->w != 0 || m->h != 0)
		return (-3);
	tab = ft_split(m->tab[i], ' ');
	if (count_table(tab) != 3)
	{
		free_table(tab);
		return (4);
	}
	m->w = ft_atoi(tab[1]);
	m->h = ft_atoi(tab[2]);
	if (m->w > 2560)
		m->w = 2560;
	if (m->h > 1400)
		m->h = 1400;
	if (m->w <= 0 || m->h <= 0)
		return (3);
	free_table(tab);
	return (0);
}
// int sub_floorceil(t_mlx *m, int i)
// {
	
// }
int ft_floorceil(t_mlx *m, int i)
{
	int r;
	int g;
	int b;
	int j;
	char **tab;

	tab = ft_split(m->tab[i], ' ');
	if (count_table(tab) != 2)
	{
		free_table(tab);
		return (4);
	}
	j = 0;
	r = ft_atoi(tab[1]);
	while (ft_strchr("0123456789", tab[1][j]))
		j++;
	j++;
	g = ft_atoi(&tab[1][j]);
	while (ft_strchr("0123456789", tab[1][j]))
		j++;
	j++;
	b = ft_atoi(&tab[1][j]);
	while (ft_strchr("0123456789", tab[1][j]) && tab[1][j])
		j++;
	if (tab[1][j] != '\0' || r > 255 || g > 255 || b > 255)
	{
		free_table(tab);
		return (6);
	}
	if (tab[0][0] == 'F')
		m->floorcol = r * 256 * 256 + g * 256 + b;
	else if (tab[0][0] == 'C')
		m->cielcol = r * 256 * 256 + g * 256 + b;
	free_table(tab);
	return (0);
}

int ft_texture(t_mlx *m, int i)
{

	char **tab;
	tab = ft_split(m->tab[i], ' ');
	if (count_table(tab) != 2)
	{
		free_table(tab);
		return (4);
	}
	if (!ft_strncmp(m->tab[i], "NO", 2))
		m->path[0] = ft_strdup(tab[1]);
	else if (!ft_strncmp(m->tab[i], "SO", 2))
		m->path[1] = ft_strdup(tab[1]);
	else if (!ft_strncmp(m->tab[i], "EA", 2))
		m->path[2] = ft_strdup(tab[1]);
	else if (!ft_strncmp(m->tab[i], "WE", 2))
		m->path[3] = ft_strdup(tab[1]);
	else if (m->tab[i][0] == 'S' && m->tab[i][1] == ' ')
		m->path[4] = ft_strdup(tab[1]);
	free_table(tab);
	return (0);
}
