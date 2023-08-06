/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_here_doc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:10:01 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/28 16:25:45 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_fork_here_doc(t_data *data, char **envp)
{
	ft_make_pipe_here_doc(data);
	data->pid = fork();
	if (data->pid == 0)
	{
		ft_dup_here_doc(data);
		ft_close(data);
		ft_check_arg(data);
		ft_execve(data, envp);
		ft_no_execve(data);
	}
	else
		data->index_cmd++;
	waitpid(data->pid, NULL, 0);
}

void	ft_make_here_doc_next(t_data *data, char **envp, char **argv)
{
	char	*line;
	char	*expected;

	line = get_next_line(0);
	expected = ft_strjoin(argv[2], "\n");
	while (ft_strcmp(expected, line) != 0)
	{
		ft_putstr_fd(line, data->input_file);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	free(expected);
	close(data->input_file);
	data->input_file = open(argv[1], O_RDONLY, 0644);
	while (data->index_cmd <= data->nb_cmd - 1)
		ft_fork_here_doc(data, envp);
	ft_close(data);
	close(data->input_file);
	ft_free(data);
}

void	ft_make_here_doc(t_data *data, char **envp, char **argv)
{
	int		i;
	int		j;

	j = 0;
	i = 3;
	data->cmd = ft_calloc(sizeof(char **), data->nb_cmd + 1);
	while (i < data->nb_cmd + 3)
	{
		data->cmd[j] = ft_split(argv[i], ' ');
		i++;
		j++;
	}
	make_first_pipe(data);
	ft_make_here_doc_next(data, envp, argv);
}
