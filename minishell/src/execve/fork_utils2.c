/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:23:05 by pdubacqu          #+#    #+#             */
/*   Updated: 2023/01/16 14:50:41 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_pid(t_cmds *save, int status)
{
	t_cmds	*cmd;

	cmd = save;
	while (save)
	{
		waitpid(save->pid, &status, 0);
		save = save->next;
	}
	if (ft_is_builtins(cmd->cmd) < 0)
		if (g_exit_code[1] == 0)
			g_exit_code[0] = status >> 8;
}
