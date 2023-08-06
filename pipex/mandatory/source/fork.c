/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:51:13 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/25 11:13:35 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_dupe(t_data *data, char **envp)
{
	int	result;
	int	i;

	i = -1;
	result = -1;
	if (data->nb_cmd != 0)
	{
		ft_close(data->input_file, data->pipe[1]);
		dup2(data->pipe[0], 0);
		dup2(data->output_file, 1);
		ft_close(data->output_file, data->pipe[0]);
	}
	while (result != 0 && data->path[++i] != NULL)
	{
		data->good_path = ft_strjoin(data->path[i], "/");
		free(data->path[i]);
		data->path[i] = ft_strjoin(data->good_path, data->cmd[data->nb_cmd][0]);
		free(data->good_path);
		result = access(data->path[i], 0);
	}
	if (result == 0)
		execve(data->path[i], data->cmd[data->nb_cmd], envp);
	else if (access(data->cmd[data->nb_cmd][0], 0) == 0)
		execve(data->cmd[data->nb_cmd][0], data->cmd[data->nb_cmd], envp);
}

void	ft_no_execve(t_data *data)
{
	ft_putstr_fd(data->cmd[data->nb_cmd][0], 2);
	ft_putendl_fd(" : command not found", 2);
	ft_free(data);
	exit(0);
}

void	ft_parents(t_data *data)
{
	if (data->nb_cmd == 0)
		ft_close(data->input_file, data->pipe[1]);
	else
		ft_close(data->output_file, data->pipe[0]);
	data->nb_cmd++;
}

void	ft_check_arg(t_data *data)
{
	if ((data->input_file == -1) && (data->nb_cmd == 0))
	{
		ft_putstr_fd("wrong path or file doesn't exist\n", 2);
		ft_free(data);
		exit(1);
	}
	if (ft_check_empty(data->cmd[data->nb_cmd][0]) == 1)
	{
		ft_close(data->output_file, data->pipe[0]);
		ft_close(data->input_file, data->pipe[1]);
		ft_putstr_fd("empty arg\n", 2);
		ft_free(data);
		exit(0);
	}
}

void	ft_fork(t_data *data, char **envp)
{
	data->pid = fork();
	if (data->pid == 0)
	{
		ft_check_arg(data);
		if (data->nb_cmd == 0)
		{
			ft_close(data->output_file, data->pipe[0]);
			dup2(data->input_file, 0);
			dup2(data->pipe[1], 1);
			ft_close(data->input_file, data->pipe[1]);
		}
		ft_dupe(data, envp);
		ft_no_execve(data);
	}
	else
		ft_parents(data);
	waitpid(data->pid, NULL, 0);
}
