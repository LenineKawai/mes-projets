/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:31:16 by mgolinva          #+#    #+#             */
/*   Updated: 2021/11/15 14:43:20 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;
	char			*ditto;

	if (!s)
		return (malloc(1));
	if (start > (unsigned int)ft_strlen(s))
		return (ft_calloc(1, 1));
	i = start;
	j = 0;
	size = ft_strlen(s) - start;
	if (size > len)
		size = len;
	ditto = malloc((size + 1) * sizeof(char));
	if (!ditto)
		return (malloc(1));
	while (j < size)
	{
		ditto[j] = s[i];
		i ++;
		j ++;
	}
	ditto[j] = '\0';
	return (ditto);
}
