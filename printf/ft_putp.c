/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:56:47 by isel-jao          #+#    #+#             */
/*   Updated: 2019/11/28 05:21:29 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			numlenp(long unsigned nb)
{
	int i;

	if (g_pf.value == NULL && g_syntax.point && !g_syntax.precesion)
		return (0);
	if (g_pf.value == NULL)
		return (1);
	i = 0;
	while (nb)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

static void	putlowx(long unsigned nb)
{
	int				len;
	int				i;
	long unsigned	a;
	long unsigned	x;

	if (!g_pf.value && g_syntax.point && !g_syntax.precesion)
		return ;
	i = 0;
	a = 1;
	len = numlenp(nb);
	while (++i < len)
		a *= 16;
	while (a)
	{
		x = nb / a;
		if (x < 10)
			ft_putchar((nb / a) + '0');
		else
			ft_putchar((nb / a) + 87);
		nb %= a;
		a /= 16;
	}
}

void		ft_putp(void)
{
	int				i;
	long unsigned	c;

	i = 0;
	c = (long unsigned int)g_pf.value;
	while (i++ < g_pf.bs)
		ft_putchar(' ');
	i = 0;
	ft_putstr("0x");
	while (i++ < g_pf.zeros)
		ft_putchar('0');
	putlowx(c);
	i = 0;
	while (i++ < g_pf.as)
		ft_putchar(' ');
}
