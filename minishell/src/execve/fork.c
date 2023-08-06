/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:24:06 by pdubacqu          #+#    #+#             */
/*   Updated: 2023/01/16 15:19:42 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	**ft_make_double(char *s, char *s2, char **files)
{
	char	**str;
	char	**s2_split;
	int		i;
	int		j;

	j = 0;
	i = 0;
	str = ft_calloc(sizeof(char *), 1024);
	str[0] = s;
	if (!*s2)
		str[1] = NULL;
	else
	{
		s2_split = ft_split(s2, ' ');
		while (s2_split[i])
		{
			str[i + 1] = s2_split[i];
			i++;
		}
	}
	str = ft_copy(files, &j, i, str);
	str[i + j + 2] = NULL;
	return (str);
}

void	ft_execve(t_cmds *cmd)
{
	char	*path;
	char	*tmp;

	tmp = ft_getenv("PATH", cmd->envp);
	path = ft_get_path(cmd, tmp);
	if (path == NULL)
	{
		if (!access(cmd->cmd, X_OK))
			execve(cmd->cmd, \
				ft_make_double(cmd->cmd, cmd->args, cmd->file_name), cmd->envp);
		free(path);
		ft_putstr_fd(cmd->cmd, 2);
		g_exit_code[0] = 127;
		ft_putendl_fd(": invalid command", 2);
		return ;
	}
	else if (!access(path, X_OK))
		execve(path,
			ft_make_double(cmd->cmd, cmd->args, cmd->file_name), cmd->envp);
	else if (!access(cmd->cmd, X_OK))
		execve(cmd->cmd, \
			ft_make_double(cmd->cmd, cmd->args, cmd->file_name), cmd->envp);
}

static void	ft_check_next(t_cmds *cmd, t_cmds *save, int fd)
{
	if (!ft_strncmp(cmd->cmd, "env", 3))
		ft_env(cmd->file_name, cmd->args, cmd, fd);
	if (!ft_strncmp(cmd->cmd, "unset", 5))
		save->lst_envp = ft_unset(cmd->file_name, cmd->args, cmd);
	if (!ft_strncmp(cmd->cmd, "pwd", 3))
		ft_pwd(cmd->args);
	if (cmd->redir_in == PIPE && cmd->pipe[0] != -1)
		close(cmd->pipe[0]);
}

void	ft_builtins(t_cmds *cmd, t_cmds *save, int i)
{
	int	fd;

	fd = ft_no_dup(cmd);
	if (!ft_strncmp(cmd->cmd, "export", 6))
		ft_export(cmd->file_name, cmd->args, cmd, fd);
	if (!ft_strncmp(cmd->cmd, "cd", 2))
		ft_cd(cmd->file_name[0], cmd->args, cmd);
	if (!ft_strcmp(cmd->cmd, "exit"))
	{
		if (cmd->next)
			close(cmd->next->pipe[0]);
		if (cmd->next)
			close(cmd->next->pipe[1]);
	}
	if (!ft_strncmp(cmd->cmd, "echo", 4))
	{
		ft_dup(cmd, i);
		ft_echo(cmd->file_name, cmd->args);
		if (cmd->redir_in == PIPE && cmd->pipe[0] != -1)
			close(cmd->pipe[0]);
	}
	ft_check_next(cmd, save, fd);
}

void	ft_fork_execution(t_cmds *cmd)
{
	int		i;
	int		status;
	t_cmds	*save;

	save = cmd;
	i = 0;
	status = 0;
	while (cmd)
	{
		ft_make_pipe(cmd);
		if (ft_is_builtins(cmd->cmd) < 0)
		{
			cmd->pid = fork();
			signal(SIGINT, sig_handler_parent);
			ft_challah(cmd, save, i);
		}
		else
			ft_builtins(cmd, save, i);
		cmd = cmd->next;
		i++;
	}
	ft_pid(save, status);
	signal(SIGINT, sig_handler);
}
