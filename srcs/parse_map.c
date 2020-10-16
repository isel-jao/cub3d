/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:33:25 by isel-jao          #+#    #+#             */
/*   Updated: 2020/10/16 11:46:20 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		ft_maplen(char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == '2' ||
			line[i] == 'N' || line[i] == 'S' || line[i] == 'W' ||
			line[i] == 'E' || line[i] == ' ')
			count++;
		else
			return (-1);
		i++;
	}
	return (count);
}

char	*ft_mapline(t_mlx *m, char *s)
{
	char	*col;
	int		j;

	if (!(col = malloc(strlen(s) + 1)))
		return (NULL);
	j = -1;
	while (s[++j] != '\0')
	{
		if (ft_strchr("012NSEW ", s[j]))
			col[j] = s[j];
		else
		{
			ft_printf("wrong cararchter in map %s  \n", s);
			free(col);
			return (NULL);
		}
		if (s[j] == '2')
			m->s_num++;
		if (ft_strchr("NSEW", s[j]))
			if (s[j] == 'N' || s[j] == 'E' || s[j] == 'S' || s[j] == 'W')
				m->p_num++;
	}
	col[j] = '\0';
	return (col);
}

int		parse_map(t_mlx *m, int *i)
{
	int		j;
	char	*tmp;
	int		ret;

	m->map.rows = ft_maplen(m->tab[*i]);
	m->map.map = new_table();
	ret = 0;
	while (!ret && m->tab[*i] && (m->tab[*i][0] == '1' || m->tab[*i][0] == ' '))
	{
		j = 0;
		if (!(tmp = ft_mapline(m, m->tab[*i])))
			ret = 5;
		m->map.map = ft_join_table(m->map.map, tmp);
		free(tmp);
		*i += 1;
		m->map.cols++;
	}
	*i -= 1;
	return (ret);
}
