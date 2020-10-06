/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:24:03 by isel-jao          #+#    #+#             */
/*   Updated: 2019/11/23 19:07:40 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_reset(void)
{
	g_syntax.flag = 0;
	g_syntax.width = 0;
	g_syntax.point = 0;
	g_syntax.precesion = 0;
	g_syntax.length = 0;
	g_syntax.type = 0;
	g_numf.value = 0;
	g_numf.bs = 0;
	g_numf.as = 0;
	g_numf.zeros = 0;
	free(g_sf.value);
	g_sf.value = NULL;
	g_sf.bs = 0;
	g_sf.as = 0;
	g_sf.zeros = 0;
	g_cf.value = 0;
	g_cf.bs = 0;
	g_cf.as = 0;
	g_cf.zeros = 0;
	g_pf.value = NULL;
	g_pf.bs = 0;
	g_pf.as = 0;
	g_pf.zeros = 0;
}
