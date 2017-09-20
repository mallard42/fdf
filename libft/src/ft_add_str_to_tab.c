/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_str_to_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 22:48:03 by mallard           #+#    #+#             */
/*   Updated: 2017/07/10 02:05:08 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdlib.h>

char		**ft_add_str_to_tab(char **tab, char *str, int free)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_newtab(ft_tablen(tab) + 1);
	while (tab[i] != NULL)
	{
		tmp[i] = ft_strdup(tab[i]);
		i++;
	}
	if (free == 1)
		ft_tabdel(tab);
	tmp[i] = ft_strdup(str);
	return (tmp);
}
