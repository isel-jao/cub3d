/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:25:31 by isel-jao          #+#    #+#             */
/*   Updated: 2019/11/29 18:50:02 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int		ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

void	ft_convflag(va_list pa)
{
	if (g_syntax.type == 'd' || g_syntax.type == 'i')
		ft_intconv(pa);
	if (g_syntax.type == 's')
		ft_sconv(pa);
	if (g_syntax.type == 'x' || g_syntax.type == 'X')
		ft_xconv(pa);
	if (g_syntax.type == 'u')
		ft_uconv(pa);
	if (g_syntax.type == 'p')
		ft_pconv(pa);
	else
		ft_cconv(pa);
}
