/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 12:02:32 by mallard           #+#    #+#             */
/*   Updated: 2017/10/14 16:00:01 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	check(char *str)
{
	char		**tab;
	int			ret;
	int			**map;

	tab = ft_strsplit(str, '\n');
	if ((ret = check_line(tab)) == -1)
		ft_putendl_fd("invalid map", 2);
	else
		map = tab_to_int(tab, ret, ft_tablen(tab));
}

int		main(int ac, char **av)
{
	char		*str;

	if (ac == 2)
	{
		str = parse(av[1]);
		if (str == NULL)
		{
			ft_putendl_fd("invalid map", 2);
			return (1);
		}
		check(str);
	}
	else if (ac == 1)
		ft_putendl_fd("insert map please", 2);
	else
		ft_putendl_fd("usage : ./fdf [map]", 2);
	return (0);
}
