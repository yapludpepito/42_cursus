/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:24:57 by pdubacqu          #+#    #+#             */
/*   Updated: 2023/01/13 11:24:57 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	ft_echo_opt(char *opt)
{
	int	i;

	i = 1;
	if (opt[0] == '-')
	{
		while (opt[i])
		{
			if (opt[i] != 'n')
				return (0);
			i++;
		}
	}
	return (1);
}

static void	ft_pecho(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		ft_putstr_fd(argv[i], 1);
		if (argv[i + 1] != NULL)
			ft_putstr_fd(" ", 1);
		i++;
	}
}

int	ft_echo(char **argv, char *opt)
{
	g_exit_code[0] = 0;
	if (!*argv && !*opt)
		ft_putendl_fd("", 1);
	else if (*argv && !*opt)
	{
		ft_pecho(argv);
		ft_putendl_fd("", 1);
	}
	else if (!*argv && ft_echo_opt(opt))
		return (0);
	else if (!*argv && !ft_echo_opt(opt))
		ft_putendl_fd(opt, 1);
	else if (*argv && !ft_echo_opt(opt))
	{
		ft_putstr_fd(opt, 1);
		ft_putstr_fd(" ", 1);
		ft_pecho(argv);
		ft_putendl_fd("", 1);
	}
	else
	{
		ft_pecho(argv);
		return (0);
	}
	return (0);
}
