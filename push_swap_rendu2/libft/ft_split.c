/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:25:00 by mgolinva          #+#    #+#             */
/*   Updated: 2022/01/18 11:34:33 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sprinkles_size(const char *str, char set);
static int	ft_sep_count(char const *str, char sep);
static char	**ft_actual_split(char **banana, const char *str, char sep, int ct);

static void	ft_free_split(char **banana, int i)
{
	while (i >= 0)
	{
		free(banana[i]);
		i --;
	}
	free(banana);
}

static int	ft_sprinkles_size(const char *str, char set)
{
	int	i;

	i = 0;
	while (str[i] != set && str[i])
	{
		i ++;
	}
	return (i);
}

static int	ft_sep_count(char const *str, char sep)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == sep && str[i])
			i ++;
		if (str[i] != sep && str[i] != '\0')
		{
			i ++;
			count ++;
		}
		while (str[i] != sep && str[i])
			i ++;
	}
	return (count);
}

static char	**ft_actual_split(char **banana, const char *str, char sep, int ct)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= ct - 1 && str[j])
	{
		while (str[j] == sep && str[j])
			j ++;
		if (str[j] != sep && str[j] != '\0')
		{
			banana[i] = ft_substr(str, j, ft_sprinkles_size(&str[j], sep));
			if (banana[i] == NULL)
			{
				ft_free_split(banana, i);
				return (malloc(0));
			}
			j ++;
		}
		while (str[j] != sep && str[j])
			j ++;
		i ++;
	}
	banana[i] = 0;
	return (banana);
}

char	**ft_split(char const *str, char sep)
{
	int		count;
	char	**banana;

	if (!str)
		return (0);
	count = ft_sep_count(str, sep);
	banana = malloc((count + 1) * sizeof(char **));
	if (!banana)
		return (0);
	return (ft_actual_split(banana, str, sep, count));
}
