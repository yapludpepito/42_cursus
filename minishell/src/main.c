/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:23:58 by pdubacqu          #+#    #+#             */
/*   Updated: 2023/01/16 15:11:55 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	g_exit_code[2] = {0, 0};

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		ft_putendl_fd("", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_exit_code[0] = 130;
		return ;
	}
}

static void	free_exit(char **env_cp, char *input)
{
	ft_free_split(env_cp);
	free(input);
	exit(g_exit_code[0]);
}

static void	null_input(char ***env_cp, char **input)
{
	if ((*input) == NULL)
	{
		ft_putendl_fd("exit", 1);
		g_exit_code[0] = 0;
		rl_clear_history();
		free_exit((*env_cp), (*input));
	}
}

static void	minishell(char ***env_cp, char **input, t_cmds **cmd)
{
	null_input(env_cp, input);
	if ((*input) && (*input)[0])
	{
		(*cmd) = parse_input((*input), (*env_cp));
		if (*cmd && !ft_strcmp((*cmd)->cmd, "exit") && !((*cmd)->next))
			ft_exit((*cmd)->file_name, (*cmd)->args, *cmd, *env_cp);
		if ((*cmd) != NULL && g_exit_code[1] == 0)
		{
			pipe((*cmd)->pipe);
			ft_free_split((*env_cp));
			ft_fork_execution((*cmd));
			if ((*cmd)->pipe[1] != -1)
				close((*cmd)->pipe[1]);
			(*env_cp) = rebuild_envp((*cmd)->lst_envp);
		}
		else if ((*cmd) != NULL && g_exit_code[1] == 1)
			if ((*cmd)->heredoc_in[0] != '\0')
				unlink((*cmd)->heredoc_in);
		g_exit_code[1] = 0;
		free_cmd((*cmd));
	}
}

int	main(int ac, char **av, char **envp)
{
	char	*input;
	t_cmds	*cmd;
	char	**env_cp;

	(void)**av;
	if (ac != 1)
		exit(1);
	cmd = NULL;
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	env_cp = ft_cpy_envp(envp);
	while (1)
	{
		input = readline("Minishell > ");
		add_history(input);
		minishell(&env_cp, &input, &cmd);
		signal(SIGQUIT, SIG_IGN);
		free(input);
	}
	return (g_exit_code[0]);
}
