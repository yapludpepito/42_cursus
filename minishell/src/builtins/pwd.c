/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:24:39 by pdubacqu          #+#    #+#             */
/*   Updated: 2023/01/13 11:24:40 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_pwd(char *opt)
{
	char	*pwd;

	if (*opt)
	{
		g_exit_code[0] = 2;
		ft_putstr_fd("minishell: pwd: ", 2);
		ft_putstr_fd(opt, 2);
		ft_putendl_fd(": invalid option", 2);
		return (2);
	}
	else
	{
		g_exit_code[0] = 0;
		pwd = NULL;
		pwd = getcwd(pwd, 0);
		ft_putendl_fd(pwd, 1);
		free(pwd);
	}
	return (0);
}
