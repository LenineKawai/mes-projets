/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:26:43 by mgolinva          #+#    #+#             */
/*   Updated: 2022/03/09 11:01:35 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close(int fd1, int fd2)
{
	if (close(fd1) < 0)
		return (perror("close : "));
	else if (close(fd2) < 0)
		return (perror("close : "));
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		exit (1);
	while (str[i])
	{
		i ++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
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

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;
	char			*ditto;

	if (!s)
		return (0);
	if (start > (unsigned int)ft_strlen(s))
		return (0);
	i = start;
	j = 0;
	size = ft_strlen(s) - start;
	if (size > len)
		size = len;
	ditto = malloc((size + 1) * sizeof(char));
	if (!ditto)
		return (0);
	while (j < size)
	{
		ditto[j] = s[i];
		i ++;
		j ++;
	}
	ditto[j] = '\0';
	return (ditto);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i ++;
	}
	free(array);
}
