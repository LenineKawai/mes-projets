/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:47:59 by mgolinva          #+#    #+#             */
/*   Updated: 2022/03/09 16:48:33 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_init(char **av, int ac, t_fd *holder, t_cmd **cmd)
{
	(void)cmd;
	if (ac == 4 && holder->fd_in != -1)
		holder->fd_out = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	holder->i = 0;
	holder->cmd_nb = ac - 3;
	holder->fd = malloc((holder->cmd_nb * 2) * sizeof(int *));
	if (!holder->fd)
		exit (0);
	holder->av_dub = &av;
}

void	ft_pipe_maker(t_fd *holder)
{
	int	i;

	i = 0;
	while (i < (holder->cmd_nb * 2 - 1))
	{	
		if (pipe(&holder->fd[i]) == -1)
		{
			ft_close_pipes(holder->fd, holder->cmd_nb);
			ft_putstr_fd("fork: Resource temporarily unavailable\n", 2);
			exit (1);
		}
		i += 2;
	}
}

void	ft_make_cmd_frm_absolute(t_fd *holder)
{		
	int	i;
	int	j;

	j = 0;
	if (holder->cmd_split[0] == 0)
		return ;
	else
		i = ft_strlen(holder->cmd_split[0]);
	if (access(holder->cmd_split[0], F_OK) == 0)
	{
		while (i > 0 && holder->cmd_split[0][i] != '/')
			i --;
		i ++;
		while (holder->cmd_split[0][i])
		{
			holder->cmd_split[0][j] = holder->cmd_split[0][i];
			j ++;
			i ++;
		}
		holder->cmd_split[0][j] = 0;
	}
}

static int	ft_fork(t_fd *holder, t_cmd *cmd, char **cmd_list, char **envp)
{
	holder->cmd_split = ft_split(cmd_list[holder->i], ' ');
	ft_make_cmd_frm_absolute(holder);
	while (holder->i < holder->cmd_nb)
	{
		holder->pid = fork();
		if (holder->pid == -1)
		{
			perror("fork ");
			ft_close_pipes(holder->fd, holder->cmd_nb);
			ft_lstclear(&cmd);
			free(cmd_list);
			exit (1);
		}
		if (holder->pid == 0)
		{
			ft_pipex(holder, cmd, cmd_list, envp);
			exit (1);
		}
		holder->i ++;
		cmd = cmd->next;
	}
	ft_close_pipes(holder->fd, holder->cmd_nb);
	while (wait(&holder->stat2) != -1)
		;
	return (WEXITSTATUS(holder->stat2));
}

int	main(int ac, char **av, char **envp)
{
	static char		**cmd_list = NULL;
	static t_cmd	*cmd = NULL;
	t_fd			holder;

	if (ac < 4)
	{
		ft_putstr_fd("Please, at least 1 infile, 1 command and 1 outfile\n", 2);
		exit (1);
	}
	holder.env = ft_path_list_maker(envp);
	cmd_list = ft_command_list_maker(cmd_list, av, ac);
	holder.fd_in = open(av[1], O_RDONLY);
	if (holder.fd_in == -1)
		perror(av[1]);
	if (ac > 4)
		holder.fd_out = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	cmd = ft_create_path_list(cmd_list, holder.env, cmd);
	ft_init(av, ac, &holder, &cmd);
	if (holder.fd_out == -1 && access(av[ac - 1], W_OK) == -1)
		perror(av[ac -1]);
	ft_pipe_maker(&holder);
	holder.stat = ft_fork(&holder, cmd, cmd_list, envp);
	ft_lstclear(&cmd);
	free(cmd_list);
	return (holder.stat);
}
