/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_first_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:56:15 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/28 16:25:26 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	make_first_pipe(t_data *data)
{
	pipe(data->pipe);
	pipe(data->pipe2);
	close(data->pipe[0]);
	close(data->pipe[1]);
	close(data->pipe2[0]);
	close(data->pipe2[1]);
}
