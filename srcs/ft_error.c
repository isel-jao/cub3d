/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 23:11:23 by isel-jao          #+#    #+#             */
/*   Updated: 2020/10/15 11:32:10 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int ft_error(int err)
{
	if (err == 0)
	return (0);
	if (err == 1)
		ft_printf("wrong map format.\n");
	else if (err == 2)
		ft_printf("wrong second argument.\n");
	else if (err == 3)
		ft_printf("incorrect resoltution.\n");
	else if (err == 4)
		ft_printf("to much/few arguments.\n");
	else if (err == 5)
		ft_printf("mem allocaion error.\n");
	else if (err == 6)
		ft_printf("map not closed.\n");
	else if (err == 7)
		ft_printf("wrong character.\n");
	return (-1);
}