/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_access_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:19:49 by mgolinva          #+#    #+#             */
/*   Updated: 2022/03/08 11:57:06 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_putnbr_fd(int nb, int fd)
{
	long int	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	if (nbr <= 9)
		ft_putchar_fd(nbr + 48, fd);
}

static int	ft_check_access(char **cmd, char **env, int cmd_nb)
{
	int		i;
	char	*path;

	i = 0;
	while (env[i])
	{
		path = ft_concatanate(env[i], cmd[0]);
		if (access(path, F_OK) == 0)
		{
			free(path);
			return (0);
		}
		free(path);
		i ++;
	}
	ft_putstr_fd("command number ", 2);
	ft_putnbr_fd(cmd_nb + 1, 2);
	ft_putstr_fd(" isn't accessible on this system or might not exist.\n", 2);
	return (1);
}

int	ft_cmd_parser(char **cmd_list, char **env, int ac)
{
	int		i;
	char	**cmd_split;

	i = 0;
	while (cmd_list[i] && i < ac - 3)
	{
		cmd_split = ft_split(cmd_list[i], ' ');
		if (ft_check_access(cmd_split, env, i) == 1)
		{
			ft_free_array(cmd_split);
			return (1);
		}
		ft_free_array(cmd_split);
		i ++;
	}
	return (0);
}
