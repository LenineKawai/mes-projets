/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:41:32 by mgolinva          #+#    #+#             */
/*   Updated: 2021/11/25 17:30:18 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		i ++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;
	char			*ditto;

	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		return (NULL);
	i = start;
	j = 0;
	size = ft_strlen(s) - start;
	if (size > len)
		size = len;
	ditto = malloc((size + 1) * sizeof(char));
	if (!ditto)
		return (NULL);
	while (j < size)
	{
		ditto[j] = s[i];
		i ++;
		j ++;
	}
	ditto[j] = '\0';
	return (ditto);
}

char	*ft_strchr(const char *str, int c)

{
	int		i;
	char	chr;

	if (!str)
		return (0);
	i = 0;
	chr = (char)c;
	while (str[i])
	{
		if (str[i] == chr)
		{
			return ((char *)&str[i]);
		}
		i ++;
	}
	if (chr == 0)
	{
		return ((char *)&str[i]);
	}
	return (0);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	int		i;
	int		j;
	char	*join;

	i = 0;
	j = 0;
	join = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (!join)
		free((void *)str1);
	if (!join)
		return (0);
	while (str1 && str1[i])
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
	free((void *)str1);
	join[i] = 0;
	return (join);
}
