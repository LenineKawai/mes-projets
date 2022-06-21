/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:17:33 by mgolinva          #+#    #+#             */
/*   Updated: 2022/03/10 10:21:31 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Bonus/pipex.h"

static int	ft_array_len(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i ++;
	return (i);
}

char	**ft_path_list_maker(char **envp)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	len = ft_array_len(envp);
	while (envp[++i])
		if (ft_strstr(envp[i], "PATH="))
			break ;
	if (i == len)
	{
		ft_putstr_fd("PATH env var is unset, no shell command will work.\n", 2);
		exit (1);
	}
	j = 0;
	while (envp[i][j])
	{
		if (envp[i][j] == '=')
		{
			j ++;
			break ;
		}
		j ++;
	}
	return (ft_split(&envp[i][j], ':'));
}

static char	**ft_actual_maker(char **av, int ac, char **cmd_list)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	while (av[i] && i < ac - 1)
	{
		cmd_list[j] = av[i];
		j ++;
		i ++;
	}
	cmd_list[j] = 0;
	return (cmd_list);
}

char	**ft_command_list_maker(char **cmd_list, char **av, int ac)
{
	cmd_list = malloc((ac - 2) * sizeof(char *));
	if (!cmd_list)
		exit (1);
	cmd_list = ft_actual_maker(av, ac, cmd_list);
	if (!cmd_list)
		exit (0);
	return (cmd_list);
}
