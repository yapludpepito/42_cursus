/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_q.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:35:14 by pdubacqu          #+#    #+#             */
/*   Updated: 2023/01/16 15:29:18 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	sig_handler_quit_child(int sig)
{
	if (sig == SIGQUIT)
		close(STDIN_FILENO);
}

void	sig_handler_quit(int sig)
{
	if (sig == SIGQUIT)
	{
		ft_putendl_fd("Quit (core dumped)", 2);
		g_exit_code[1] = 1;
		g_exit_code[0] = 131;
	}
}

void	ft_challah(t_cmds *cmd, t_cmds *save, int i)
{
	if (cmd->pid == 0)
	{
		signal(SIGQUIT, sig_handler_quit_child);
		ft_fork_exec(cmd, i, save);
	}
	else
	{
		signal(SIGQUIT, sig_handler_quit);
		ft_no_fork(cmd);
	}
}
