/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:24:36 by pdubacqu          #+#    #+#             */
/*   Updated: 2023/08/06 16:35:30 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	ft_free_node(t_envp **node)
{
	free((*node)->variable);
	free((*node)->value);
	free(*node);
}

static t_envp	*ft_remove_var(t_envp *cur, t_envp *save, char **argv, int *i)
{
	t_envp	*prev;

	while (cur)
	{
		if (!strcmp(cur->variable, argv[*i]))
		{
			if (cur == save)
				save = save->next;
			else
			{
				prev = save;
				while (prev->next != cur)
					prev = prev->next;
				prev->next = cur->next;
			}
			ft_free_node(&cur);
			cur = save;
			break ;
		}
		cur = cur->next;
	}
	return (save);
}

static void	error(char *msg, char *opt, int exit_c)
{
	g_exit_code[0] = exit_c;
	ft_putstr_fd("unset: ", 2);
	ft_putstr_fd(opt, 2);
	ft_putendl_fd(msg, 2);
}

t_envp	*ft_unset(char **argv, char *opt, t_cmds *cmd)
{
	int		i;
	t_envp	*cur;
	t_envp	*save;

	i = -1;
	save = cmd->lst_envp;
	if (*opt)
	{
		error(": invalid option", opt, 2);
		return (save);
	}
	else if (argv[++i])
	{
		cur = cmd->lst_envp;
		while (argv[i])
		{
			if (ft_str_index_chr(argv[i], '-') >= 0)
			{
				error(": not a valid identifier", argv[i], 1);
				return (save);
			}
			save = ft_remove_var(cur, save, argv, &i);
			i++;
		}
	}
	return (save);
}
