/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 19:55:35 by isel-jao          #+#    #+#             */
/*   Updated: 2020/02/14 02:30:29 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	get_value(int *index, char *s, va_list pa)
{
	int i;
	int	nb;

	i = *index;
	nb = 0;
	if (s[i] == '*')
		nb = va_arg(pa, int);
	else
		nb = ftatoi(&s[i]);
	if (s[i] == '*')
		i++;
	else
	{
		while (is_set(s[i], "0123456789"))
			i++;
	}
	*index = i;
	return (nb);
}

static void	get_wpp(char *s, va_list pa)
{
	int i;
	int nb;

	i = 0;
	while (s[i] != g_syntax.type)
	{
		if (s[i] != '.' && s[i] != '-' && s[i] != '0')
			g_syntax.width = get_value(&i, s, pa);
		if (g_syntax.width < 0)
			g_syntax.flag = '-';
		if (s[i] == '.')
		{
			g_syntax.point = 1;
			while (s[i] == '.')
				i++;
			nb = get_value(&i, s, pa);
			if (nb >= 0)
				g_syntax.precesion = nb;
			else
				g_syntax.precesion = 0;
			nb < 0 ? g_syntax.point-- : g_syntax.point;
		}
		while (s[i] == '-' || s[i] == '0')
			i++;
	}
}

void		ft_getflag(char *s, va_list pa)
{
	int	i;

	i = 0;
	while (is_set(s[i], "0123456789.*-"))
		i++;
	g_syntax.type = s[i];
	g_a = i + 2;
	if (s[0] == '0')
		g_syntax.flag = '0';
	while (i >= 0 && s[i] != '-')
		i--;
	if (s[i] == '-')
		g_syntax.flag = '-';
	get_wpp(s, pa);
	if (g_syntax.width < 0)
	{
		g_syntax.width *= -1;
		g_syntax.flag = '-';
	}
}
