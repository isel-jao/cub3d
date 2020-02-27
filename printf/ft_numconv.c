/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numconv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 00:03:41 by isel-jao          #+#    #+#             */
/*   Updated: 2019/11/28 04:49:46 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_pconv(va_list pa)
{
	int				len;
	unsigned long	c;

	g_pf.value = va_arg(pa, void *);
	c = (long unsigned int)g_pf.value;
	len = numlenp(c) + 2;
	if ((g_syntax.flag == '0' && g_syntax.point) || g_syntax.point)
	{
		g_pf.zeros = g_syntax.precesion + 2 - len;
		g_pf.bs = g_syntax.width - ft_max(g_syntax.precesion + 2, len);
	}
	if (g_syntax.flag == '-')
	{
		g_pf.as = g_syntax.width - ft_max(g_syntax.precesion + 2, len);
		g_pf.bs = 0;
	}
	if (g_syntax.flag == '0' && !g_syntax.point)
		g_pf.zeros = g_syntax.width - len;
	if (!g_syntax.flag)
		g_pf.bs = g_syntax.width - ft_max(g_syntax.precesion + 2, len);
}

void	ft_xconv(va_list pa)
{
	int len;

	g_numf.value = va_arg(pa, unsigned int);
	len = ft_numlenx(g_numf.value);
	if ((g_syntax.flag == '0' && g_syntax.point) || g_syntax.point)
	{
		g_numf.zeros = g_syntax.precesion - len;
		g_numf.bs = g_syntax.width - ft_max(g_syntax.precesion, len);
	}
	if (g_syntax.flag == '-')
	{
		g_numf.as = g_syntax.width - ft_max(g_syntax.precesion, len);
		g_numf.bs = 0;
	}
	if (g_syntax.flag == '0' && !g_syntax.point)
		g_numf.zeros = g_syntax.width - len;
	if (!g_syntax.flag)
		g_numf.bs = g_syntax.width - ft_max(g_syntax.precesion, len);
}

void	ft_uconv(va_list pa)
{
	int len;

	g_numf.value = va_arg(pa, unsigned int);
	len = ft_numlenu(g_numf.value);
	if ((g_syntax.flag == '0' && g_syntax.point) || g_syntax.point)
	{
		g_numf.zeros = g_syntax.precesion - len;
		g_numf.bs = g_syntax.width - ft_max(g_syntax.precesion, len);
	}
	if (g_syntax.flag == '-')
	{
		g_numf.as = g_syntax.width - ft_max(g_syntax.precesion, len);
		g_numf.bs = 0;
	}
	if (g_syntax.flag == '0' && !g_syntax.point)
		g_numf.zeros = g_syntax.width - len;
	if (!g_syntax.flag)
		g_numf.bs = g_syntax.width - ft_max(g_syntax.precesion, len);
}

void	ft_intconv(va_list pa)
{
	int len;

	g_numf.value = (int)va_arg(pa, int);
	len = ft_numlen(g_numf.value);
	if ((g_syntax.flag == '0' && g_syntax.point) || g_syntax.point)
	{
		g_numf.zeros = g_syntax.precesion - len;
		g_numf.bs = g_syntax.width - ft_max(g_syntax.precesion, len);
	}
	if (g_syntax.flag == '-')
	{
		g_numf.as = g_syntax.width - ft_max(g_syntax.precesion, len);
		g_numf.bs = 0;
	}
	if (g_syntax.flag == '0' && !g_syntax.point)
		g_numf.zeros = g_syntax.width - len;
	if (!g_syntax.flag)
		g_numf.bs = g_syntax.width - ft_max(g_syntax.precesion, len);
	if (g_numf.value < 0)
	{
		g_syntax.point ? g_numf.zeros : g_numf.zeros--;
		g_numf.bs--;
		g_numf.as--;
	}
}
