/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 22:42:35 by mallard           #+#    #+#             */
/*   Updated: 2017/07/10 02:04:05 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdlib.h>

char		**ft_newtab(int size)
{
	char	**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * (size + 1))))
		exit(1);
	tab[size] = NULL;
	return (tab);
}
