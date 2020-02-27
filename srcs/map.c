/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:33:25 by isel-jao          #+#    #+#             */
/*   Updated: 2020/02/26 14:02:23 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"



int		ft_maplen(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == '2' || \
		line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || \
		line[i] == 'E')
			count++;
		else if (line[i] != ' ')
			return (-1);
		i++;
	}
	return (count);
}

char	*ft_mapline(t_mlx *m, char *s, int *i)
{
	char	*col;
	int		j;

	if (ft_maplen(s) != m->map.rows || !(col = malloc(m->map.rows + 1)))
		return (NULL);
	j = 0;
	while (s[*i] != '\0')
	{
		if (s[*i] == '0' || s[*i] == '1' || s[*i] == 'N' || s[*i] == 'E' \
		|| s[*i] == 'S' || s[*i] == 'W' || s[*i] == '2')
			col[j++] = s[*i];
		else if (s[*i] != ' ')
		{
			free(col);
			return (NULL);
		}
		if (s[*i] == '2')
			m->s_num++;
		if (s[*i] == 'N' || s[*i] == 'E' || s[*i] == 'S' || s[*i] == 'W')
			m->p_num++;
		(*i)++;
	}
	col[j] = '\0';
	return (col);
}

int		ft_map(t_mlx *m, int *i)
{
	int		j;
	char	*tmp;
	int		ret;

	m->map.rows = ft_maplen(m->tab[*i]);
	m->map.map = new_table();
	ret = 0;
	while (!ret && m->tab[*i] && (m->tab[*i][0] == '1' || m->tab[*i][0] == '0'))
	{
		j = 0;
		if (!(tmp = ft_mapline(m, m->tab[*i], &j)))
			ret = 2;
		m->map.map = ft_join_table(m->map.map, tmp);
		free(tmp);
		*i += 1;
		m->map.cols++;
	}
	*i -= 1;
	return (ret);
}
