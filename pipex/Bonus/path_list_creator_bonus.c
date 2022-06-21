/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_list_creator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:32:16 by mgolinva          #+#    #+#             */
/*   Updated: 2022/03/10 10:19:23 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_concatanate(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = malloc ((ft_strlen(str1) + ft_strlen(str2) + 2) * sizeof(char));
	if (!new_str)
		exit(1);
	while (str1[i] && str1[i] != 0)
	{
		new_str[i] = str1[i];
		i ++;
	}
	new_str[i] = '/';
	i ++;
	while (str2[j] && str2[j] != 0)
	{
		new_str[i] = str2[j];
		i ++;
		j ++;
	}
	new_str[i] = 0;
	return (new_str);
}

static void	on_the_norm_again(t_cmd **cmd, char *path, char **tmp)
{
	path = ft_substr(tmp[0], 0, ft_strlen(tmp[0]) + 1);
	ft_free_array(tmp);
	*cmd = ft_lstnew(path);
	return ;
}

static void	ft_new(char **cmd_list, char **env, t_cmd **cmd, char *path)
{
	int		i;
	char	**tmp;

	i = -1;
	if (cmd_list[0][0] == 0)
	{
		*cmd = ft_lstnew(ft_substr("/trash", 0, 6));
		return ;
	}
	tmp = ft_split(cmd_list[0], ' ');
	while (env[++i])
	{
		free(path);
		if (access(tmp[0], F_OK) == 0)
			on_the_norm_again(cmd, path, tmp);
		path = ft_concatanate(env[i], tmp[0]);
		if (access(path, F_OK) == 0)
		{
			*cmd = ft_lstnew(path);
			ft_free_array(tmp);
			return ;
		}
	}
	ft_free_array(tmp);
	*cmd = ft_lstnew(path);
}

static void	ft_next_cmd(char **cmd_list, char **env, t_cmd **cmd)
{
	int		j;
	char	**tmp;
	char	*path;

	j = 1;
	path = NULL;
	while (cmd_list[j])
	{
		while (cmd_list[j] && cmd_list[j][0] == 0)
		{
			ft_add_back(cmd, ft_lstnew(ft_substr("/trash", 0, 6)));
			j ++;
		}
		if (cmd_list[j] == 0)
			return ;
		tmp = ft_split(cmd_list[j], ' ');
		ft_nik_la_norme(env, tmp, path, cmd);
		j ++;
		ft_free_array(tmp);
	}
}

t_cmd	*ft_create_path_list(char **cmd_list, char **env, t_cmd *cmd)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	j = 1;
	path = NULL;
	ft_new(cmd_list, env, &cmd, path);
	ft_next_cmd(cmd_list, env, &cmd);
	return (cmd);
}
