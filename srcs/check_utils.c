/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 23:53:20 by isel-jao          #+#    #+#             */
/*   Updated: 2020/10/16 09:25:08 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int ft_check_ext(char const *str, char const *ext)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (strlen(str) < 5)
		return(-1);
	while (str[i])
		i++;
	while (ext[j])
		j++;
	while (j >= 0 && str[i] == ext[j])
	{
		i--;
		j--;
	}
	if (j >= 0)	
		return (-1);
	return (0);
}

int check_rows(t_mlx *m)
{
	int i;
	int j;
	char **s;
	s = m->map.map;

	i = -1;
	while (s[++i])
	{
		j = 0;
		while (s[i][j])
		{
			while (s[i][j] == ' ')
				j++;
			if (s[i][j] && s[i][j] != '1')
				return (-1);
			while (s[i][j] && s[i][j] != ' ')
				j++;
			if (s[i][j - 1] != '1')
				return (-1);
		}
	}
	return (0);
}
int check_cols(t_mlx *m)
{
	int i;
	int j;
	char **s;

	s = m->map.map;
	j = -1;
	while (++j < m->map.rows)
	{
		i = 0;
		while (s[i])
		{
			while (s[i] && (j >= (int)ft_strlen(s[i]) || s[i][j] == ' '))
				i++;
			if (s[i] && s[i][j] != '1')
				return (-1);
			while (s[i] && (j < (int)ft_strlen(s[i]) && s[i][j] != ' '))
				i++;
			if (j < (int)ft_strlen(s[i - 1]) && s[i - 1][j] != '1' && s[i - 1][j] != ' ')
				return (-1);
		}
	}
	return (0);
}
static void get_crmax(t_mlx *m)
{
	int i;

	i = -1;
	while (m->map.map[++i])
	{
		if (m->map.rows < (int)strlen(m->map.map[i]))
			m->map.rows = (int)strlen(m->map.map[i]);
	}
	m->map.cols = i;
}

int ft_check_map(t_mlx *m)
{
	get_crmax(m);
	if (check_cols(m) || check_rows(m))
		return (ft_error(5));
	return (0);
}