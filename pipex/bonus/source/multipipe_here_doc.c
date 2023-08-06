/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipe_here_doc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:30:14 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/28 13:05:42 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_dup_next_here_doc(t_data *data)
{
	if (data->index_cmd % 2 == 0)
	{
		dup2(data->pipe2[0], 0);
		dup2(data->pipe[1], 1);
	}
	else
	{
		dup2(data->pipe[0], 0);
		dup2(data->pipe2[1], 1);
	}
}

void	ft_dup_here_doc(t_data *data)
{
	if (data->index_cmd == 0)
	{
		dup2(data->input_file, 0);
		dup2(data->pipe[1], 1);
	}
	else if (data->index_cmd == data->nb_cmd - 1)
	{
		if (data->index_cmd % 2 == 0)
		{
			dup2(data->pipe2[0], 0);
			dup2(data->output_file, 1);
		}
		else
		{
			dup2(data->pipe[0], 0);
			dup2(data->output_file, 1);
		}
	}
	else
		ft_dup_next_here_doc(data);
}

void	ft_make_pipe_here_doc(t_data *data)
{
	if (data->index_cmd % 2 == 1)
	{
		close(data->pipe[1]);
		close(data->pipe2[0]);
		if (pipe(data->pipe2) < 0)
		{
			ft_free(data);
			exit(0);
		}
	}
	else
	{
		close(data->pipe[0]);
		close(data->pipe2[1]);
		if (pipe(data->pipe) < 0)
		{
			ft_free(data);
			exit(0);
		}
	}
}
