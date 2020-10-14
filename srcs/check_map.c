/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:45:53 by isel-jao          #+#    #+#             */
/*   Updated: 2020/10/14 13:43:39 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

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
			while (s[i] && (j >= ft_strlen(s[i]) || s[i][j] == ' '))
				i++;
			if (s[i] && s[i][j] != '1')
				return (-1);
			while (s[i] && (j < ft_strlen(s[i]) && s[i][j] != ' '))
				i++;
			if (j < ft_strlen(s[i - 1]) && s[i - 1][j] != '1' && s[i - 1][j] \
            != ' ')
				return (-1);
		}
	}
	return (0);
}
void get_crmax(t_mlx *m)
{
	int i;
	int j;

	i = -1;
	while (m->map.map[++i])
	{
		if (m->map.rows < strlen(m->map.map[i]))
			m->map.rows = strlen(m->map.map[i]);
	}
	m->map.cols = i;
}

int ft_check_map(t_mlx *m)
{
	get_crmax(m);
	if (check_cols(m) || check_rows(m))
		return (ft_error(6));
	return (0);
}
