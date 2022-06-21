/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   la_norm_stp_stop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:43:11 by mgolinva          #+#    #+#             */
/*   Updated: 2022/03/10 10:21:39 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Bonus/pipex.h"

void	ft_close_pipes(int *fd, int cmd_nb)
{
	int	i;

	i = 0;
	while (i < cmd_nb * 2)
	{
		close(fd[i]);
		i ++;
	}
}

void	jpp_la(char **cmd_list, t_fd *holder)
{
	int	i;

	i = 0;
	if (cmd_list[holder->i][i] == 0)
	{
		ft_putstr_fd("permission denied:\n", 2);
		return ;
	}
	while (cmd_list[holder->i][i])
	{
		if (cmd_list[holder->i][i] == '/')
		{
			ft_putstr_fd(cmd_list[holder->i], 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			return ;
		}
		i ++;
	}
	ft_putstr_fd("command not found : ", 2);
	ft_putstr_fd(cmd_list[holder->i], 2);
	ft_putstr_fd("\n", 2);
}

void	ft_norm_stp_arrete(char **tmp, char *path, t_cmd **cmd)
{
	path = ft_substr(tmp[0], 0, ft_strlen(tmp[0]) + 1);
	ft_add_back(cmd, ft_lstnew(path));
}

int	ft_vrmt_la_norm_jte_seup_dessus(char **env)
{
	int	len;

	len = 0;
	while (env[len])
		len ++;
	return (len);
}

void	ft_nik_la_norme(char **env, char **tmp, char *path, t_cmd **cmd)
{
	int	i;
	int	len;

	len = ft_vrmt_la_norm_jte_seup_dessus(env);
	i = -1;
	while (env[++i])
	{
		if (access(tmp[0], F_OK) == 0)
		{
			ft_norm_stp_arrete(tmp, path, cmd);
			break ;
		}
		path = ft_concatanate(env[i], tmp[0]);
		if (access(path, F_OK) == 0)
		{
			ft_add_back(cmd, ft_lstnew(path));
			break ;
		}
		if (i == len - 1)
		{
			ft_add_back(cmd, ft_lstnew(path));
			break ;
		}
		free(path);
	}
}
