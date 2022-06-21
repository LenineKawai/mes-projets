/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:29:07 by mgolinva          #+#    #+#             */
/*   Updated: 2021/11/16 09:52:26 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i ++;
	}
	return (0);
}

static int	ft_set_count_up(char const *str, char const *set)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && ft_is_set(set, str[i]) == 1)
	{
		count ++;
		i ++;
	}
	return (count);
}

static int	ft_set_count_down(char const *str, char const *set)
{
	int	i;
	int	count;

	i = ft_strlen(str) - 1;
	count = 0;
	while (i > 0 && ft_is_set(set, str[i]) == 1)
	{
		i --;
		count ++;
	}
	if (i == 0)
		return (0);
	return (count);
}

static char	*ft_actl_trim(const char *str, const char *set, char *trim, int max)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && ft_is_set(set, str[i]) == 1)
		i ++;
	if (i == ft_strlen(str))
		return (trim);
	while (str[i] && i < ft_strlen(str) - max)
	{
		trim[j] = str[i];
		i ++;
		j ++;
	}
	trim[j] = 0;
	return (trim);
}

char	*ft_strtrim(char const *str, char const *set)
{
	int		i;
	int		max;
	int		count;
	char	*trim;

	if (!str || !set)
		return (malloc(1));
	if (str[0] == 0)
		return (ft_strdup(str));
	i = 0;
	max = ft_set_count_down(str, set);
	count = ft_set_count_up(str, set) + ft_set_count_down(str, set);
	trim = ft_calloc((ft_strlen(str) - count + 1), sizeof(char));
	if (!trim)
		return (malloc(1));
	return (ft_actl_trim(str, set, trim, max));
}
