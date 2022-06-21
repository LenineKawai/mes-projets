/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:04:35 by mgolinva          #+#    #+#             */
/*   Updated: 2021/11/15 16:29:57 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	int		i;
	int		j;
	char	*join;

	if (!str1 && str2)
		return (malloc(0));
	i = 0;
	j = 0;
	join = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (!join)
		return (0);
	while (str1[i])
	{
		join[i] = str1[i];
		i ++;
	}
	while (str2[j])
	{
		join[i] = str2[j];
		i ++;
		j ++;
	}
	join[i] = 0;
	return (join);
}
