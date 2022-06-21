/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:00:19 by mgolinva          #+#    #+#             */
/*   Updated: 2022/02/10 14:21:58 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			j ++;
		}
		i ++;
	}
	return (0);
}

void	ft_check_arg(int ac, char **av)
{
	if (ac != 2)
	{
		printf("A map file ending in '.ber' is needed to properly"
			"run this program.\n");
		exit (0);
	}
	if (ft_strstr(av[1], ".ber") == 0)
	{
		printf("This map ain't a .ber.\n");
		exit (0);
	}
}

char	**ft_map_maker(char **av)
{
	char	**map;
	char	*map_line;
	int		lines;
	int		fd;
	int		i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	lines = 0;
	lines = line_ct(av);
	map = malloc((lines + 1) * sizeof(char **));
	if (!map || lines == 0)
		exit (0);
	while (i < lines)
	{
		map_line = get_next_line(fd);
		map[i] = map_line;
		i ++;
	}
	map[i] = 0;
	return (map);
}

int	ft_map_size(char *map_line)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		i ++;
	}
	return (i);
}
