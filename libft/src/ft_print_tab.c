/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 23:00:04 by mallard           #+#    #+#             */
/*   Updated: 2017/07/10 02:04:25 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void		ft_print_tab(char **tab)
{
	int		i;

	if (*tab)
	{
		i = 0;
		while (tab[i] != NULL)
		{
			ft_putstr(tab[i]);
			ft_putstr("\n");
			i++;
		}
	}
	else
		ft_putendl("NULL");
}
