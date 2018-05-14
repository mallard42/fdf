/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:46:43 by mallard           #+#    #+#             */
/*   Updated: 2017/10/14 14:49:46 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			*char_to_int(char *str)
{
	int		*tmp;
	char	**tab;
	int		i;

	tab = ft_split(str);
	i = ft_tablen(tab);
	if (!(tmp = (int *)malloc(sizeof(int) * (i + 2))))
		return (0);
	tmp[i] = 0;
	i = 0;
	while (tab[i])
	{
		tmp[i] = ft_atoi(ft_strsub(tab[i], 0, 5));
		i++;
	}
	return (tmp);
}

int			**tab_to_int(char **tab, int col, int line)
{
	int		i;
	int		**map;
	int		j;

	if (!(map = (int **)malloc(sizeof(int *) * (ft_tablen(tab) + 1))))
		exit(1);
	i = 0;
	while (tab[i])
	{
		map[i] = char_to_int(tab[i]);
		i++;
	}
	grille(col - 1, line - 1, map, 0);
	return (map);
}

t_map		map_ini(int col, int line)
{
	t_map		tmp;

	tmp.mlx = mlx_init();
	tmp.win = mlx_new_window(tmp.mlx, WIN_X, WIN_Y, "pls");
	tmp.diff = 1;
	tmp.col = col;
	tmp.line = line;
	tmp.x_ini = 350;
	tmp.z_ini = 1;
	tmp.y_ini = 100;
	return (tmp);
}
