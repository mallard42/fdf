/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 14:09:21 by mallard           #+#    #+#             */
/*   Updated: 2017/10/14 17:43:16 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

int		check_str(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' ||
			str[i] == '\t' || str[i] == '\n' || str[i] == '\0' || str[i] == '-')
			i++;
		else if ((tmp = ft_strchr(str, 'x')))
		{
			if (tmp[-1] && tmp[-1] == '0')
				i++;
			else
				return (1);
		}
		else
			return (1);
	}
	return (0);
}

int		check_line(char **tab)
{
	int		i;
	int		j;
	char	**tmp;

	i = -1;
	tmp = ft_strsplit(tab[0], ' ');
	j = ft_tablen(tmp);
	while (tab[++i])
	{
		ft_tabdel(tmp);
		tmp = ft_strsplit(tab[i], ' ');
		if (ft_tablen(tmp) != j)
			return (-1);
	}
	if (j < 0)
		return (-1);
	return (j);
}
