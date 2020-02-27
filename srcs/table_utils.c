/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 09:57:08 by ylazrek           #+#    #+#             */
/*   Updated: 2020/02/26 19:37:56 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cube3d.h"

int		count_table(char **tab)
{
	int i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

void	free_table(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**new_table(void)
{
	char	**tab;

	tab = (char**)malloc(sizeof(char*) * 1);
	tab[0] = NULL;
	return (tab);
}

char	**ft_join_table(char **tab, char *str)
{
	int		len;
	char	**new_t;
	int		i;
	int		j;

	i = 0;
	len = count_table(tab);
	new_t = (char**)malloc(sizeof(char*) * (len + 2));
	while (tab[i] != NULL)
	{
		new_t[i] = ft_strdup(tab[i]);
		i++;
	}
	new_t[i] = ft_strdup(str);
	new_t[++i] = NULL;
	free_table(tab);
	return (new_t);
}

int file_to_tab(char ***tab, char *cub)
{
	char	*line;
	int		fd;
	int		ret;

	ret = 1;
	fd = open(cub, O_RDONLY);
	if (fd == -1)
		return (-1);
	*tab = new_table();
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		*tab = ft_join_table(*tab, line);
		free(line);
	}
	close(fd);
	if (ret == -1)
		return (-1);
	return (0);
}
void	print_table(char **tab)
{
	int i = 0;
	if (!tab)
		return;
	while (tab[i] != NULL)
		ft_printf("%s\n", tab[i++]);
}
