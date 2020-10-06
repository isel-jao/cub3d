/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:54:34 by isel-jao          #+#    #+#             */
/*   Updated: 2019/11/26 17:28:38 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		ft_putchar(str[i]);
}

void	ft_puts(void)
{
	int i;

	i = 0;
	while (i++ < g_sf.bs)
		ft_putchar(' ');
	while (i++ <= g_sf.zeros)
		ft_putchar('0');
	i = 0;
	if (!g_syntax.point)
	{
		ft_putstr(g_sf.value);
		while (i++ < g_sf.as)
			ft_putchar(' ');
	}
	else
	{
		while (i < g_syntax.precesion && g_sf.value[i])
			ft_putchar(g_sf.value[i++]);
		i = 0;
		while (i++ < g_sf.as)
			ft_putchar(' ');
	}
}
