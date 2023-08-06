/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:49:51 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/28 17:17:05 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_data {
	int		input_file;
	int		output_file;
	int		nb_cmd;
	int		pipe[2];
	char	*good_path;
	char	**path;
	char	***cmd;
	pid_t	pid;
}				t_data;

void	ft_free(t_data *data);
void	ft_fork(t_data *data, char **envp);
void	ft_save_data(int argc, char **argv, char **envp, t_data *data);
void	ft_dupe(t_data *data, char **envp);
void	ft_no_execve(t_data *data);
void	ft_parents(t_data *data);
void	ft_close(int first, int second);

int		ft_check_empty(char *str);

#endif
