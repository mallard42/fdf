/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 22:44:57 by mallard           #+#    #+#             */
/*   Updated: 2017/07/10 02:03:13 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdlib.h>

void	ft_tabdel(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_strdel(&(tab[i]));
		i++;
	}
	free(tab);
	tab = NULL;
}
