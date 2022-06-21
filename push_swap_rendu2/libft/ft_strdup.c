/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:08:59 by mgolinva          #+#    #+#             */
/*   Updated: 2021/11/08 15:05:43 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		size;
	char	*dub;

	i = 0;
	size = ft_strlen(str);
	dub = malloc(size + 1 * sizeof(char));
	if (!dub)
		return (0);
	while (str[i])
	{
		dub[i] = str[i];
		i ++;
	}
	dub[i] = '\0';
	return (dub);
}
