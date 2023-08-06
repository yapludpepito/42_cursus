/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:51:13 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/28 17:13:58 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	close(0);
	close(1);
	close(2);
	exit(1);
}

void	ft_execve(t_data *data, char **envp)
{
	int	result;
	int	i;

	i = -1;
	result = -1;
	while (result != 0 && data->path[++i] != NULL)
	{
		data->good_path = ft_strjoin(data->path[i], "/");
		free(data->path[i]);
		data->path[i] = ft_strjoin(data->good_path,
				data->cmd[data->index_cmd][0]);
		free(data->good_path);
		result = access(data->path[i], 0);
	}
	if (result == 0)
		execve(data->path[i], data->cmd[data->index_cmd], envp);
	if (access(data->cmd[data->index_cmd][0], 0) == 0)
		execve(data->cmd[data->index_cmd][0], data->cmd[data->index_cmd], envp);
}

void	ft_no_execve(t_data *data)
{
	ft_putchar_fd('\"', 2);
	ft_putstr_fd(data->cmd[data->index_cmd][0], 2);
	ft_putchar_fd('\"', 2);
	ft_error(" : command not found\n");
}

void	ft_check_arg(t_data *data)
{
	if ((data->input_file == -1) && (data->index_cmd == 0))
		ft_error("wrong path or file doesn't exist\n");
	else if (ft_check_empty(data->cmd[data->index_cmd][0]) == 1)
		ft_no_execve(data);
	else if (data->output_file == -1 && data->index_cmd == data->nb_cmd)
		ft_error("permission denied\n");
}

void	ft_fork(t_data *data, char **envp)
{
	ft_make_pipe(data);
	data->pid = fork();
	if (data->pid == 0)
	{
		ft_dup(data);
		ft_close(data);
		ft_check_arg(data);
		ft_execve(data, envp);
		ft_no_execve(data);
	}
	else
		data->index_cmd++;
	waitpid(data->pid, NULL, 0);
}
