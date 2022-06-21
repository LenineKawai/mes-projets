/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:08:41 by mgolinva          #+#    #+#             */
/*   Updated: 2022/03/10 10:21:55 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Bonus/pipex.h"

static void	ft_in(t_fd *holder, t_cmd *cmd, char **envp, char **cmd_list)
{
	if (holder->fd_in == -1)
		exit (1);
	if (dup2(holder->fd_in, 0) == -1)
	{
		ft_free_array(holder->cmd_split);
		ft_close_pipes(holder->fd, holder->cmd_nb);
		return (perror("dup2 "));
	}
	if (dup2(holder->fd[holder->i * 2 + 1], 1) == -1)
	{
		ft_free_array(holder->cmd_split);
		ft_close_pipes(holder->fd, holder->cmd_nb);
		return (perror("dup2 "));
	}
	ft_close_pipes(holder->fd, holder->cmd_nb);
	if (execve(cmd->path, holder->cmd_split, envp) < 0)
	{
		ft_free_array(holder->cmd_split);
		jpp_la(cmd_list, holder);
		exit (1);
	}
}

static void	ft_mid(t_fd *holder, t_cmd *cmd, char **envp, char **cmd_list)
{
	if (dup2(holder->fd[(holder->i - 1) * 2], 0) == -1)
	{	
		ft_free_array(holder->cmd_split);
		ft_close_pipes(holder->fd, holder->cmd_nb);
		return (perror("dup2 "));
	}
	if (dup2(holder->fd[holder->i * 2 + 1], 1) == -1)
	{
		ft_free_array(holder->cmd_split);
		ft_close_pipes(holder->fd, holder->cmd_nb);
		return (perror("dup2 "));
	}
	ft_close_pipes(holder->fd, holder->cmd_nb);
	if (execve(cmd->path, holder->cmd_split, envp) < 0)
	{
		ft_free_array(holder->cmd_split);
		jpp_la(cmd_list, holder);
		exit (1);
	}
}

static void	ft_out(t_fd *holder, t_cmd *cmd, char **envp, char **cmd_list)
{
	if (holder->fd_out == -1)
		exit (1);
	if (dup2(holder->fd_out, 1) == -1)
	{
		ft_free_array(holder->cmd_split);
		ft_close_pipes(holder->fd, holder->cmd_nb);
		return (perror("dup2 "));
	}
	if (dup2(holder->fd[(holder->i - 1) * 2], 0) == -1)
	{
		ft_free_array(holder->cmd_split);
		ft_close_pipes(holder->fd, holder->cmd_nb);
		return (perror("dup2 "));
	}
	ft_close_pipes(holder->fd, holder->cmd_nb);
	if (execve(cmd->path, holder->cmd_split, envp) < 0)
	{
		ft_free_array(holder->cmd_split);
		jpp_la(cmd_list, holder);
		exit (1);
	}
}

static void	ft_one(t_fd *holder, t_cmd *cmd, char **envp, char **cmd_list)
{
	if (holder->fd_out == -1 || holder->fd_in == -1)
		exit (1);
	if (dup2(holder->fd_out, 1) == -1)
	{
		ft_free_array(holder->cmd_split);
		ft_close_pipes(holder->fd, holder->cmd_nb);
		close(holder->fd_out);
		return (perror("dup2 "));
	}
	if (dup2(holder->fd_in, 0) == -1)
	{
		ft_free_array(holder->cmd_split);
		ft_close_pipes(holder->fd, holder->cmd_nb);
		close(holder->fd_in);
		return (perror("dup2 "));
	}
	ft_close(holder->fd_in, holder->fd_out);
	if (execve(cmd->path, holder->cmd_split, envp) < 0)
	{
		ft_free_array(holder->cmd_split);
		jpp_la(cmd_list, holder);
		exit (1);
	}
}

void	ft_pipex(t_fd *holder, t_cmd *cmd, char **cmd_list, char **envp)
{
	holder->cmd_split = ft_split(cmd_list[holder->i], ' ');
	ft_make_cmd_frm_absolute(holder);
	if (holder->cmd_nb == 1)
	{
		ft_one(holder, cmd, envp, cmd_list);
	}
	else if (holder->i == 0 && holder->cmd_nb > 1)
	{
		ft_in(holder, cmd, envp, cmd_list);
	}
	else if (holder->i > 0 && holder->i < holder->cmd_nb - 1)
	{
		ft_mid(holder, cmd, envp, cmd_list);
	}
	else if (holder->i == holder->cmd_nb - 1)
	{
		ft_out(holder, cmd, envp, cmd_list);
	}
}
