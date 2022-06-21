/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:32:57 by mgolinva          #+#    #+#             */
/*   Updated: 2021/11/30 11:25:11 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_scotch(char *temp)
{
	free(temp);
	return (0);
}

static char	*ft_save_next_line(char *line)
{
	int		i;
	int		size;
	char	*temp2;

	if (!line)
	{
		free(line);
		return (0);
	}
	i = 0;
	size = ft_strlen(line);
	while (line[i] != '\n' && line[i])
		i ++;
	temp2 = ft_substr(line, i + 1, size + 1);
	free(line);
	return (temp2);
}

static char	*ft_sep_until_eol(char *line)
{
	char	*temp;
	int		i;

	if (!line)
		return (0);
	i = 0;
	while (line[i] != '\n' && line[i])
		i ++;
	temp = ft_substr(line, 0, i + 1);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE + 1];
	int				check;
	static char		*line;
	char			*temp;

	check = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	while (ft_strchr(line, '\n') == NULL && check != 0)
	{
		check = read (fd, buff, BUFFER_SIZE);
		buff[check] = 0;
		if (check < 0)
			return (0);
		if (check > 0)
			line = ft_strjoin(line, buff);
	}
	temp = ft_sep_until_eol(line);
	line = ft_save_next_line(line);
	if (temp == NULL)
		return (ft_scotch(temp));
	if (temp[0] == '\0')
		return (ft_scotch(temp));
	return (temp);
}
