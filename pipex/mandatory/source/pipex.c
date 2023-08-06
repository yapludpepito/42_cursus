/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:49:23 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/27 10:17:07 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_close(int first, int second)
{
	if (first != -1)
		close(first);
	if (second != -1)
		close(second);
}

void	ft_save_data(int argc, char **argv, char **envp, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->input_file = open(argv[1], O_RDONLY);
	data->output_file
		= open(argv[argc - 1], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	while (ft_strncmp(envp[i], "PATH=", (long unsigned int)5) != 0)
		i++;
	data->good_path = ft_strtrim(envp[i], "PATH=");
	data->path = ft_split(data->good_path, ':');
	free(data->good_path);
	i = 2;
	data->cmd = malloc(sizeof(char **) * argc - 2);
	data->cmd[argc - 1 - i] = NULL;
	while (i < argc - 1)
	{
		data->cmd[j] = ft_split(argv[i], ' ');
		i++;
		j++;
	}
	data->nb_cmd = 0;
}

int	ft_check_empty(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] != ' ' || str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

void	ft_free(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->cmd[i] != NULL)
	{
		j = 0;
		while (data->cmd[i][j] != NULL)
		{
			free(data->cmd[i][j]);
			j++;
		}
		free(data->cmd[i]);
		i++;
	}
	free(data->cmd);
	i = 0;
	while (data->path[i] != NULL)
	{
		free(data->path[i]);
		i++;
	}
	free(data->path);
	free(data);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	if (argc < 5)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	data = malloc(sizeof(t_data) * 1);
	ft_save_data(argc, argv, envp, data);
	if (pipe(data->pipe) < 0)
	{
		ft_free(data);
		exit(0);
	}
	while (data->nb_cmd < argc - 3)
		ft_fork(data, envp);
	ft_free(data);
}
