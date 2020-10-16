/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:41:36 by isel-jao          #+#    #+#             */
/*   Updated: 2020/10/16 11:38:51 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static	int	parse_return(int ret, int i)
{
	if (ret)
		ft_printf("error line %d\t", i);
	return (ft_error(ret));
}

int			parse(t_mlx *m, char *cub)
{
	int	ret;
	int	i;

	i = -1;
	if (file_to_tab(&m->tab, cub) == -1)
		return (ft_error(1));
	ret = 0;
	while (m->tab[++i] && !ret)
	{
		if (m->tab[i][0] == 'R' && m->tab[i][1] == ' ')
			ret = ft_res(m, i);
		else if (!ft_strncmp(m->tab[i], "NO ", 3) || !ft_strncmp(m->tab[i], \
		"SO ", 3) || !ft_strncmp(m->tab[i], "WE ", 3) || \
		!ft_strncmp(m->tab[i], "EA ", 3) || (m->tab[i][0] == 'S' && \
		m->tab[i][1] == ' '))
			ret = ft_texture(m, i);
		else if ((m->tab[i][0] == 'F' && m->tab[i][1] == ' ') ||\
		(m->tab[i][0] == 'C' && m->tab[i][1] == ' '))
			ret = ft_floorceil(m, i);
		else if (m->tab[i][0] == '1' || m->tab[i][0] == ' ')
			ret = parse_map(m, &i);
		else if (m->tab[i] && m->tab[i][0] != 0)
			ret = -1;
	}
	return (parse_return(ret, i));
}
