/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:45:11 by mgolinva          #+#    #+#             */
/*   Updated: 2022/03/08 16:51:58 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_cmd
{
	char	*path;
	void	*next;
}			t_cmd;

typedef struct s_fd
{
	char	***av_dub;
	char	**env;
	char	**cmd_split;
	int		stat;
	int		stat2;
	int		i;
	int		fd_in;
	int		fd_out;
	int		*fd;
	pid_t	pid;
	int		cmd_nb;
}			t_fd;

void		ft_pipe_maker(t_fd *holder);
void		ft_close_pipes(int *fd, int cmd_nb);
void		ft_pipex(t_fd *holder, t_cmd *cmd, char **cmd_list, char **envp);
void		ft_close(int fd1, int fd2);
void		ft_free_array(char **array);
void		ft_lstclear(t_cmd **lst);
void		ft_add_back(t_cmd **alpha, t_cmd *newb);
t_cmd		*ft_lstnew(char *content);
t_cmd		*ft_create_path_list(char **cmd_list, char **env, t_cmd *cmd);
void		ft_putstr_fd(char *str, int fd);
void		ft_putchar_fd(char c, int fd);
void		*ft_calloc(size_t count, size_t size);
char		**ft_split(char *str, char sep);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strstr(char *str, char *to_find);
char		**ft_path_list_maker(char **envp);
char		**ft_command_list_maker(char **cmd_list, char **av, int ac);
int			ft_cmd_parser(char **cmd_list, char **env, int ac);
int			ft_strlen(const char *str);
char		*ft_concatanate(char *str1, char *str2);
void		ft_nik_la_norme(char **env, char **tmp, char *path, t_cmd **cmd);
int			ft_vrmt_la_norm_jte_seup_dessus(char **env);
void		ft_norm_stp_arrete(char **tmp, char *path, t_cmd **cmd);
void		jpp_la(char **cmd_list, t_fd *holder);
void		ft_make_cmd_frm_absolute(t_fd *holder);

#endif
