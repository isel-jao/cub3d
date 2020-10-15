/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_touls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 23:53:20 by isel-jao          #+#    #+#             */
/*   Updated: 2020/09/18 23:54:49 by isel-jao         ###   ########.fr       */
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