/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:12:47 by mallard           #+#    #+#             */
/*   Updated: 2017/07/17 06:47:13 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen((char *)s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j > 0)
		j--;
	if (i == ft_strlen((char *)s))
		return (NULL);
	return (ft_strsub(s, i, j - i + 1));
}
