/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 13:20:55 by mallard           #+#    #+#             */
/*   Updated: 2017/10/14 17:41:43 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

char		*parse(char *str)
{
	int		fd;
	char	buff[128];
	char	*tmp;
	int		i;

	tmp = NULL;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ft_memset(buff, '\0', 127);
	while ((i = read(fd, buff, 127)))
	{
		if (i == -1 || check_str(buff) == 1)
			return (NULL);
		buff[i] = '\0';
		if (tmp == NULL)
			tmp = ft_strdup(buff);
		else
			tmp = ft_strjoin(tmp, buff);
		ft_memset(buff, '\0', 127);
	}
	return (tmp);
}
