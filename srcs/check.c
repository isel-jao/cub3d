/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 13:28:24 by isel-jao          #+#    #+#             */
/*   Updated: 2020/10/14 13:30:47 by isel-jao         ###   ########.fr       */
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