/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:20:54 by isel-jao          #+#    #+#             */
/*   Updated: 2020/10/15 11:21:23 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

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